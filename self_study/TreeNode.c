#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode n1 = {05, NULL, NULL};
TreeNode n2 = {15, &n1, NULL};
TreeNode n3 = {22, NULL, NULL};
TreeNode n4 = {35, &n3, NULL};
TreeNode n5 = {95, NULL, NULL};
TreeNode n6 = {93, &n4, &n5};
TreeNode n7 = {17, &n2, &n6};
TreeNode *root = &n7;

void inorder(TreeNode* root){
    if(root != NULL){
        inorder(root->left);
        printf("[%d] ", root->data);
        inorder(root->right);
    }
}

void preorder(TreeNode* root){
    if(root != NULL){
        printf("[%d] ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("[%d] ",root->data);
    }
}

int main(void){
    printf("중위 순회 = ");
    inorder(root);
    printf("\n");

    printf("전위 순회 = ");
    preorder(root);
    printf("\n");
    
    printf("후위 순회 = ");
    postorder(root);
    printf("\n");

    return 0;
}