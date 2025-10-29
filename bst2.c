#include <stdio.h>
#include <stdlib.h>

int arr[] = {2, 4, 8, 12, 16, 18};


typedef struct bstNode{
    int val;
    struct bstNode *left;
    struct bstNode *right;
} bstNode;

bstNode* createNode(int val){
    bstNode* node = malloc(sizeof(bstNode));
   
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

bstNode* sortedArray(int arr[], int start,int end){
    if (start > end)//base case - no elements
        return NULL;
    int mid = (start+end)/2;
    bstNode* root = createNode(arr[mid]); //middle element becomes the root, here 8

    root->left = sortedArray(arr,start,mid-1); // recursively making the first half as the left sub tree
    root->right = sortedArray(arr,mid+1,end);  // recursively making the second half as the right sub tree

    return root;
}

void inorderTrav(bstNode *root){
    if (root == NULL){return;}
    inorderTrav(root->left);
    printf("%d ",root->val);
    inorderTrav(root->right);
   
}

int main(){ 
    bstNode *root =  sortedArray(arr,0,5);
    inorderTrav(root);
    printf("Root rn: %d \n",root->val);

    return 0;
}