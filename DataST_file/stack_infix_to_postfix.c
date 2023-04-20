#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef char element;

typedef struct{
    element data[MAX_SIZE];
    int top;
} StackType;

void init_stack(StackType *q){
    q-> top = -1;
}

int is_empty(StackType *q){
    return (q -> top == -1);
}

int is_full(StackType *q){
    return (q->top == MAX_SIZE-1);
}

void push(StackType *q, element item){
    if(is_full(q)){
        exit(1);
    }
    else{
        q->data[++(q->top)] = item;
    }
}
element pop(StackType *q){
    int tmp;
    if(is_empty(q)){
        exit(1);
    }
    else{
        tmp = q->data[(q->top)--];
    }
    return tmp;
}

int peek(StackType *q){
    int tmp;
    if(is_empty(q)){
        exit(1);
    }
    else{
        tmp = q->data[q->top];
    }
    return tmp;
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
    char ch , top_op;
    int len = strlen(exp);
    StackType q;

    init_stack(&q);

    for(int i = 0 ; i < len ; i++){
        ch = exp[i];
        
        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            while(!is_empty(&q) && (prec(ch) <= prec(peek(&q)))){
                printf("%c",pop(&q));
            }
            push(&q,ch);
            break;
        case '(':
            push(&q,ch);
            break;
        case ')':
            top_op = pop(&q);

            while(top_op != '('){
                printf("%c",top_op);
                top_op = pop(&q);
            }
            break;
        default:
            printf("%c",ch);
            break;
        }
    }
    while(!is_empty(&q)){
        printf("%c",pop(&q));
    }
}
int main(void){

    char *s = "(2+3)*4+9";
    printf("중위표기수식 %s \n",s);
    printf("후위표기수식");
    infix_to_postfix(s);
    printf("\n");

    return 0;
    
}