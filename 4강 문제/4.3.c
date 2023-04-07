#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct{
    int data[MAX_SIZE];
    int top;
}StackType;

void init_stack(StackType *s)
{
    s->top = -1;
}
int is_empty(StackType *s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int is_full(StackType *s){
    if(s->top == (MAX_SIZE -1)){
        return 1;
    }
    else{
        return 0;
    }
}
void push(StackType *s,int item){
    if(is_full(s)){
        exit(1);
    }
    else{
        s -> data[++(s->top)] = item;

    }
}
int pop(StackType *s){
    if(is_empty(s)){
        exit(1);
    }
    else{
        return s -> data[(s -> top)--];
    }
}
int peek(StackType *s){
    if(is_empty(s)){
        exit(1);
        }
    else{
        return s->data[s->top];
    }
}

int main(void){

    StackType s;

    init_stack(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    printf("%d\n",pop(&s));
    printf("%d\n",pop(&s));
    printf("%d\n",pop(&s));

    return 0;
}
//컴퓨터공학과 20203193 박준걸