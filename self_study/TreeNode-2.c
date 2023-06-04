#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left,*right;
} TreeNode;

TreeNode n1 = {1,NULL,NULL};
TreeNode n2 = {4,&n1,NULL};
TreeNode n3 = {16,NULL,NULL};
TreeNode n4 = {25,NULL,NULL};
TreeNode n5 = {20,&n3,&n4};
TreeNode n6 = {15,&n2,&n5};
TreeNode *root = &n6;

//������ȸ(VLR)
TreeNode preorder(TreeNode* root){
    if(root != NULL){
        printf("[%d] ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//������ȸ(LVR)
TreeNode inorder(TreeNode* root){
    if(root != NULL){
        inorder(root->left);
        printf("[%d] ",root->data);
        inorder(root->right);
    }
}

//������ȸ(LRV)
TreeNode postorder(TreeNode* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("[%d] ",root->data);
    }
}

int main(void){

    printf("������ȸ = ");
    preorder(root);
    printf("\n");

    printf("������ȸ = ");
    inorder(root);
    printf("\n");
    
    printf("������ȸ = ");
    postorder(root);
    printf("\n");

    return 0;

}