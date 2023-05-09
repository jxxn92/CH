#include <stdio.h>
#include <stdlib.h>

typedef struct ListHead{
    int coef;
    int expon;
    struct ListHead *link;
} ListHead;

typedef struct ListType
{
    int size;
    ListHead *head;
    ListHead *tail;
} ListType;

void error(char *message){
    fprintf(stderr,"%s\n",message);
    exit(1);
}

ListType* create(){
    ListType *plist = (ListType *)malloc(sizeof(ListType));
    plist -> size = 0;
    plist -> head = plist -> tail = NULL;
    return plist;
}

void insert_last(ListType* plist, int coef, int expon){
    ListHead* temp = (ListHead *)malloc(sizeof (ListHead)) ;
    if (temp == NULL)
        error("메모리 할당 에러");
    temp -> coef = coef ;
    temp -> expon = expon ;
    temp -> link = NULL;
    if (plist -> tail ==  NULL )  {
        plist -> head = plist -> tail = temp ;
    }
    else{
        plist -> tail -> link = temp;
        plist -> tail = temp;
    }
    plist -> size++;
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3){
    ListHead* a = plist1 -> head;
    ListHead* b = plist2 -> head;

    int sum;

    while (a && b){
        if(a->expon == b-> expon){
            sum = a -> coef + b -> coef;
            if (sum != 0) 
                insert_last(plist3,sum,a->expon);
            a = a -> link;
            b = b -> link;
        }
        else if(a->expon > b->expon){
            insert_last(plist3, a -> coef, a->expon);
            a = a->link;
        }
        else{
            insert_last(plist3, b->coef, b->expon);
            b = b -> link;
        }
    }

    for(;a != NULL; a= a->link)
        insert_last(plist3, a->coef, a->expon);
    for(;b != NULL; b= b->link)
        insert_last(plist3,b->coef,b->expon);
}


void poly_print(ListType* plist){
    ListHead* p = plist -> head;

    printf("polynomial : ");
    for(;p;p=p->link){
        printf("%d^%d + ",p -> coef,p -> expon);
    }
    printf("\n");
}

int main(void){
    ListType *list1,*list2,*list3,*list4,*list5;

    list1 = create();
    list2 = create();
    list3 = create();
    list4 = create();
    list5 = create();

    insert_last(list1,3,6);
    insert_last(list1,7,3);
    insert_last(list1,-2,2);
    insert_last(list1,-9,0);

    insert_last(list2,-2,6);
    insert_last(list2,-4,4);
    insert_last(list2,6,2);
    insert_last(list2,6,1);
    insert_last(list2,1,0);

    poly_print(list1);
    poly_print(list2);

    poly_add(list1,list2,list3);
    poly_print(list3);

    free(list1);
    free(list2);
    free(list3);

    //컴퓨터공학과 20203193 박준걸


}