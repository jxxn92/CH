#include <stdio.h>
#include <string.h>

/* struct studentTag{
    char name[10];
    int age;
    double gpa;
}; */
/* typedef struct{
    char name[10];
    int age;
    double gpa;
}student;
 */
typedef struct{
    char name[10];
    int age;
    double gpa;
}student;

int main(){
    
/*     struct studentTag s1;

    strcpy(s1.name,"kim");
    s1.age = 20;
    s1.gpa = 4.3;
 */
    // student s1 = {"kim",20,4.3};

    student a = {"kim",20,4.3};
    student b = {"park",21,4.2};


    printf("%s %d %lf\n",a.name,a.age,a.gpa);
    printf("%s %d %lf",b.name,b.age,b.gpa);
}