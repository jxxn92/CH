#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element;

typedef struct{
    element data[MAX_SIZE];
    int top;
} StackType;

void init_stack(StackType *q){
    q-> top = -1;
}

int is_empty(StackType *q){
    return (q -> top == -1);
}

int is_full(StackType *q){
    return (q->top == MAX_SIZE-1);
}

void push(StackType *q, element item){
    if(is_full(q)){
        exit(1);
    }
    else{
        q->data[++(q->top)] = item;
    }
}
element pop(StackType *q){
    int tmp;
    if(is_empty(q)){
        exit(1);
    }
    else{
        tmp = q->data[(q->top)--];
    }
    return tmp;
}

int peek(StackType *q){
    int tmp;
    if(is_empty(q)){
        exit(1);
    }
    else{
        tmp = q->data[q->top];
    }
    return tmp;
}

int main(void){

    StackType q;

    init_stack(&q);
    push(&q,1);
    printf("%d\n",peek(&q));
    printf("%d\n",pop(&q));
    push(&q,2);
    printf("%d\n",peek(&q));
    printf("%d\n",pop(&q));
    push(&q,3);
    printf("%d\n",peek(&q));
    printf("%d\n",pop(&q));

    return 0;
    
}