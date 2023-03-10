#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
        int age, arrive;
        struct Fila *next;
} Fila;

void addMain(Fila **aux, Fila **start, Fila **end){
        Fila *now = *start, *prev = *start, *temp = *aux;
        (*aux) = (*aux)->next;

        if(!(*start)) {
                *start = *end = temp;
                temp->next = NULL;
                return;
        }

        if(temp->age > 59) {
                prev = now;
                now = now->next;
                while(now && temp->age < now->age) {
                        prev = now;
                        now = now->next;
                }
                
                if(now == NULL)
                        *end = temp;

                temp->next = prev->next;
                prev->next = temp;

        }else {
                (*end)->next = temp;
                temp->next = NULL;
                (*end) = temp;
        }
}

void addAux(Fila **start){
        Fila *new = malloc(sizeof(Fila));
        Fila *current = *start, *prev = *start;

        scanf("%d %d", &new->age, &new->arrive);

        if(!(*start)) {
                *start = new;
                return;
        }

        while(current && (new->arrive > current->arrive || (new->arrive == current->arrive && new->age <= 59))) {
                prev = current;
                current = current->next; 
        }

        if(current == *start) {
                new->next = prev;
                *start = new;
                return;
        }

        new->next = prev->next;
        prev->next = new;
}

void Remove(Fila **head, int *total_time, int time, Fila *temp){
        Fila *aux;

        while(*head != NULL && time >= *total_time) {
                aux = *head;
                *head = (*head)->next;
                free(aux);

                if((*head) != NULL) {
                        if((*head)->arrive < *total_time){
                                *total_time += 3;
                        }else{
                                *total_time = (*head)->arrive + 3;
                        }

                }else{
                        if(temp->arrive < *total_time){
                                *total_time += 3;
                        }else{
                                *total_time = temp->arrive + 3;
                        }
                }
        }
}

void show(Fila *start){
        while(start) {
                printf("%d ", start->age);
                start = start->next;
        }
        printf("\n");
}

void Clear(Fila *target){
        Fila *aux;

        while(target) {
                aux = target;
                target = target->next;
                free(aux);
        }
}

int main(int argc, char const *argv[]){
        Fila *aux = NULL;
        Fila *head = NULL, *tail = NULL;
        int n, i, curr, sum = 0;

        scanf("%d", &n);

        for(i = 0; i < n; i++)
                addAux(&aux);

        sum = aux->arrive + 3;
        while(aux) {
                curr = aux->arrive;
                
                while(aux && aux->arrive == curr) {
                        Remove(&head, &sum, curr, aux);
                        addMain(&aux, &head, &tail);
                }
                show(head);
        }

        Clear(head);
        Clear(aux);

        return 0;
}
