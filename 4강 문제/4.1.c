#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1; // 스택이 비어있는걸 초기화 해주기 위해서

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
void push(int item){
    if(is_full()){
        exit(1);
    }
    else{
        top = top + 1;
        stack[top] = item;
    }
}
int pop(){
    if(is_empty()){
        exit(1);
        }
    else{
        int e;
        e = stack[top];
        top = top - 1;
        return e;
        }
}
int peek(){
    if(is_empty()){
        exit(1);
        }
    else{
        int e;
        e = stack[top];
    }
}

int main(void){

    push(1);
    push(2);
    push(3);
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());

    return 0;
}