#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
typedef int element;
typedef struct{
    element data[MAX_SIZE];
    int front,rear;
} DequeType;

void error(char* message){
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_deque(DequeType* d){
    d -> front = 0;
    d -> rear = 0;
}

int is_empty(DequeType *d){
    if(d->front == d->rear ){
        return 1;
    }
    else
        return 0;
}

int is_full(DequeType *d){
    if((d -> rear +1 ) % MAX_SIZE == d -> front){
        return 1;
    }
    else
        return 0;
}

void print_deque(DequeType *d){
    printf("DEQUEUE(front=%d rear=%d) = ",d->front,d->rear);
    if(!is_empty(d)){
        int i = d->front;
        do{
            i = (i + 1) % MAX_SIZE;
            printf("%d | ",d->data[i]);
            if(i == d->rear)
                break;
        } while(i != d->front);
    }
    printf("\n");
}

void add_rear(DequeType *d,element item){
    if(is_full(d)){
        error("포화");
    }
    d -> rear = (d -> rear + 1) % MAX_SIZE;
    d->data[d->rear] = item;
}

element delete_front(DequeType *d){
    if(is_empty(d)){
        error("공백");
    }
    d -> front = (d->front+1) % MAX_SIZE;
    return d->data[d->front];
}

element get_front(DequeType *d){
    if(is_empty(d)){
        error("공백");
    }
    return (d->data[(d->front+1) % MAX_SIZE]);
}

void add_front(DequeType *d,int val){
    if(is_full(d)){
        error("포화");
    }
    d->data[d->front] = val;
    d->front = (d->front -1 + MAX_SIZE) %MAX_SIZE;
}

element delete_rear(DequeType *d){
    int prev = d->rear;
    if(is_empty(d)){
        error("공백");
    }
    d->rear = (d -> rear -1 + MAX_SIZE)%MAX_SIZE;
    return prev;
}

int get_rear(DequeType *d){
    if(is_empty(d)){
        error("공백");
    }
    return d->data[d->rear];
}

int main(void){

    DequeType d;
    init_deque(&d);

    for(int i = 0 ; i < 4; i++){
        add_front(&d,i);
        print_deque(&d);
    }
    for(int i = 0 ; i < 4; i++){
        delete_rear(&d);
        print_deque(&d);
    }

    return 0;

}