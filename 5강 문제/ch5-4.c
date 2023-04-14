#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct{
    int data[MAX_SIZE];
    int front,rear;
} DequeType;

void error(char *message){
    fprintf(stderr,"%s \n",message);
    exit(1);
}

void init_deque(DequeType *q){
    q -> front = 0;
    q -> rear = 0;
}

int is_empty(DequeType *q){
    if(q->front == q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(DequeType *q){
    if(q->front == (q->rear+1)%MAX_SIZE){
        return 1;
    }
    else{
        return 0;
    }
}

void deque_print(DequeType *q){
    printf("DEQUE(front=%d rear=%d) = ",q->front,q->rear);
    if(!is_empty(q)){
        int i = q->front;
        do{
            i = (i+1) % MAX_SIZE;
            printf("%d | ",q->data[i]);
            if(i == q->rear){
                break;
            }
        }while(i != q->front);
    }
    printf("\n");
}

void add_rear(DequeType *q,int item){
    if(is_full(q)){
        error("큐가 포화상태입니다.");
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = item;

}

int delete_front(DequeType *q){
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
    }
    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front];
}

int get_front(DequeType *q){
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
    }
    return (q->front+1) % MAX_SIZE;
}

void add_front(DequeType *q,int item){
    if(is_full(q)){
        error("큐가 포화상태입니다.");
    }
    q->data[q->front] = item;
    q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE;// 만약 front 가 0번 index 에 있을경우 -1을 하면 front의 index값이 -1은 불가능 하기때문에 MAX_SIZE를 더해준다.
                                        // -1 + 5 = 4 이기 때문에 % MAX_SIZE를 해줌으로써 제자리를 찾아감.
}

int delete_rear(DequeType *q){ 
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
    }
    q->rear = (q->rear - 1 + MAX_SIZE) % MAX_SIZE;
    return q->data[q->rear];
}

int get_rear(DequeType *q){
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
    }
    return q->data[q->rear];
}

int main(void){

    DequeType q;

    init_deque(&q);

    for(int i = 0; i < 3; i++){
        add_front(&q,i);
        deque_print(&q);
    }
    for(int i = 0; i < 3 ; i++){
        delete_rear(&q);
        deque_print(&q);
    }

    printf("\n\n컴퓨터공학과 20203193 박준걸\n\n");

    return 0;
}