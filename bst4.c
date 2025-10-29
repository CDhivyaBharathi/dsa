/* 
Question:
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.




sol
since its the longest path between two leaf nodes passing through or not through the root, this would involve recursively finding
the left sub tree height and the right subtree height and the path at the root and finding the max */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct bstNode{
    int val;
    struct bstNode* left;
    struct bstNode* right;
} bstNode;

bstNode* createNode(int val){
    bstNode* node = malloc(sizeof(bstNode));
    node -> val = val;
    node ->left = NULL;
    node -> right = NULL;
    return node;
}

bstNode* insert(bstNode* root,int val){
    if (root == NULL){
        root = createNode(val);
    }
    if (val > root->val){
        root->right = insert(root->right,val);
    } else if (val < root -> val){
        root ->left = insert(root->left,val);
    }
    return root;
}


int height(bstNode *root){
    if (root == NULL){
        return 0;
    }
    /* point of confusion: seems to be counting the nodes but since you are doing height of the child, if there
     is one child, then it returns one which means there should be one edge connecting the parent to this child. */


    int l_height = height(root->left);
    int r_height = height(root->right);

    return 1 + fmax(l_height,r_height);
}

//longest path between two leaf nodes
int diameter(bstNode *root){
    if (root== NULL){
        return 0; //base case
    }
    //then find the left and right heights of this root
    int l_he = height(root->left);
    int r_he = height(root->right);

    printf("root: %d  left:%d  right: %d\n",root->val,l_he,r_he);

    int ls_dia = diameter(root->left);
    int rs_dia = diameter(root->right);

    return fmax(l_he+r_he,fmax(ls_dia,rs_dia));
}

void inorder(bstNode *root){
    if(root==NULL){
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

    int dia = diameter(root);
    printf("diameter: %d",dia);
    return 0;

}