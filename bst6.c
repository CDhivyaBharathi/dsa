/*
Given the roots of two binary trees root and subRoot, 
return true if there is a subtree of root with the same structure and node values of subRoot and 
false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants.
The tree tree could also be considered as a subtree of itself.


sol:
do a search and return the node and then check children

*/

#include <stdlib.h>
#include <stdio.h>


typedef struct node{
    int val;
    struct node* right;
    struct node* left;
} node;

node* createNode(int val){
    node* root = malloc(sizeof(node));
    root->val = val;
    root->right = NULL;
    root->left = NULL;
    return root;
}

node* insert(node* root,int key){
    if(root == NULL){
        root = createNode(key);
        return root;
    }
    if (key < root->val){
        root->left = insert(root->left,key);
    } else if (key > root->val){
        root -> right = insert(root->right,key);
    }

    return root;
}

void inorder(node* root){
    if (root == NULL){return ;}
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

// node* search(node*root,int val){
//     if (root == NULL){
//         return NULL;
//     }
//     if (root->val == val){
//         return root;
//     } else if (val < root->val ){
//         return search(root->left,val);
//     } else if (val > root->val ){
//         return search(root->right,val);
//     }

//     return root;
// }

int same(node* t1, node* t2){
    if ( t1 == NULL && t2 == NULL){
        return 1;
    } else if ( t1 == NULL || t2 == NULL){
        return 0;
    } else if (t1->val != t2->val){
        return 0;
    }
    return same(t1->left,t2->left) && same(t1->right,t2->right);
}

int isSub(node* root, node* subroot){
    
    
    if (root == NULL){
        return 0;
    } else if (same(root,subroot)) return 1;
    return isSub(root->left,subroot) || isSub(root->right,subroot);
}

int main(){
    node *root = NULL;
    root = insert(root,20);
    root = insert(root,10);
    root = insert(root,40);
    root = insert(root,45);
    printf("Root rn: %d \n",root->val);


    node *subTree = NULL;
    subTree = insert(subTree,210);
    subTree = insert(subTree,45);
    printf("Root rn: %d \n",subTree->val);

    inorder(root);
    printf("\n");
    inorder(subTree);
    printf("\n");


    printf("%d ", isSub(root,subTree));

    return 0;
}