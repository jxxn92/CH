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
        error("ť�� ��ȭ�����Դϴ�.");
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = item;

}

int delete_front(DequeType *q){
    if(is_empty(q)){
        error("ť�� ��������Դϴ�.");
    }
    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front];
}

int get_front(DequeType *q){
    if(is_empty(q)){
        error("ť�� ��������Դϴ�.");
    }
    return (q->front+1) % MAX_SIZE;
}

void add_front(DequeType *q,int item){
    if(is_full(q)){
        error("ť�� ��ȭ�����Դϴ�.");
    }
    q->data[q->front] = item;
    q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE;// ���� front �� 0�� index �� ������� -1�� �ϸ� front�� index���� -1�� �Ұ��� �ϱ⶧���� MAX_SIZE�� �����ش�.
                                        // -1 + 5 = 4 �̱� ������ % MAX_SIZE�� �������ν� ���ڸ��� ã�ư�.
}

int delete_rear(DequeType *q){ 
    if(is_empty(q)){
        error("ť�� ��������Դϴ�.");
    }
    q->rear = (q->rear - 1 + MAX_SIZE) % MAX_SIZE;
    return q->data[q->rear];
}

int get_rear(DequeType *q){
    if(is_empty(q)){
        error("ť�� ��������Դϴ�.");
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

    printf("\n\n��ǻ�Ͱ��а� 20203193 ���ذ�\n\n");

    return 0;
}