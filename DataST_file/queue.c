#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef int element;
typedef struct{
    int front;
    int rear;
    element data[MAX_SIZE];
} QueueType;

void error(char *message){
    fprintf(stderr,"%s n",message);
    exit(1);
}

void init_queue(QueueType *q){
    q -> front = -1;
    q -> rear = -1;
}

void print_queue(QueueType *q){
    for(int i = 0 ; i < MAX_SIZE ; i++){
        if(i <= q->front || i > q -> rear){ // i�� fornt ���� �۰ų� i �� rear���� ū��쿡�� �� ��� x (Ʋ����) �̷� ��쿡�� �׳� Ʋ���ϱ� �������� ���
            printf("  | ");
        }
        else{
            printf("%d | ",q->data[i]);
        }
    }
    printf("\n");
}
int is_full(QueueType *q){
    if (q -> rear == MAX_SIZE -1){
        return 1;
    }
    else{
        return 0;
    }
}
int is_empty(QueueType *q){
    if(q->front == q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(QueueType *q,int item){
    if(is_full(q)){
        error("ť�� ��ȭ�����Դϴ�.");
        return;
    }
    q->data[++(q->rear)] = item; 
}

int dequeue(QueueType *q){ 
    if(is_empty(q)){
        error("ť�� ����ֽ��ϴ�.");
        return -1;
    }
    int s = q->data[++(q->front)];
    return s;
}

int main(void){

    int item = 0;
    QueueType q;

    init_queue(&q);

    enqueue(&q, 10);
    print_queue(&q);
    enqueue(&q, 20); 
    print_queue(&q);
    enqueue(&q, 30); 
    print_queue(&q);

    dequeue(&q); 
    print_queue(&q);
    dequeue(&q); 
    print_queue(&q);
    dequeue(&q); 
    print_queue(&q);

    return 0;
}