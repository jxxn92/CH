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

int eval(char exp[]){
    int op1, op2, value = 0; //op1,op2 는 pop()한걸 임시 저장하는 변수 value 같은 경우에는 ch와 연산자 구분 하는 중에서 연산자가 아닌 피연산자이면 value에 저장
    int len = strlen(exp);
    char ch;

    StackType s;
    init_stack(&s);
    
    for (int i = 0; i < len ; i++){
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/'){
            value = ch - '0';  //예를 들어 ch가 '3'이라면, '3'의 ASCII 코드 값인 51에서 '0'의 ASCII 코드 값인 48을 빼면 3이 된다.
            push(&s,value);
        }
        else {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch){
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
            }

        }
    }
    return pop(&s);
}
int main(void){

    int result;
    printf("후위표기식은 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("결과값은 %d\n",result);

    
    printf("컴퓨터공학과 20203193 박준걸");

    return 0;

}