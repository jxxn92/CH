#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_STRING 100

typedef struct{
    int student_no;
    char name[MAX_STRING];
    char address[MAX_STRING];
}element;

element stack[MAX_SIZE];
int top = -1;

int is_empty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int is_full(){
    if(top == (MAX_SIZE -1)){
        return 1;
    }
    else{
        return 0;
    }
}
void push(element item){
    if(is_full()){
        exit(1);
    }
    else{
        stack[++top] = item;
    }
}
element pop(){
    if(is_empty()){
        exit(1);
        }
    else{
        return stack[top--];
        }
}
element peek(){
    if(is_empty()){
        exit(1);
        }
    else{
        return stack[top];
    }
}

int main(void){

    element ie = {20203193,"박준걸","광주"};
    element oe;

    push(ie);
    oe = pop();

    printf("학번 : %d\n",oe.student_no);
    printf("이름 : %s\n",oe.name);
    printf("주소 : %s\n",oe.address);

    return 0;
}