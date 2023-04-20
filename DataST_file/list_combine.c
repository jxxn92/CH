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
    ListNode *removed; // 삭제할 노드를 복사한 removed 노드
    removed = pre -> link; ///삭제할 노드를 removed에다가 복사
    pre -> link = removed -> link; //pre 의 링크에다가 지금 removed는 복사된 곧 없어질 노드이기 때문에 없어질 노드의 링크는 지금 마지막에 있는 노드 이기때문에 
    free(removed);                    // 그 값을 복사해주면 pre노드의 링크가 마지막에 있는 노드를 가르키게 된다.
    return head;
}

void print_list(ListNode *head){
    for(ListNode *p = head; p != NULL; p = p-> link){ //head부터 NULL이 나올때까지 NULL이 나왔다는건 사실상 이제 마지막 노드 까지 갔을경우
                                                        //p = p->link와 같은경우에는 다음 링크의 값을 p에다가 넣어라.
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