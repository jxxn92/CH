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

void init_queue(QueueType *q){ //front �� reer�� �ʱ�ȭ ���ִ� �Լ�
    q -> front = -1;
    q -> reer = -1;
}

void queue_print(QueueType *q){ //����ť�� ������ִ� �Լ�
    for(int i = 0 ; i < MAX_SIZE; i++){
        if(i <= q-> front || i > q->reer){  // front �� reer�� ������ �ƴϸ� "|"���� ���� ��� �ϰ� ���� �´ٸ� ���ڸ� ���
            printf("   | ");
        }
        else{
            printf("%d | ",q->data[i]);
        }
    }
    printf("\n");
}

int is_full(QueueType *q){ //����ť�� �� �� �ִ��� Ȯ�� �ϴ� �Լ�
    if(q -> reer == MAX_SIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}

int is_empty(QueueType *q) { //���� ť�� ����ִ��� Ȯ���ϴ� �Լ�
    if(q -> front == q -> reer){
        return 1;
        }
    else{
        return 0;
        }
    }

void enqueue(QueueType *q,int item){ //����ť �ȿ� ���� ���� �ִ� �Լ�
    if(is_full(q)){
        error("ť�� ��ȭ�����Դϴ�.");
        return;
    }
    q->data[++(q->reer)] = item; 
}

int dequeue(QueueType *q){ //����ť���� ���� �����ϴ� �Լ�
    if(is_empty(q)){
        error("ť�� ����ֽ��ϴ�.");
        return -1;
    }
    int s;
    s = q->data[++(q->front)];
    return s;
}

int main(void){

    int item = 0;
    QueueType q; //��Ʈ��Ʈ�� q�� ����

    init_queue(&q); // q �ʱ�ȭ

    enqueue(&q,10); // 10 �̶�� �� ����
    queue_print(&q); // �� ���
    
    enqueue(&q,20); // 20 �̶�� �� ����
    queue_print(&q); // �� ���
    
    enqueue(&q,30); // 30 �̶�� �� ����
    queue_print(&q); // �� ���

    item = dequeue(&q); // �� ����
    queue_print(&q); // �� ���
     
    item = dequeue(&q); // �� ����
    queue_print(&q); // �� ���
    
    item = dequeue(&q); // �� ����
    queue_print(&q); // �� ���

    printf("\n\n��ǻ�Ͱ��а� 20203193 ���ذ�\n\n");

    return 0;
}
