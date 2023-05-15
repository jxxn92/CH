#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element;

typedef struct{
    element array[MAX_SIZE];
    int size;
} ArrayListType;

void error(char* message){
    fprintf(stderr,"%s \n",message);
    exit(1);
}

void init_array(ArrayListType *l){
    l -> size = 0;
}

int is_empty(ArrayListType *l){
    if(l->size == 0){
        return 1;
    }
    else
        return 0;
}

int is_full(ArrayListType *l){
    if(l -> size == MAX_SIZE){
        return 1;
    }
    else
        return 0;
}

element get_entry(ArrayListType* l, int pos){
    if(pos < 0 || pos >= l ->size){
        error("error");
    }
    return l->array[pos];
}

void print_array(ArrayListType* l){
    for (int i = 0; i < l->size; i++){
        printf("%d->",l->array[i]);
    }
    printf("\n");
}

void insert_last(ArrayListType* l ,element item){
    if(l->size >= MAX_SIZE){
        error("error");
    }
    l->array[(l->size)++] = item;
}

void insert(ArrayListType* l,int pos,element item){
    if(!is_full(l) && (pos >=0) && (pos <= l->size)){
        for(int i = (l->size -1); i >= pos; i--){
            l->array[i+1] = l->array[i];
        }
        l->array[pos] = item;
        l->size++;
    }
}

element delete(ArrayListType* l ,int pos){
    element item;
    
    if(pos < 0 || pos >= l -> size){
        error("error");
    }
    item = l->array[pos];
    for(int i = pos; i < (l->size-1); i++){
        l->array[i] = l->array[i+1];
    }
    l->size--;
    return item;
}

int main(void){

    ArrayListType l;
    init_array(&l);

    insert(&l,0,10); print_array(&l);
    insert(&l,0,20); print_array(&l);
    insert(&l,0,30); print_array(&l);

    insert_last(&l,40); print_array(&l);
    delete(&l,0); print_array(&l);

    return 0;
}