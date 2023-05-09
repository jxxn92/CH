int get_sum(ListNode* head){
    int sum = 0;
    ListNode *p = head;
    while(p != NULL){
        sum += p->data;
        p = p -> link;
    }
    return sum;
}

//컴퓨터 공학과 20203193 박준걸