#include <stdlib.h>
#include <stdio.h>
#define MAX 2

typedef struct Pilha
{
    char item;
    int top;
}Tpilha;

void Pilha_start(Tpilha *p){
    p->top = -1;
}

int Pilha_vazia(Tpilha *p){
    if(p->top == -1){
        return 1;  
    }else{
        return 0;
    }
}


void Pilha_insert(Tpilha *p, int a){
    if(p->top != MAX-1){ //se nao estiver cheia
        p->top++;

    }
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
