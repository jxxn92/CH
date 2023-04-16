#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    
    char name[10];
    int age;
    double gpa;
} student;

int main(void){

    student *p;

    p = (student *)malloc(sizeof(student));

    if(p==NULL){
        fprintf(stderr,"메모리를 할당 할 수 없습니다.");
        exit(1);
    }
    strcpy(p->name,"kim");
    p->age = 20;
    p->gpa = 4.3;

    printf("%s %d %lf",p->name,p->age,p->gpa);
    free(p);
    return 0;
}