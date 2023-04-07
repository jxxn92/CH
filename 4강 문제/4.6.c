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
int check_matching(const char *in){
    StackType s;
    char ch,open_ch; //ch는 한글자씩 떼서 저장할 변수 , open_ch는 pop()함수를 지나고 나서 조건 지나갈 때까지 임시 저장되는 변수
    int n = strlen(in);
    init_stack(&s);

    for(int i = 0; i < n ; i++){
        ch = in[i];
        switch(ch){
            case '(':
            case '{':
            case '[':
                push(&s,ch);
                break;
            case ')':
            case '}':
            case ']':
                if(is_empty(&s)){
                    return 0;
                    }
                else{
                    open_ch = pop(&s);
                    if( (open_ch == '(' && ch != ')')||
                        (open_ch == '{' && ch != '}')||
                        (open_ch == '[' && ch != ']'))    //조건문에서 '(' 나왔을때 ')' 아니라면 0을 반환한다. [자기 맞은편 꺽쇠가 아닐경우 0 반환]
                    {return 0;}
                    break;
                }
        }
    }
    if(!is_empty(&s)) return 0;
    else return 1;
}
int main(void){

    char *p = "{A[(i+1)]=0;}";

    if (check_matching(p)==1)
        printf("%s 괄호 검사 성공",p);
    else
        printf("%s 괄호 검사 실패",p);

    
    printf("컴퓨터공학과 20203193 박준걸");
    return 0;
}