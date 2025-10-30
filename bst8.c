/*

Given an integer array nums where the elements are sorted in ascending order, convert it to a binary search tree.
*/

#include <stdio.h>
#include <stdlib.h>


int arr1[] = {10,20,30};
typedef struct bstNode{
    int val;
    struct bstNode* right;
    struct bstNode* left;
} bstNode;

bstNode* createNode(int val){
    bstNode* node = malloc(sizeof(bstNode));
    node -> val = val;
    node->right = NULL;
    node->left = NULL;

    return node;
}

bstNode* insert(bstNode* root, int val){
    if (root == NULL){
        return createNode(val);
    }
    if (val < root->val){
        root->left = insert(root->left, val);
    } else if (val > root->val){
        root ->right = insert(root->right,val);
    }

    return root;
}

void inorder(bstNode* root){
    if (root==NULL){return;}
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

bstNode* makeBst(int arr[],int start, int end){
    if (start>end){
        return NULL;
    }
    int mid = (start+end)/2;
     
    bstNode* root = createNode(mid);

    root -> left = makeBst(arr,start,mid-1);
    root ->right = makeBst(arr,mid+1,end);

    return root;
    
}

bstNode* sorterArray(int* arr, int size){
    return makeBst(arr,0,size-1);
}

int main(){
    bstNode* root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 18);

    inorder(root);
    printf("\n");

    int length = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d ",length);
    //makeBst(arr1, length); //cannot calculate length inside directly cause then it will return the length of the pointer arr




    return 0;
}