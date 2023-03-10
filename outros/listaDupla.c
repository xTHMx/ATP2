#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char str[40];
    struct No *next, *prev;
}No;

void insereList(No **head, char word[]){
    No *new = malloc(sizeof(No));
    No *aux;

    strcpy(new->str,word);

    if(new){
        if(*head == NULL){
            *head = new;
            new->next = NULL;
            new->prev = NULL;

        }else if(strcmp(word, (*head)->str) < 0){
            new->next = *head;
            (*head)->prev = new;
            new->prev = NULL;
            *head = new;

        }else{
            aux = *head;
            while(aux->next && strcmp(word,aux->next->str) > 0)
                aux = aux->next;
                   
            if(aux->next){
                new->next = aux->next;
                aux->next->prev = new;
            }else{
                new->next = NULL;
            }
            new->prev = aux;
            aux->next = new;

        }
    }

}

void printList(No **head){
    No *aux = *head;

    if(*head){
        printf("%s ", aux->str);
        while(aux->next){
            aux = aux->next;
            printf("%s ", aux->str);
        }
        printf("\n");

    }else{
        printf("NULL\n");
    }

}

void removeList(No **head, char word[]){
    No *rem = NULL, *aux;

    if(*head){
        if((*head)->next == NULL && strcmp(word, (*head)->str) == 0){
            free(*head);
            *head = NULL;

        }else if(strcmp(word, (*head)->str) == 0){
            rem = *head;
            rem->next->prev = NULL;
            *head = rem->next;
            free(rem);
        }else{
            aux = *head;
            while(aux->next && strcmp(word,aux->next->str) != 0)
                aux = aux->next;

            rem = aux->next;
            aux->next = NULL;
            rem->prev = aux;
            if(rem->next){
                rem->next->prev = aux;
                aux->next = rem->next;
            }

            free(rem);
        }
    }
}

int main(int argc, char const *argv[])
{
    No *head = NULL;

    insereList(&head, "teste");
    insereList(&head, "aaa");
    insereList(&head, "butter");
    insereList(&head, "zeta");
    insereList(&head, "zoca");

    //removeList(&head, "teste");
    //removeList(&head, "aaa");
    removeList(&head, "butter");
    //removeList(&head, "zeta");
    removeList(&head, "zoca");

    printList(&head);

    return 0;
}
