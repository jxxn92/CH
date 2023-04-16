#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define SIZE 10

int main(void){
    
    int *p; //포인터 변수는 4바이트 고정
    p = (int *)malloc(SIZE * sizeof(int));
    if(p == NULL){
        fprintf(stderr,"메모리가 부족해서 할당 불가합니다.");
        exit(1);
    }
    for (int i = 0; i < SIZE; i++)
    {
        p[i] = i;        
    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d \n",p[i]);       
    }
    
    free(p);
    return 0;
}