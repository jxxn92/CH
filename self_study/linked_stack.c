#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;

typedef struct StackNode{
    element data;
    struct StackNode *link;
} StackNode;

typedef struct{
    StackNode* top;
} LinkedStackType;

void init(LinkedStackType* l){
    l -> top = NULL;
}

int is_empty(LinkedStackType* l){
    return (l -> top == NULL);
}

int is_full(LinkedStackType* l){
    return 0;
}

void push(LinkedStackType* l , element item){
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    temp->data = item;
    temp->link = l -> top;
    l -> top = temp;
}

void print_stack(LinkedStackType* l){
    for(StackNode* p = l -> top; p != NULL; p = p->link ){
        printf("%d->",p->data);
    }
    printf("NULL \n");
}

element pop(LinkedStackType* l){
    if(is_empty(l)){
        fprintf(stderr,"error\n");
        exit(1);
    }
    else{
        StackNode* removed = l -> top;
        int data = removed -> data;
        l -> top = l -> top -> link;
        free(removed);
        return data;
    }
}

element peek(LinkedStackType* l){
    if(is_empty(l)){
        fprintf(stderr,"error \n");
        exit(1);
    }
    else{
        return l -> top -> data;
    }
}

int main(void){

    LinkedStackType l;

    init(&l);
    push(&l,1); print_stack(&l);
    push(&l,2); print_stack(&l);
    push(&l,3); print_stack(&l);

    pop(&l); print_stack(&l);
    pop(&l); print_stack(&l);
    pop(&l); print_stack(&l);

    return 0;
}