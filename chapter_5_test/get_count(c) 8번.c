int get_count(QueueType *q){
    int cnt = 0;
    if(is_empty(q)){
        error("함수가 공백상태입니다.");
        exit(1);
    }
    if(q->rear >= q->front){
        cnt = ((q->rear) % MAX_SIZE) - ((q->front)%MAX_SIZE);
    }
    else{
        cnt = MAX_SIZE - (q->front - q->rear);
    }
    return cnt;

    printf("컴퓨터공학과 20203193 박준걸");
}