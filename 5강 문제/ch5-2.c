#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef int element;
typedef struct{
    int data[MAX_SIZE];
    int front;
    int rear;
} QueueType;

void error(char *message){ //원형큐가 오류가나면 오류를 출력하는 함수
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_queue(QueueType *q){ //원형큐를 초기화 하는 함수
    q -> front =  0;
    q -> rear = 0;
}

int is_empty(QueueType *q){  //원형큐가 비어있는지 확인하는 함수
    if(q->front == q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

int get_count(QueueType *q){
    int cnt = 0;
    if(is_empty(q)){
        error("함수가 공백상태입니다.");
        exit(1);
    }
    else{
        cnt = ((q->rear) % MAX_SIZE) - ((q->front)%MAX_SIZE);
    }
    return cnt;
}
int is_full(QueueType *q){ //원형큐가 꽉 차있는지 확인하는 함수
    if(((q->rear)+1)%MAX_SIZE == q->front){
        return 1;
    }
    else{
        return 0;
    }
}

void queue_print(QueueType *q){ // 큐의 값을 출력하는 함수 
    printf("QUEUE(front=%d rear=%d) = ",q->front,q->rear);
    if(!is_empty(q)){ //비어있지 않으면 값을 추가
        int i = q -> front;
        do{
            i = (i+1) % MAX_SIZE;
            printf("%d | ",q->data[i]);
            if(i == q-> rear){ 
                break;
            }
        }while(i != q -> front);
    }
    printf("\n");
}

void enqueue(QueueType *q,element item){ //큐에 값을 추가하는 함수
    if(is_full(q)){
        error("큐가 포화상태입니다.");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = item;

}

int dequeue(QueueType *q){ //큐에서 값을 제거하는 함수
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
        return -1;
    }

    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front];
}

int main(void){

    QueueType q;
    int element;

    init_queue(&q);
    printf("--데이터 추가 단계--\n");
    while(!is_full(&q)){
        printf("정수를 입력하시오: ");
        scanf("%d",&element);
        enqueue(&q,element);
        queue_print(&q);
        printf("\n%d\n",get_count(&q));
        
    }
    printf("큐가 포화상태입니다.\n\n");
    
    printf("--데이터 삭제 단계--\n");
    while(!is_empty(&q)){
        element = dequeue(&q);
        printf("꺼내진 정수 : %d \n",element);
        queue_print(&q);
        printf("\n%d\n",get_count(&q));
    }

    printf("큐는 공백상태입니다.\n");


    printf("\n\n컴퓨터공학과 20203193 박준걸\n\n");

    return 0;
    
}