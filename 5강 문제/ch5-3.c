#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct{
    int data[MAX_SIZE];
    int front;
    int reer;
} QueueType;

void error(char *message){ //원형큐가 오류가나면 오류를 출력하는 함수
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_queue(QueueType *q){ //원형큐를 초기화 하는 함수
    q -> front =  0;
    q -> reer = 0;
}

int is_empty(QueueType *q){  //원형큐가 비어있는지 확인하는 함수
    if(q->front == q->reer){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(QueueType *q){ //원형큐가 꽉 차있는지 확인하는 함수
    if(((q->reer)+1)%MAX_SIZE == q->front){
        return 1;
    }
    else{
        return 0;
    }
}

void queue_print(QueueType *q){ // 큐의 값을 출력하는 함수 
    printf("QUEUE(front=%d reer=%d) = ",q->front,q->reer);
    if(!is_empty(q)){ //비어있지 않으면 값을 추가
        int i = q -> front;
        do{
            i = (i+1) % MAX_SIZE;
            printf("%d | ",q->data[i]);
            if(i == q-> reer){ 
                break;
            }
        }while(i != q -> front);
    }
    printf("\n");
}

void enqueue(QueueType *q,int item){ //큐에 값을 추가하는 함수
    if(is_full(q)){
        error("큐가 포화상태입니다.");
        return;
    }
    else{
        q->reer = (q->reer + 1) % MAX_SIZE;
        q->data[q->reer] = item;
    }
}

int dequeue(QueueType *q){ //큐에서 값을 제거하는 함수
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
        return -1;
    }
    else{
        q->front = (q->front + 1) % MAX_SIZE;
        return q->data[q->front];
    }
}

int main(void){

    QueueType q;
    int element;

    init_queue(&q);
    srand(time(NULL)); //시간과 관련한 랜덤한 변수 설정
    printf("\n\n컴퓨터공학과 20203193 박준걸\n\n");

    for(int i = 0 ; i < 100; i++){
        if(rand() % 5 == 0){ // 5로 나누어 떨어지면 0~99까지 랜덤한 숫자 추가
            enqueue(&q,rand()%100);
        }
        queue_print(&q);
        if(rand() % 10 == 0){ // 10으로 나누어 떨어지면 숫자 제거
            int data = dequeue(&q);
        }
        queue_print(&q);
    }

    return 0;
}