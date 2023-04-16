#include <stdio.h>

void hanoi(int n,char from,char mid,char to)
{
    if(n==1){
    printf("���� %d�� %c���� %c�� �̵�\n",n,from,to); 
    return;
    }

    hanoi(n-1,from,to,mid);
    printf("���� %d�� %c���� %c�� �̵�\n",n,from,to);
    hanoi(n-1,mid,from,to);
}

int main(){
    hanoi(5,'A','B','C');
}