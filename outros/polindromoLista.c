#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char str;
    struct No *next;
}No;

void push(No **top, char c){
    No *new = malloc(sizeof(No));
    new->str = c;

    if(new){
        if(*top == NULL){
            *top = new;
            new->next = NULL;
        }else{
            new->next = *top;
            *top  = new;
        }
    }
    printf("Inserido->%c\n", new->str);
}


char pop(No **top){
    No *rem = NULL;
    char c;

    if((*top)->next == NULL){
        rem = *top;
        *top = NULL;
        c = rem->str;
        free(rem);
        return c;
    }else{
        rem = *top;
        *top = rem->next;
        c = rem->str;
        free(rem);
        return c;
    }
}


int main(int argc, char const *argv[])
{
    No *top = NULL;
    char string[101], reverse[101];
    int  i = 0;

    scanf("%s", string);

    while(string[i] != '\0'){
        push(&top,string[i]);
        i++;
    }

    i = 0;
    while(top != NULL){
        reverse[i] = pop(&top);
        i++;
    }
    reverse[i] = '\0';

    if(strcmp(reverse,string) == 0){
        printf("É palindromo");
    }else{
        printf("Não é palindromo");
    }

    return 0;
}
