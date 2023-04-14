#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

//typedef int element;

typedef struct{
    int id;
    int arrival_time;
    int service_time;
} element;

typedef struct{
    element data[MAX_SIZE];
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

int enqueue(QueueType *q,element item){ //? 큐에 값을 추가하는 함수
    if(is_full(q))
        error("큐가 포화상태입니다.");
    q->reer = (q->reer + 1) % MAX_SIZE;
    q->data[q->reer] = item;
}

element dequeue(QueueType *q){ //큐에서 값을 제거하는 함수
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front];
}

int main(void){

    int minutes = 60;
    int total_wait = 0;
    int total_customers = 0;
    int service_time = 0;
    int service_customer;
    
    QueueType q;
    init_queue(&q);

    srand(time(NULL));
    
    for(int clock = 0; clock < minutes; clock++){
        printf("현재시각 = %d\n",clock);
        if((rand()%10) < 3){
            element customer;
            customer.id = total_customers++;
            customer.arrival_time = clock;
            customer.service_time = rand() % 3 +1;
            enqueue(&q,customer);
            printf("고객 %d이 %d분에 들어옵니다. 업무처리시간 = %d분\n",customer.id,customer.arrival_time,customer.service_time);
        }
        if(service_time > 0){
            printf("고객 %d 업무 처리중입니다. \n",service_customer);
            service_time--;
        }
        else{
            if(!is_empty(&q)){
                element customer = dequeue(&q);
                service_customer = customer.id;
                service_time = customer.service_time;
                printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",customer.id,clock,clock-customer.arrival_time);
                total_wait += clock - customer.arrival_time;
            }
        }
    }
    printf("전체 대기 시간 = %d분 \n",total_wait);
    printf("\n\n컴퓨터공학과 20203193 박준걸\n\n");
    return 0;
}