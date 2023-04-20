#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 5
typedef int element;

typedef struct{
    int front;
    int rear;
    element data[MAX_SIZE];
} QueueType;

void error(char *message){
    fprintf(stderr,"%s",message);
    exit(1);
}

void init_queue(QueueType *q){
    q -> front = 0;
    q -> rear = 0;
}

int is_empty(QueueType *q){
    if(q->front == q-> rear){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(QueueType *q){
    if(((q ->rear)+1) % MAX_SIZE == q->front){
        return 1;
    }
    else{
        return 0;
    }
}

void print_queue(QueueType *q){
    printf("QUEUE(front=%d, rear=%d) = ",q -> front , q-> rear);
    int i = q -> front;
    if(!is_empty(q)){
        do{
            i = (i+1) % MAX_SIZE;
            printf("%d | ",q->data[i]);
            if(i == q->rear){
                break;
            }
        } while(i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType *q,element item){
    if(is_full(q)){
        error("ť�� ��ȭ�����Դϴ�.");
    }
    q -> rear = ( q->rear+1 ) % MAX_SIZE;
    q->data[q->rear] = item ;
}

element dequeue(QueueType *q){

    if(is_empty(q)){
        error("ť�� ��������Դϴ�.");
    }
    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front]; 
}

element peex(QueueType *q){
    if(is_empty(q)){
        error("ť�� ��������Դϴ�.");
    }
    return q->data[(q->front + 1) % MAX_SIZE];
}

int main(void){

    QueueType q;
    int element;

    init_queue(&q);
    srand(time(NULL));

    for (int i = 0; i < 100; i++)
    {
        if (rand() % 5 == 0){ //�������� 5�� ����� ��������
            enqueue(&q,rand()%100); //����ť���ٰ� 0~99 ������ �������� �߰��Ѵ�.
        } 
        print_queue(&q);

        if(rand() %10 == 0){
            dequeue(&q);
        }
        print_queue(&q);
    }

    
    return 0;

}