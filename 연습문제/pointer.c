#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 6
/* void swap(int *px,int *py){

    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}


int main(){

    int a = 1;
    int b = 2;
    printf("swap을 출력하기 전 : a = %d b = %d\n\n",a,b);
    swap(&a,&b);
    printf("swap을 출력한 후 : a = %d b = %d",a,b);

} */

void get_integers(int list[]){ // list = [1,2,3,4,5,6]
    printf("6개의 정수를 입력하시오 : ");
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d",&list[i]);
    }
    
}
int cal_sum(int list[]){
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum = sum += *(list + i); //포인터로 하면 list배열의 첫번째 주소값 + 4바이트 추가 해서 다음 값으로 넘어가는 구조 << 포인터 연산으로 해결한 문제.
    }
    return sum;
}

int main(void){
    
    int list[SIZE];

    get_integers(list);

    printf("합 = %d\n",cal_sum(list));

    return 0;
}

