#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int *data;
    int capacity; //현재 크기
    int top;
}StackType;

void init_stack(StackType *s)
{
    s->top = -1;
    s->capacity = 1;
    s->data = (int *)malloc(s->capacity * sizeof(int));

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
    if(s->top == (s->capacity-1)){
        return 1;
    }
    else{
        return 0;
    }
}
void push(StackType *s,int item){
    if(is_full(s)){
        s->capacity *= 5;
        s->data = (int *)realloc(s->data,s->capacity * sizeof(int));
    }
    else{
        s->data[++(s->top)] = item;
    }
}
int pop(StackType *s){
    if(is_empty(s)){
        exit(1);
    }
    else{
        return s->data[(s->top)--];
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
    
    free(s.data);
    
    return 0;

}
