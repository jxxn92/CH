#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;

typedef struct QueueNode{
    element data;
    struct QueueNode* link;
} QueueNode;

typedef struct{
    QueueNode *front,*rear;
} LinkedQueueType;

void init(LinkedQueueType* l){
    l -> front = 0;
    l -> rear = 0;
}

int is_empty(LinkedQueueType* l){
    return (l -> front == NULL);
}

int is_full(LinkedQueueType* l){
    return 0;
}

void enqueue(LinkedQueueType* l,element item){
    QueueNode* temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp -> data = item;
    temp -> link = NULL;

    if(is_empty(l)){
        l -> front = temp;
        l -> rear = temp;
    }
    else{
        l->rear->link = temp;
        l -> rear = temp;
    }
}

element dequeue(LinkedQueueType* l){
    QueueNode* removed = l -> front;
    if(is_empty(l)){
        fprintf(stderr,"error");
        exit(1);
    }
    else{
        int data = removed -> data;
        l -> front = l -> front -> link;
        if(l->front == NULL){
            l -> rear = NULL;
        } 
        free(removed);
        return data;
    }
}

void print_queue(LinkedQueueType* l){
    QueueNode* p;
    for(p = l->front; p != NULL; p = p->link){
        printf("%d->",p->data);
    }
    printf("NULL \n");
}

int main(void){

    LinkedQueueType l;

    init(&l);

    enqueue(&l,1); print_queue(&l);
    enqueue(&l,2); print_queue(&l);
    enqueue(&l,3); print_queue(&l);

    dequeue(&l); print_queue(&l);
    dequeue(&l); print_queue(&l);
    dequeue(&l); print_queue(&l);

    return 0;
}