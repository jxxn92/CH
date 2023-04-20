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

int eval(char exp[]){
    int op1,op2,value;
    char ch;
    int len = strlen(exp);
    StackType q;

    init_stack(&q);

    for(int i = 0 ; i < len ; i++){
        ch = exp[i];
        if(ch != '+' && ch != '-' && ch != '*' && ch != '/'){
            value = ch - '0';
            push(&q,value);
        }
        else{
            op2 = pop(&q);
            op1 = pop(&q);
            switch (ch)
            {
            case '+':
                push(&q,op1 + op2);
                break;
            case '-':
                push(&q,op1 - op2);
                break;
            case '*':
                push(&q,op1 * op2);
                break;
            case '/':
                push(&q,op1 / op2);
                break;
            }
        }
    }
    return pop(&q);

}
int main(void){

    int result;
    printf("후위 표기식은 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("결과 값은 %d\n",result);
    return 0;
    
}