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

int main(){
    bstNode *root = NULL;

    root = insert(root,25);
    root = insert(root,35);
    root = insert(root,20);
    root = insert(root,10);


    inorderTrav(root);
    printf("\n");
    return 0;
}