#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void add_element(ListNode** phead, ListNode* new_node) {
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else {
		ListNode* c = NULL;
		ListNode* p = *phead;
		while (p != NULL) {
			if (new_node->data < p->data) {
				if (c == NULL) {
					new_node->link = *phead;
					*phead = new_node;
				}
				else {
					c->link = new_node;
					new_node->link = p;
				}
				break;
			}
			c = p;
			p = p->link;
		}
	}
}

void delete_element(ListNode** head, element item) {
	ListNode* p = NULL, * removed = *head;
	while (removed->data != item) {
		p = removed;
		removed = removed->link;
	}
	if (p == NULL)
		*head = (*head)->link;
	else
		p->link = removed->link;
	return;
}

void clear(ListNode** head) {
	(*head)->link = NULL;
}

int is_in_list(ListNode* head, element item) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == item)
			return 1;
		p = p->link;
	}
	return 0;
}

int get_length(ListNode* head) {
	int count = 0;
	ListNode* p = head;
	while (p != NULL) {
		count++;
		p = p->link;
	}
	return count;
}

int is_empty(ListNode* head) {
	return head->link == NULL;
}

ListNode* create_node(element data) {
	ListNode* new_node;
	new_node = (ListNode*)malloc(sizeof(new_node));
	new_node->data = data;
	new_node->link = NULL;
	return new_node;
}

int is_full(ListNode* head) {
	// 노드가 더이상 만들어지지 않는다면 메모리가 가득찬상태.
	ListNode* N = create_node(0);
	if (N == NULL)
		return 1;
	return 0;
}

void display(ListNode* head) {
	ListNode* p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}
