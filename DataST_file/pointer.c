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
    printf("swap�� ����ϱ� �� : a = %d b = %d\n\n",a,b);
    swap(&a,&b);
    printf("swap�� ����� �� : a = %d b = %d",a,b);

} */

void get_integers(int list[]){ // list = [1,2,3,4,5,6]
    printf("6���� ������ �Է��Ͻÿ� : ");
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d",&list[i]);
    }
    
}
int cal_sum(int list[]){
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum = sum += *(list + i); //�����ͷ� �ϸ� list�迭�� ù��° �ּҰ� + 4����Ʈ �߰� �ؼ� ���� ������ �Ѿ�� ���� << ������ �������� �ذ��� ����.
    }
    return sum;
}

int main(void){
    
    int list[SIZE];

    get_integers(list);

    printf("�� = %d\n",cal_sum(list));

    return 0;
}

