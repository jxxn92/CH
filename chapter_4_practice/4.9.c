#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAZE_SIZE 6

typedef struct{
    short r;
    short c; 
}element;

typedef struct{
    element data[MAX_SIZE];
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
void push(StackType *s,element item){
    if(is_full(s)){
        exit(1);
    }
    else{
        s -> data[++(s->top)] = item;

    }
}
element pop(StackType *s){
    if(is_empty(s)){
        exit(1);
    }
    else{
        return s -> data[(s -> top)--];
    }
}
element peek(StackType *s){
    if(is_empty(s)){
        exit(1);
        }
    else{
        return s->data[s->top];
    }
}

element here  = {1,0};
element entry = {1,0};

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'w','w','w','w','w','w'},
    {'e','0','w','0','0','w'},
    {'w','0','0','0','w','w'},
    {'w','0','w','0','w','w'},
    {'w','0','w','0','0','x'},
    {'w','w','w','w','w','w'}
};

void push_loc(StackType *s,int r,int c){
    if( r < 0 || c < 0) return;
    if (maze[r][c] != 'w' && maze[r][c] != '.'){
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s,tmp);
    }
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]){
    printf("\n");
    for(int r = 0 ; r < MAZE_SIZE ; r++){
        for(int c = 0; c < MAZE_SIZE; c++){
            printf("%c",maze[r][c]);
        }
        printf("\n");
    }
}

int main(void){
    
    int r,c;
    
    StackType s;
    init_stack(&s);

    here = entry;
    while ( maze[here.r][here.c] != 'x'){
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        maze_print(maze);
        push_loc(&s,r-1,c);
        push_loc(&s,r+1,c);
        push_loc(&s,r,c-1);
        push_loc(&s,r,c+1);
        
        if(is_empty(&s)){
            printf("실패");
        }
        else{
            here = pop(&s);
        }
    }
        printf("성공\n");


        printf("컴퓨터공학과 20203193 박준걸");
        return 0;


    }

