#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 5

typedef int element;
typedef struct{
    int front,rear;
    element data[MAX_SIZE];
} QueueType;

void error(char* message){
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_queue(QueueType* q){
    q -> front = 0;
    q -> rear = 0;
}

int is_empty(QueueType* q){
    return q->rear == q->front; 
}

int is_full(QueueType* q){
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void print_queue(QueueType* q){
    printf("QUEUE(front=%d rear=%d) = ",q->front,q->rear);
    if(!is_empty(q)){
        int i = q->front;
        do{
            i = (i + 1) % MAX_SIZE;
            printf("%d | ",q->data[i]);
            if(i == q->rear)
                break;
        } while(i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType* q, element item){
    if(is_full(q)){
        error("포화");
    }
    q-> rear = (q->rear+1) % MAX_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q){
    if(is_empty(q)){
        error("공백");
    }
    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front];
}

element peek(QueueType* q){
    if(is_empty(q)){
        error("포화");
    }
    return q->data[(q->front+1)%MAX_SIZE];
}

int main(void){
    QueueType queue;
    int element;

    init_queue(&queue);
    srand(time(NULL));

    for(int i = 0; i < 100; i++){
        if(rand() % 5 == 0){ // 5로 나누어 떨이진다면
            enqueue(&queue,rand()%100); // 0~99까지 아무 숫자 큐에 원혀큐에 삽입
        }
        print_queue(&queue);

        if(rand()%10 == 0){
            int data = dequeue(&queue);
        }
        print_queue(&queue);
    }
    return 0;
}