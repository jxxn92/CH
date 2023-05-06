#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{

    int data;
    struct TreeNode *left,*right;
} TreeNode;

//       n1
//     /   |
//    n2   n3
//   / |  / |
//  n4   n5 n6  
//       |
//       n7

int main(void){

    TreeNode *n1,*n2,*n3,*n4,*n5,*n6,*n7;

    n1 = (TreeNode *)malloc(sizeof(TreeNode));
    n2 = (TreeNode *)malloc(sizeof(TreeNode));
    n3 = (TreeNode *)malloc(sizeof(TreeNode));
    n4 = (TreeNode *)malloc(sizeof(TreeNode));
    n5 = (TreeNode *)malloc(sizeof(TreeNode));
    n6 = (TreeNode *)malloc(sizeof(TreeNode));
    n7 = (TreeNode *)malloc(sizeof(TreeNode));

    n1 -> data = 10;
    n1 -> left = n2;
    n1 -> right = n3;

    n2 -> data = 20;
    n2 -> left = n4;
    n2 -> right = NULL;

    n3 -> data = 30;
    n3 -> left = n5;
    n3 -> right = n6;

    n4 -> data = 40;
    n4 -> left = NULL;
    n4 -> right = NULL;

    n5 -> data = 50;
    n5 -> left = n7;
    n5 -> right = NULL;

    n6 -> data = 60;
    n6 -> left = NULL;
    n6 -> right = NULL;

    n7 -> data = 70;
    n7 -> left = NULL;
    n7 -> right = NULL;


    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(n7);

    return 0;

    // 컴퓨터공학과 20203193 박준걸
}