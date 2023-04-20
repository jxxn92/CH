#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;

typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;
void error(char *message){
    fprintf(stderr,"%s",message);
    exit(1);
}
ListNode* insert_first(ListNode *head,int value){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p -> data = value;
    p -> link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode *head,ListNode *pre,element value){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p -> data = value;
    p -> link = pre -> link;
    pre->link = p;
    return head;
}

ListNode* delete_first(ListNode *head){
    ListNode *removed;
    if(head == NULL){
        return NULL;
    }
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}
ListNode* delete(ListNode *head,ListNode *pre)
{
    ListNode *removed; // ������ ��带 ������ removed ���
    removed = pre -> link; ///������ ��带 removed���ٰ� ����
    pre -> link = removed -> link; //pre �� ��ũ���ٰ� ���� removed�� ����� �� ������ ����̱� ������ ������ ����� ��ũ�� ���� �������� �ִ� ��� �̱⶧���� 
    free(removed);                    // �� ���� �������ָ� pre����� ��ũ�� �������� �ִ� ��带 ����Ű�� �ȴ�.
    return head;
}

void print_list(ListNode *head){
    for(ListNode *p = head; p != NULL; p = p-> link){ //head���� NULL�� ���ö����� NULL�� ���Դٴ°� ��ǻ� ���� ������ ��� ���� �������
                                                        //p = p->link�� ������쿡�� ���� ��ũ�� ���� p���ٰ� �־��.
        printf("%d ->",p->data);
    }
    printf("NULL");
    printf("\n");
}

int main(void){

    ListNode *head = NULL;

    for (int i = 0 ; i < 5; i++){
        head = insert_first(head,i);
        print_list(head);
    }

    for (int i = 0 ; i < 5; i++){
        head = delete_first(head);
        print_list(head);
    }
    return 0;
}