int palindrome_check(DequeType* q) {
	while (!is_empty(q)) {
		if (delete_front(q) != delete_rear(q)) {
			return 0;
		}
		else {
			return 1;
		}	
	}
}
if (palindrome_check(&q)) {
		printf("ȸ���Դϴ�");
	}
	else {
		printf("ȸ���� �ƴմϴ�");
	}

//��ǻ�Ͱ��а� 20203193 ���ذ�