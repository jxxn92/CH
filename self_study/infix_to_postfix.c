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

        switch(ch) //�������� ���
        { 
        case '+':
        case '-':
        case '*':
        case '/':
            while(!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) // ������ ��� ���� �ʰ� ���� ch�� �ִ� �����ڿ� peek���� ���ÿ� �ִ� �����ڸ� ���ؼ�
                printf("%c",pop(&s));                                    // ���ÿ� �����ִ� �����ڰ� �� Ŭ ��쿡�� ���ÿ� �ִ� �����ڸ� ����ϰ� ���� ch�� �ִ� �����ڸ� ���ÿ� �ִ´�.
            push(&s,ch);
            break;
        case '(':
            push(&s,ch);
            break;
        case ')':
            top_op = pop(&s);

            while(top_op != '('){ //���� ��ȣ ���� �� ���� ���ÿ� �ִ� �� ���
                printf("%c",top_op);
                top_op = pop(&s);
            }
            break;
        default:
            printf("%c",ch); // �ǿ�����(����)
            break;
        }   
    }
    while(!is_empty(&s)) //���ÿ� ���� ���� ������ ���
        printf("%c",pop(&s));
}

int main(void){

    char *s = "(2+3)*4+9";
    printf("����ǥ�ü��� %s \n",s);
    printf("����ǥ�ü���");
    infix_to_postfix(s);
    printf("\n");

    return 0;
}