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
		printf("회문입니다");
	}
	else {
		printf("회문이 아닙니다");
	}

//컴퓨터공학과 20203193 박준걸