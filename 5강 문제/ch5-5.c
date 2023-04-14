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

void error(char *message){ //����ť�� ���������� ������ ����ϴ� �Լ�
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_queue(QueueType *q){ //����ť�� �ʱ�ȭ �ϴ� �Լ�
    q -> front =  0;
    q -> reer = 0;
}

int is_empty(QueueType *q){  //����ť�� ����ִ��� Ȯ���ϴ� �Լ�
    if(q->front == q->reer){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(QueueType *q){ //����ť�� �� ���ִ��� Ȯ���ϴ� �Լ�
    if(((q->reer)+1)%MAX_SIZE == q->front){
        return 1;
    }
    else{
        return 0;
    }
}

void queue_print(QueueType *q){ // ť�� ���� ����ϴ� �Լ� 
    printf("QUEUE(front=%d reer=%d) = ",q->front,q->reer);
    if(!is_empty(q)){ //������� ������ ���� �߰�
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

int enqueue(QueueType *q,element item){ //? ť�� ���� �߰��ϴ� �Լ�
    if(is_full(q))
        error("ť�� ��ȭ�����Դϴ�.");
    q->reer = (q->reer + 1) % MAX_SIZE;
    q->data[q->reer] = item;
}

element dequeue(QueueType *q){ //ť���� ���� �����ϴ� �Լ�
    if(is_empty(q))
        error("ť�� ��������Դϴ�.");
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
        printf("����ð� = %d\n",clock);
        if((rand()%10) < 3){
            element customer;
            customer.id = total_customers++;
            customer.arrival_time = clock;
            customer.service_time = rand() % 3 +1;
            enqueue(&q,customer);
            printf("�� %d�� %d�п� ���ɴϴ�. ����ó���ð� = %d��\n",customer.id,customer.arrival_time,customer.service_time);
        }
        if(service_time > 0){
            printf("�� %d ���� ó�����Դϴ�. \n",service_customer);
            service_time--;
        }
        else{
            if(!is_empty(&q)){
                element customer = dequeue(&q);
                service_customer = customer.id;
                service_time = customer.service_time;
                printf("�� %d�� %d�п� ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n",customer.id,clock,clock-customer.arrival_time);
                total_wait += clock - customer.arrival_time;
            }
        }
    }
    printf("��ü ��� �ð� = %d�� \n",total_wait);
    printf("\n\n��ǻ�Ͱ��а� 20203193 ���ذ�\n\n");
    return 0;
}