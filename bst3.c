#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct bstNode
{
    int val;
    struct bstNode *left;
    struct bstNode *right;
    
} bstNode;

bstNode* createNode(int val){
    bstNode *node = malloc(sizeof(bstNode));
    node->val = val;
    node -> left = NULL;
    node->right = NULL;
    return node;
}

bstNode* insert(bstNode *root, int key){
    if (root == NULL){
        root = createNode(key);
        return root;
    }
    if (key < root->val){
        root->left = insert(root->left,key);
    } else if (key > root->val){
        root->right = insert(root->right,key);
    }
    return root;
}


//function to return height of the given root
int height(bstNode *root){
    if (root == NULL){
        return 0; //empty tree
    }
    int heightr = height(root->right);
    int heightl = height(root->left);

    return 1 + fmax(heightl, heightr); //adding 1 to the max of height of either sub tree
}

//checking if its a valid avl
int isAVL(bstNode *root){
    if (root == NULL){
        return 1; //base case - true
    }
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    if (abs(lHeight-rHeight) > 1) // < 2 means it can be either 0 or 1
    {
        return 0; //false
    }

    return isAVL(root->left) && isAVL(root->right);

}

//inorder traversal
void inorder(bstNode* root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

int main(){
    bstNode *root = NULL;
    root = insert(root,20);
    root = insert(root,10);
    root = insert(root,40);
    root = insert(root,45);
    root = insert(root,30);

    inorder(root);

    printf("\n");

    if (isAVL(root)){
        printf("It is a valid avl tree");
    } else {
        printf("Not a valid avl tree");
    }

    
    return 0;
}