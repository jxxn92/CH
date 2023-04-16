#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef int element;
typedef struct{
    int data[MAX_SIZE];
    int front;
    int rear;
} QueueType;

void error(char *message){ //����ť�� ���������� ������ ����ϴ� �Լ�
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_queue(QueueType *q){ //����ť�� �ʱ�ȭ �ϴ� �Լ�
    q -> front =  0;
    q -> rear = 0;
}

int is_empty(QueueType *q){  //����ť�� ����ִ��� Ȯ���ϴ� �Լ�
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
        error("�Լ��� ��������Դϴ�.");
        exit(1);
    }
    else{
        cnt = ((q->rear) % MAX_SIZE) - ((q->front)%MAX_SIZE);
    }
    return cnt;
}
int is_full(QueueType *q){ //����ť�� �� ���ִ��� Ȯ���ϴ� �Լ�
    if(((q->rear)+1)%MAX_SIZE == q->front){
        return 1;
    }
    else{
        return 0;
    }
}

void queue_print(QueueType *q){ // ť�� ���� ����ϴ� �Լ� 
    printf("QUEUE(front=%d rear=%d) = ",q->front,q->rear);
    if(!is_empty(q)){ //������� ������ ���� �߰�
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

void enqueue(QueueType *q,element item){ //ť�� ���� �߰��ϴ� �Լ�
    if(is_full(q)){
        error("ť�� ��ȭ�����Դϴ�.");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = item;

}

int dequeue(QueueType *q){ //ť���� ���� �����ϴ� �Լ�
    if(is_empty(q)){
        error("ť�� ��������Դϴ�.");
        return -1;
    }

    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front];
}

int main(void){

    QueueType q;
    int element;

    init_queue(&q);
    printf("--������ �߰� �ܰ�--\n");
    while(!is_full(&q)){
        printf("������ �Է��Ͻÿ�: ");
        scanf("%d",&element);
        enqueue(&q,element);
        queue_print(&q);
        printf("\n%d\n",get_count(&q));
        
    }
    printf("ť�� ��ȭ�����Դϴ�.\n\n");
    
    printf("--������ ���� �ܰ�--\n");
    while(!is_empty(&q)){
        element = dequeue(&q);
        printf("������ ���� : %d \n",element);
        queue_print(&q);
        printf("\n%d\n",get_count(&q));
    }

    printf("ť�� ��������Դϴ�.\n");


    printf("\n\n��ǻ�Ͱ��а� 20203193 ���ذ�\n\n");

    return 0;
    
}