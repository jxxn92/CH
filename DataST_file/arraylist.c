#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element;

typedef struct{
    element array[MAX_SIZE];
    int size;
} ArrayListType;

void error(char *message){
    fprintf(stderr,"%s",message);
    exit(1);
}
void init_array(ArrayListType *l){
    l->size = 0;
}

int is_empty(ArrayListType *l){ //arraylist 가 비어있으면 1 반환 비어 있지 않으면 0 반환
    if(l->size == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(ArrayListType *l){
    if(l->size == MAX_SIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}

element get_pos(ArrayListType *l,int pos){
    if(pos < 0 || pos >= l->size){
        error("위치오류");
    }
    return l->array[pos];
}

void print_list(ArrayListType *l){
    for (int i = 0 ; i < l->size ; i++){
        printf("%d->",l->array[i]);
    }
    printf("\n");
}

void insert(ArrayListType *l,int pos,int item){
    if(!is_full(l) && (pos >= 0 )&& (pos <= l->size)){
        for(int i = (l->size - 1);i >= pos;i--){
            l->array[i+1] = l->array[i];
        }
        l->array[pos] = item;
        l->size++;
    }
}

void insert_last(ArrayListType *l,element item){
    if(l->size >= MAX_SIZE){
        error("리스트 오버플로우");
    }
    l->array[l->size++] = item;
}
element delete(ArrayListType *l,int pos){
    element item;

    if(pos < 0 || pos >= l->size){
        error("위치 오류");
    }
    item = l->array[pos];
    for(int i = pos; i <(l->size -1); i++){
        l -> array[i] = l-> array[i+1];
    }
    l->size--;
    return item;
}

int main(void){
    ArrayListType l;

    init_array(&l);

    insert(&l,0,10); print_list(&l);
    insert(&l,0,20); print_list(&l);
    insert(&l,0,30); print_list(&l);
    insert_last(&l,40); print_list(&l);
    delete(&l,0); print_list(&l);

    return 0;

}