#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct GraphType{
    int n;
    int adj_mat[MAX_SIZE][MAX_SIZE];
} GraphType;

void init(GraphType* g){
    g -> n = 0;
    int r,c;
    for(r = 0; r <MAX_SIZE; r++){
        for(c = 0; c < MAX_SIZE ; c++){
            g->adj_mat[r][c] = 0;
        }
    }
}

void insert_vertex(GraphType* g, int v){
    if(((g->n)+1) > MAX_SIZE){
        fprintf(stderr,"error");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int start , int end){
    if(start >= g->n || end >= g->n){
        fprintf(stderr,"Error");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void print_adj_mat(GraphType*g){
    for(int i  = 0 ; i < g->n; i++){
        for(int j = 0; j < g->n; j++){
            printf("%2d ",g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

void main(){

    GraphType* g;
    g = (GraphType *)malloc(sizeof(GraphType));

    init(g);
    for(int i = 0 ; i < 5 ; i++){
        insert_vertex(g,i);
    }
    insert_edge(g,0,1);    
    insert_edge(g,0,2);
    insert_edge(g,0,3);
}