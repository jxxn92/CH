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


void print_list(ListNode* head){
    for(ListNode *p = head; p != NULL; p = p->link){
        printf("%d->",p->data); //찾기 성공해서 위치 반환
    }
    printf("NULL \n"); // 찾기 실패한 경우 
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

ListNode* contact_list(ListNode* head1,ListNode* head2){
    if(head1 == NULL) return head2;
    else if(head2 == NULL) return head1;
    else{
        ListNode* p;
        p = head1;
        while(p->link != NULL){
            p = p->link;
        }
        p->link = head2;
        return head1;
    }
}

int main(void){

    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    head1 = insert_first(head1,30);
    head1 = insert_first(head1,20);
    head1 = insert_first(head1,10);
    print_list(head1);

    head2 = insert_first(head2,50);
    head2 = insert_first(head2,40);
    print_list(head2);

    ListNode* total = NULL;

    total =contact_list(head1,head2);
    print_list(total);

    return 0;
}