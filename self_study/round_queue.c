#include <stdio.h>
#include <stdlib.h>

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
        error("error");
    }
    q-> rear = (q->rear+1) % MAX_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q){
    if(is_empty(q)){
        error("error");
    }
    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front];
}

element peek(QueueType* q){
    if(is_empty(q)){
        error("error");
    }
    return q->data[(q->front+1)%MAX_SIZE];
}

int main(void){

    QueueType q;
    int element;

    init_queue(&q);
    printf("-- 데이터 추가 단계 --\n");
    while(!is_full(&q)){
        printf("정수를 입력하세요: ");
        scanf("%d",&element);
        enqueue(&q,element);
        print_queue(&q);
    }
    printf("큐는 포화상태입니다.\n");

    printf("-- 데이터 제거 단계 --\n");

    while (!is_empty(&q))
    {
        element = dequeue(&q);
        printf("꺼내진 정수 : %d \n",element);
        print_queue(&q);
    }
    printf("큐는 공백상태입니다.\n");

    return 0;
    
}