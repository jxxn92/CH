#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef char element;

typedef struct
{
    element data[MAX_SIZE];
    int top;
}StackType;

void init_stack(StackType *s){
    s -> top = -1;
}

int is_empty(StackType* s){
    return (s -> top == -1);
}

int is_full(StackType* s){
    return (s -> top == (MAX_SIZE - 1));
}

void push(StackType* s,element item){
    if(is_full(s)){
        fprintf(stderr,"error");
        exit(1); 
    }
    else s->data[++(s -> top)] = item;
}

element pop(StackType* s){
    if (is_empty(s))
    {
        fprintf(stderr,"error");
        exit(1);
    }
    else{
        return(s->data[(s->top)--]);
    }
}

element peek(StackType* s){
    if(is_empty(s)){
        fprintf(stderr,"error");
        exit(1);
    }
    else{
        return(s->data[s->top]);
    }
}


int prec(char op){
    switch (op)
    {
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

void infix_to_postfix(char exp[]){
    int len = strlen(exp);
    char ch , top_op;
    StackType s;

    init_stack(&s);

    for(int i = 0 ; i < len; i ++){
        ch = exp[i];

        switch(ch) //연산자일 경우
        { 
        case '+':
        case '-':
        case '*':
        case '/':
            while(!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) // 스택이 비어 있지 않고 현재 ch에 있는 연산자와 peek으로 스택에 있는 연산자를 비교해서
                printf("%c",pop(&s));                                    // 스택에 남아있는 연산자가 더 클 경우에는 스택에 있는 연산자를 출력하고 현재 ch에 있는 연산자를 스택에 넣는다.
            push(&s,ch);
            break;
        case '(':
            push(&s,ch);
            break;
        case ')':
            top_op = pop(&s);

            while(top_op != '('){ //왼쪽 괄호 만날 때 까지 스택에 있는 값 출력
                printf("%c",top_op);
                top_op = pop(&s);
            }
            break;
        default:
            printf("%c",ch); // 피연산자(숫자)
            break;
        }   
    }
    while(!is_empty(&s)) //스택에 남은 값이 없도록 출력
        printf("%c",pop(&s));
}

int main(void){

    char *s = "(2+3)*4+9";
    printf("중위표시수식 %s \n",s);
    printf("후위표시수식");
    infix_to_postfix(s);
    printf("\n");

    return 0;
}