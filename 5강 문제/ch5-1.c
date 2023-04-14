#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct{
    int front;
    int reer;
    int data[MAX_SIZE];
} QueueType;

void error(char *message){
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_queue(QueueType *q){ //front 와 reer을 초기화 해주는 함수
    q -> front = -1;
    q -> reer = -1;
}

void queue_print(QueueType *q){ //선형큐를 출력해주는 함수
    for(int i = 0 ; i < MAX_SIZE; i++){
        if(i <= q-> front || i > q->reer){  // front 나 reer가 범위가 아니면 "|"으로 벽을 출력 하고 값이 맞다면 숫자를 출력
            printf("   | ");
        }
        else{
            printf("%d | ",q->data[i]);
        }
    }
    printf("\n");
}

int is_full(QueueType *q){ //선형큐가 꽉 차 있는지 확인 하는 함수
    if(q -> reer == MAX_SIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}

int is_empty(QueueType *q) { //선형 큐가 비어있는지 확인하는 함수
    if(q -> front == q -> reer){
        return 1;
        }
    else{
        return 0;
        }
    }

void enqueue(QueueType *q,int item){ //선형큐 안에 값을 집어 넣는 함수
    if(is_full(q)){
        error("큐가 포화상태입니다.");
        return;
    }
    q->data[++(q->reer)] = item; 
}

int dequeue(QueueType *q){ //선형큐에서 값을 삭제하는 함수
    if(is_empty(q)){
        error("큐가 비어있습니다.");
        return -1;
    }
    int s;
    s = q->data[++(q->front)];
    return s;
}

int main(void){

    int item = 0;
    QueueType q; //스트럭트를 q로 선언

    init_queue(&q); // q 초기화

    enqueue(&q,10); // 10 이라는 값 삽입
    queue_print(&q); // 값 출력
    
    enqueue(&q,20); // 20 이라는 값 삽입
    queue_print(&q); // 값 출력
    
    enqueue(&q,30); // 30 이라는 값 삽입
    queue_print(&q); // 값 출력

    item = dequeue(&q); // 값 삭제
    queue_print(&q); // 값 출력
     
    item = dequeue(&q); // 값 삭제
    queue_print(&q); // 값 출력
    
    item = dequeue(&q); // 값 삭제
    queue_print(&q); // 값 출력

    printf("\n\n컴퓨터공학과 20203193 박준걸\n\n");

    return 0;
}
