int get_sum(ListNode* head){
    int sum = 0;
    ListNode *p = head;
    while(p != NULL){
        sum += p->data;
        p = p -> link;
    }
    return sum;
}

//��ǻ�� ���а� 20203193 ���ذ�