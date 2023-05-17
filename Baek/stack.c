#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct{
    int data[MAX_SIZE];
    int top
} StackType;

void stack_init(StackType* s){
    s -> top = -1;
}
int empty(StackType* s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}