#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode{
    int val;
    struct bstNode *right;
    struct bstNode *left;
} bstNode;

bstNode* createNode(int val){
    bstNode *node = malloc(sizeof(bstNode));
    node->val = val;
    node->right = NULL;
    node->left = NULL;
    return node;
}

bstNode* insert(bstNode *root,int key){
    if (root == NULL){
        root = createNode(key);
        return root;
    }
    if (key > root->val){
        root->right = insert(root->right,key);
    } else if (key < root->val){
        root->left = insert(root->left,key);
    } 
    return root;
}

void inorderTrav(bstNode *root){
    if (root == NULL){return;}
    inorderTrav(root->left);
    printf("%d ",root->val);
    inorderTrav(root->right);
   
}
//left most element
bstNode* findMin(bstNode *root){
    if (root == NULL){
        return NULL;
    }
    if (root->left != NULL){
        root = root->left;
    }
    return root;

}

bstNode* search(bstNode* root,int key){
    if (root == NULL){
        return NULL;
    }
    if(root->val == key){
        return root;
    }
    if (key < root->val){
        return search(root->left,key);
    } else if (key > root->val){
        return search(root->right,key);
    }
    return root;
}

bstNode* delete(bstNode *root,int key){
    if (root == NULL){
        return NULL;
    }

    if(key < root->val){
        root->left = delete(root->left,key);
    } else if (key > root->val){
        root->right = delete(root->right,key);
    }else {
        if (root->right == NULL && root -> left == NULL){
            free(root);
            return NULL;
        } else if (root->left == NULL){ //only right child
            bstNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL){ //only left child
            bstNode *temp = root->left;
            free(root);
            return temp;
        } else { //there are two children
            bstNode *succ = findMin(root->right); //finding min of the right subtree to short circuit the prev node of node
            root -> val = succ -> val;
            root -> right = delete(root->right, succ->val);
        }
    }
    return root;
}



int main(){
    bstNode *root = NULL;

    root = insert(root,10);
    printf("Root rn: %d \n",root->val);
    root = insert(root,5);
    printf("Root rn: %d \n",root->val);
    root = insert(root,20);
    printf("Root rn: %d \n",root->val);
    root = insert(root,25);

    printf("Root rn: %d \n",root->val);
    bstNode *node =  search(root,5);
    inorderTrav(node);
    printf("\n");

    inorderTrav(root);
    printf("\n");


    root = delete(root,20);

    inorderTrav(root);
    printf("\n");
    node =  search(root,20);
    inorderTrav(node);
    printf("\n");

    return 0;
}