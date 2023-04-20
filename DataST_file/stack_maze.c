#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAZE_SIZE 6
#define MAX_SIZE 100

//typedef int element;

typedef struct
{
    short c;
    short r;
} element;

typedef struct{
    element data[MAX_SIZE];
    int top;
} StackType;

element here = {0,1} , entry ={0,1};

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
    if(is_empty(q)){
        exit(1);
    }
    else{
        return q->data[(q->top)--];
    }
}

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'}
};

/* int peek(StackType *q){
    if(is_empty(q)){
        exit(1);
    }
    else{
        return q->data[q->top];
    }
} */



void push_loc(StackType *q,int r, int c){
    if(r < 0 || c < 0 ) return;
    if(maze[r][c] != '1' && maze[r][c] != '.'){  // 지금 가려는 곳이 벽이거나 이미 다녀온 곳이 아닐 경우에 tmp 변수에 값을 저장후 스택에 삽입
        element tmp; 
        tmp.r = r;
        tmp.c = c;
        push(q,tmp);
    }
}

void print_maze(char maze[MAZE_SIZE][MAZE_SIZE]){
    printf("\n");
    for(int r = 0; r < MAZE_SIZE ; r++){
        for(int c = 0 ; c <MAZE_SIZE; c++){
            printf("%c",maze[r][c]);
        }
        printf("\n");
    }
}

int main(void){

    int r ,c ;
    StackType q;

    init_stack(&q);
    here = entry;

    while ((maze[here.r][here.c] != 'x')) //출구로 나갈때까지 반복하라
    {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        print_maze(maze);
        push_loc(&q,r-1,c);
        push_loc(&q,r+1,c);
        push_loc(&q,r,c-1);
        push_loc(&q,r,c+1);
        
        if(is_empty(&q)){
            printf("실패!\n");
            return 0;
        }
        else{
            here = pop(&q);
        }
    }

    printf("성공! \n");
    return 0;
    
}