#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef int element;

typedef struct{
    int front;
    int rear;
    element data[MAX_SIZE];
} DequeType;

void error(char *message){
    fprintf(stderr,"%s",message);
}

void init_deque(DequeType *q){
    q -> front = 0;
    q -> rear = 0;
}

int is_empty(DequeType *q){
    if(q->front == q-> rear){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(DequeType *q){
    if((q->rear+1) & MAX_SIZE == q->front){
        return 1;
    }
    else{
        return 0;
    }
}

void printt_deque(DequeType *q){
    printf("DEQUE(front=%d rear=%d) = ",q->front,q->rear);
    if(!is_empty(q)){
        int i = q->front;
        do{
            i = (i+1)%MAX_SIZE;
            printf("%d |",q->data[i]);
            if(i == q->rear){
                break;
            }
        } while(i != q->front);
    }
    printf("\n");
}
void add_rear(DequeType *q,element item){
    if(is_full(q)){
        error("큐가 포화상태입니다.");
        exit(1);
    }
    q->rear = (q->rear+1) % MAX_SIZE;
    q->data[q->rear] = item;
}
element delete_front(DequeType *q){
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
        exit(1);
    }
    q->front = (q->front +1 ) %MAX_SIZE;
    return q->data[q->front];
}

element get_front(DequeType *q){
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
        exit(1);
    }
    return q->data[(q->front+1)%MAX_SIZE];
}

void add_front(DequeType *q,element val){
    if(is_full(q)){
        error("큐가 포화상태입니다.");
        exit(1);
    }
    q->data[q->front] = val;
    q->front = (q->front -1 + MAX_SIZE) % MAX_SIZE;
}

element delete_rear(DequeType *q){
    int prev = q-> rear;
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
        exit(1);
    }
    q->rear = (q->rear -1 +MAX_SIZE )%MAX_SIZE;
    return prev;
}

element get_rear(DequeType *q){
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
        exit(1);
    }
    return q->data[q->rear];
}

int main(void){

    DequeType q;

    init_deque(&q);

    for(int i = 0 ; i < 3 ; i++){
        add_front(&q,i);
        printt_deque(&q);
    }
    for(int i = 0 ; i < 3; i++){
        delete_rear(&q);
        printt_deque(&q);
    }
    return 0;
}