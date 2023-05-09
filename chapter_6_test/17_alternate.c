ListNode* alternate(ListNode* A, ListNode* B) {
	ListNode* p = A,
    ListNode* q = B,  
    ListNode* r = NULL;
	while (p != NULL || q != NULL) {
		if(p != NULL){
			insert_last(&r, create_node(p->data));
			p = p->link;
		}
		if (q != NULL) {
			insert_last(&r, create_node(q->data));
			q = q->link;
		}
	}
	return r;
}

//��ǻ�Ͱ��а� 20203193 ���ذ�

// �ð� ���⵵�� O(a + b)