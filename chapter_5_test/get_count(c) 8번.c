int get_count(QueueType *q){
    int cnt = 0;
    if(is_empty(q)){
        error("�Լ��� ��������Դϴ�.");
        exit(1);
    }
    if(q->rear >= q->front){
        cnt = ((q->rear) % MAX_SIZE) - ((q->front)%MAX_SIZE);
    }
    else{
        cnt = MAX_SIZE - (q->front - q->rear);
    }
    return cnt;

    printf("��ǻ�Ͱ��а� 20203193 ���ذ�");
}