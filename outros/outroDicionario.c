#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word {
    char str[101];
    struct word *next;
} word;

void insertWord(word **h, char str[101]){
    word *new = malloc(sizeof(word));
    word *aux = *h;

    strcpy(new->str,str);
    new->next = NULL;

    if(*h == NULL){
        *h = new;

    }else{
        if(strcmp(new->str,(*h)->str) < 0) {
            new->next = aux;
            (*h) = new;
            return;

        }else{
            while (aux->next && strcmp(str,aux->next->str) > 0)
                aux = aux->next;
            
            
            if(aux->next && !strcmp(aux->next->str, str)) {
                free(new);
                return;
            }
            

            new->next = aux->next;
            aux->next = new;
        }
    }
}

void removeWord(word **h, char str[101]){
   word *aux, *antes;
    aux = antes = (*h);

    if(!(*h))
        return;

    while(aux->next && strcmp(str, aux->str) != 0) {
        antes = aux;
        aux = aux->next;
    }

    if(!strcmp(str, aux->str)) {
        if(aux == (*h))
            (*h) = aux->next;
        else
            antes->next = aux->next;

        free(aux);
    }
}


void showList(word **h, char str[101]){
    word *aux = *h;

    while(aux && strcmp(str, aux->str) > 0)
         aux = aux->next;

    if(aux == NULL) {
        printf("NULL\n");
        return;
    }else{
        while(aux) {
            printf("%s ", aux->str);
            aux = aux->next;
        }
    }

    printf("\n");


}


void Clear(word **h){
    word *aux;

    while(aux) {
        aux = *h;
        *h = (*h)->next;
        free(aux);
    }
}


int main(int argc, char const *argv[])
{
    word *head = NULL;
    int n, m, i, op;
    char str[101];

    scanf("%d %d", &n, &m);

    for(i = 0; i< n ; i++){
        scanf(" %s", str);
        insertWord(&head,str);
    }

    for(i = 0; i < m; i++) {
        scanf(" %d", &op);

        if(op == 0){
            scanf(" %s", str);
            removeWord(&head, str);

        }else if(op == 1){
            scanf(" %s", str);
            insertWord(&head, str);

        }else{
            scanf(" %s", str);
            showList(&head, str);

        }
    }

    //Clear(&head);

    return 0;
}
