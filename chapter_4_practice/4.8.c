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

int prec(char op){
    switch(op){
        case '(' :
        case ')' :
            return 0;
        case '+' :
        case '-' :
            return 1;
        case '*' :
        case '/' :
            return 2;
    }
    return -1;
}

void infix_to_postfix(char exp[]){
    char ch, top_op;
    int len = strlen(exp);
    
    StackType s;
    init_stack(&s);

    for(int i = 0; i < len ; i++){
        ch = exp[i];
        switch(ch){
            case '+' : case '-' : case '*' : case '/' :
                while(!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
                    printf("%c",pop(&s));
                push(&s,ch);
                break;
            case '(' :
                push(&s,ch);
                break;
            case ')' :
                top_op = pop(&s);
                while(top_op != '('){
                    printf("%c",top_op);
                    top_op = pop(&s);
                }
                break;
            default:
                printf("%c",ch);
                break;
        }
    }
    while(!is_empty(&s)){
        printf("%c",pop(&s));
    }
}
int main(void){
    char *s = "(2+3)*4+9";
    printf("중위표시수식 %s\n",s);
    printf("후위표시수식 ");
    infix_to_postfix(s);
    printf("\n");

    
    printf("컴퓨터공학과 20203193 박준걸");

    return 0; 
}