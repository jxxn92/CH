#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define MAZE_SIZE 6

typedef struct {
    short r;
    short c;

}element;

typedef struct
{
    element data[MAX_SIZE];
    int top;
}StackType;

element here = {1,0};
element entry = {1,0};

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

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'},
};

void push_loc(StackType* s, short r, short c){
    if(r < 0 || c < 0) return;
    if(maze[r][c] != '1' && maze[r][c] != '.'){
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s,tmp);
    }
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]){
    printf("\n");
    for(int r = 0; r < MAZE_SIZE ; r++){
        for(int c = 0 ; c <MAZE_SIZE; c++){
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
    while (maze[here.r][here.c] != 'x'){
        r = here.r;
        c = here.c;
        maze[r][c] = '.';

        maze_print(maze);

        push_loc(&s, r - 1 , c);
        push_loc(&s, r + 1 , c);
        push_loc(&s, r , c - 1);
        push_loc(&s, r , c + 1);
        
        if(is_empty(&s)){
            printf("����");
            exit(1);
        }
        else {
            here = pop(&s);
        }
    }
        printf("����");
        return 0;
}