#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define SIZE 10

int main(void){
    
    int *p; //������ ������ 4����Ʈ ����
    p = (int *)malloc(SIZE * sizeof(int));
    if(p == NULL){
        fprintf(stderr,"�޸𸮰� �����ؼ� �Ҵ� �Ұ��մϴ�.");
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