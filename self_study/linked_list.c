#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode{
    element data;
    struct ListNode* link;
}ListNode;

void error(char* message){
    fprintf(stderr,"%s\n",message);
    exit(1);
}

ListNode* insert_first(ListNode *head, int value){
    ListNode* p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode* head ,ListNode* pre, element value){
    ListNode* p = (ListNode *)malloc(sizeof(ListNode));
    p -> data = value;
    p -> link = pre->link;
    pre->link = p;
    return head;
}

ListNode* delete_first(ListNode* head){
    ListNode* removed;
    if(head == NULL) return NULL;
    removed = head;
    head = removed -> link;
    free(removed);
    return head;
}

ListNode* delete(ListNode* head,ListNode* pre){
    ListNode* removed;
    removed = pre->link;
    pre->link = removed -> link;
    free(removed);
    return head;
}

ListNode* serch_list(ListNode* head,element item){
    ListNode* p = head;

    while(p != NULL){
        if(p->data == item){
            return p;
        }
        p = p->link;
    }
    return NULL;
}

void print_list(ListNode* head){
    for(ListNode *p = head; p != NULL; p = p->link){
        printf("%d->",p->data); //찾기 성공해서 위치 반환
    }
    printf("NULL \n"); // 찾기 실패한 경우 
}


int main(void){
    ListNode *head = NULL;

    for(int i = 0 ; i < 5 ; i++){
        head = insert_first(head,i);
        print_list(head);
    }
    for(int i = 0 ; i < 5 ; i++){
        head = delete_first(head);
        print_list(head);
    }
    return 0;
}

/* int main(void){

    ListNode* head = NULL;

    head = insert_first(head,10);
    print_list(head);
    head = insert_first(head,20);
    print_list(head);
    head = insert_first(head,30);
    print_list(head);

    if(serch_list(head,20) != NULL){
        printf("찾음");
    }
    else{
        printf("못찾음");
    }
    return 0;
} */