#include <stdio.h>  
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element;
typedef struct{
    element data[MAX_SIZE];
    int top;
} StackType;

void init_stack(StackType* s){
    s -> top = -1;
}

int is_empty(StackType* s){
    return (s-> top == -1);
}

int is_full(StackType* s){
    return ((s -> top) == (MAX_SIZE -1));
}

void push(StackType* s, element item){
    if(is_full(s)){
        fprintf(stderr,"error");
        exit(1);
    }
    s->data[++(s->top)] = item;
}

element pop(StackType* s){
    if(is_empty(s)){
        fprintf(stderr,"error");
        exit(1);
    }
    int item = s->data[(s->top)--];
    return item;
}

element peek(StackType* s){
    if(is_empty(s)){
        fprintf(stderr,"error");
        exit(1);
    }
    return s->data[s->top];
}

int main(void){

    StackType s;

    init_stack(&s);

    push(&s,1);     
    printf("%d \n",peek(&s));
    push(&s,2); 
    printf("%d \n",peek(&s));
    push(&s,3); 
    printf("%d \n",peek(&s));

    printf("%d \n",pop(&s));
    printf("%d \n",pop(&s));
    printf("%d \n",pop(&s)); 


    return 0;
}