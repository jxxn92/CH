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

    printf("��ǻ�Ͱ��а� 20203193 ���ذ�");
}