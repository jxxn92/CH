#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left,*right;
} TreeNode;

#define MAX_SIZE 100
int top = -1;
TreeNode *stack[MAX_SIZE];

void push(TreeNode* p){
    if(top < MAX_SIZE-1)
        stack[++top] = p;
}

TreeNode* pop(){

    TreeNode *p = NULL;

    if(top >= 0){
        p = stack[top--];
    }
    return p;
}

void inorder_iter(TreeNode* root){
    while(1){
        while(root != NULL){
            push(root);
            root = root -> left;
        }
        root = pop();
        if(!root) break;
        printf("[%d] ",root->data);
        root = root -> right;
    }
}

TreeNode n1 = {1,NULL,NULL};
TreeNode n2 = {4,&n1,NULL};
TreeNode n3 = {16,NULL,NULL};
TreeNode n4 = {25,NULL,NULL};
TreeNode n5 = {20,&n3,&n4};
TreeNode n6 = {15,&n2,&n5};
TreeNode *root = &n6;

int main(void){

    printf("���� ��ȸ: ");
    inorder_iter(root);
    printf("\n");
    
    return 0;
}