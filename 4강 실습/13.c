#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct{
    int data[MAX_SIZE];
    int top;
}StackType;
void init_stack(StackType *s)
{
    s->top = -1;
}
int is_empty(StackType *s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int is_full(StackType *s){
    if(s->top == (MAX_SIZE -1)){
        return 1;
    }
    else{
        return 0;
    }
}
void push(StackType *s,int item){
    if(is_full(s)){
        exit(1);
    }
    else{
        s -> data[++(s->top)] = item;

    }
}
int pop(StackType *s){
    if(is_empty(s)){
        exit(1);
    }
    else{
        return s -> data[(s -> top)--];
    }
}
int peek(StackType *s){
    if(is_empty(s)){
        exit(1);
        }
    else{
        return s->data[s->top];
    }
}

int main(void){
    
    StackType s,add;
    init_stack(&s);
    init_stack(&add);
    int i = 0;
    char str[MAX_SIZE];

    printf("정수를 입력하세요: ");
    scanf("%s",str);
    while(str[i] != NULL){
        if(str[i] != str[i+1]){
            push(&s,str[i]-'0');
        }
        i++;
        }
    while (!is_empty(&s)){
            push(&add,pop(&s));
        }
    printf("출력: ");
    while (!is_empty(&add)) {
		printf("%d", pop(&add));
	}
    
    printf("컴퓨터공학과 20203193 박준걸");
    return 0;
}