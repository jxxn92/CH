#include <stdio.h>

void hanoi(int n,char from,char mid,char to)
{
    if(n==1){
    printf("원반 %d를 %c에서 %c로 이동\n",n,from,to); 
    return;
    }

    hanoi(n-1,from,to,mid);
    printf("원반 %d를 %c에서 %c로 이동\n",n,from,to);
    hanoi(n-1,mid,from,to);
}

int main(){
    hanoi(5,'A','B','C');
}