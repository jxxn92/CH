#include <stdio.h>
#include <stdlib.h>
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

int check_matching(const char *in){
    StackType q;
    char ch,open_ch; //ch는 아래 처럼 받은 값을 하나하나 배열처럼 띄어서 저장할 변수 open_ch 는 pop한 리턴값을 저장할 변수
    int len = strlen(in); //받은 값의 길이를 저장하는 변수 len

    init_stack(&q);

    for(int i = 0; i < len ; i++){
        ch = in[i];
        switch(ch){
            case '(':
            case '[':
            case '{': 
                push(&q,ch);
                break;
            case ')':
            case ']':
            case '}':
                if(is_empty(&q)){
                    exit(1);
                }
                else{
                    open_ch = pop(&q);
                    if( (open_ch == '(' && ch != ')') ||
                        (open_ch == '{' && ch != '}') ||
                        (open_ch == '[' && ch != ']')){
                            return 0;
                        }
                        break;
                }
        }

    }
    if(!is_empty(&q)) return 0;
    return 1;
}
int main(void){

    char *p = "{ A[(i+1]) =0; }";
    if(check_matching(p) == 1){
        printf("%s 괄호 검사 성공",p);
    }
    else{
        printf("%s 괄호 검사 실패",p);
    }

    return 0;
    
}