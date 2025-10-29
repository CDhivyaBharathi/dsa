// Given the root of a binary tree, invert the tree, and return its root.

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* left;
    struct node* right;
} node;

node* createNode(int val){
    node* root = malloc(sizeof(node));
    root->val = val;
    root->right = NULL;
    root->left = NULL;
    return root;
}

node* insert(node* root, int key){
    if (root == NULL){
        root = createNode(key);
        return root;
    }

    if (key < root->val){
        root->left = insert(root->left,key);
    } else if ( key > root->val){
        root -> right = insert(root->right,key);
    }

    return root;
}

void inOrder(node* root){
    if(root==NULL){return;}
    inOrder(root->left);
    printf("%d ",root->val);
    inOrder(root->right);
}


node* invTree(node* root){
    if (root == NULL){
        return NULL;
    }
    node* right_inv = invTree(root->right);
    node* left_inv = invTree(root->left);


    root->left = right_inv;
    root->right = left_inv;

    /*
    root->left = invTree(root->right);
    root->right = invTree(root->left);


    why is this wrong ??? 
    in the first line you are re-writting root->left and in the next line it points to the same number
    
    */

    return root;
}

int main(){
    node *root = NULL;
    root = insert(root,20);
    root = insert(root,10);
    root = insert(root,40);
    root = insert(root,45);
    root = insert(root,30);

    inOrder(root);
    printf("\n");

    invTree(root);
    inOrder(root);
    printf("\n");


    return 0;
}