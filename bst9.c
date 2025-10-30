#include <stdio.h>
#include <stdlib.h>
int lvl;
typedef struct bn{
    int val;
    struct bn* left;
    struct bn* right;
} bn;


bn* create(int val){
    bn* node = malloc(sizeof(bn));
    node->val = val;
    node->right = NULL;
    node->left = NULL;
    return node;
}

bn* insert(bn* root, int val){
    if (root == NULL){
        return create(val);
    }
    if (val < root->val){
        root->left = insert(root->left, val);
    } else if (val > root->val){
        root->right = insert(root->right,val);
    }
    return root;
}

void inorder(bn* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

int searchHelp(bn* root,int val,int level){
    
    if (root == NULL){
        return -1;
    }

    if (root->val == val){
        return level;
    } else if (val < root->val){
        return searchHelp(root->left,val,level+1);
    } else if (val > root->val){
        return searchHelp(root->right,val,level+1);
    }
    return level;
}

int search(bn* root,int val){
    return searchHelp(root,val,0);
}



bn* findMin(bn* root){
    if (root== NULL){
        return NULL;
    }
    if(root->left != NULL){
        root = root -> left;
    }
    return root;
}

bn* delete(bn* root, int val){
    if(root == NULL){
        return NULL;
    } 
    if (val < root->val){
        root->left =  delete(root->left,val);
    } else if (val > root->val){
        root->right =  delete(root->right,val);
    } else {
        if (root->right == NULL && root->left == NULL){
            free(root);
            return NULL;
        } else if (root->left == NULL){
            bn* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL){
            bn* temp = root->left;
            free(root);
            return temp;
        } else{
            bn* succ = findMin(root->right);
            root->val = succ ->val;
            root->right =  delete(root->right,succ->val);
        }
    }
    return root;
}

int main(){
    bn* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 18);

    inorder(root);
    printf("\n");

    int l = search(root,3); //starting level 1
    printf("%d ",l);

    root = delete(root,15);
    inorder(root);
    printf("\n");

}