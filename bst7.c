/*
Given the root node of a binary search tree and two integers low and high, 
return the sum of values of all nodes with a value in the inclusive range [low, high].
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct bNode{
    int val;
    struct bNode* right;
    struct bNode* left;
} bNode;

bNode* createNode(int val){
    bNode* node = malloc(sizeof(bNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bNode* insert(bNode* root,int key){
    if(root == NULL){
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

void inorder(bNode* root){
    if(root == NULL){return;}
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

int rangeSum(bNode* root,int low,int high){

    int sum = 0;
    
    
    if (root == NULL){
        return 0;
    }
    //checking if the val is in the range
    if (root->val >= low && root->val <= high){
        sum += root ->val;
    }
    //if the val is greater than the low val, try the left sub tree
    if (root->val > low){
        sum += rangeSum(root->left,low,high);
    }
    //if the val is lower than the high val, try the right sub tree
    if (root->val < high){
        sum += rangeSum(root->right,low,high);
    }

    return sum;
}

int main(){
    bNode* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 18);

    inorder(root);
    printf("\n");

    printf("Sum in range [7, 15]: %d\n", rangeSum(root, 7, 15));


    return 0;
}