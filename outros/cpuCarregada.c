#include <stdio.h>
#include <stdlib.h>

int completed = 0;

typedef struct No{
    int tstart;
    int tcost;
    struct No *next;
}No;

typedef struct List{
    int size;
    No *head;
}List;

void CreateList(List *l){ //cria a lista
    l->head = NULL;
    l->size = 0;
}

void InsertList(List *l, int time_start, int time_cost){
    No *new = malloc(sizeof(No));
    No *aux;

    new->tstart = time_start;
    new->tcost = time_cost;

    if(l->head == NULL){ //se n houver elementos
        new->next = NULL;
        l->head = new;
        

    }else if(time_start < l->head->tstart){ //se o valor for menor que o head
        new->next = l->head;
        l->head = new;

    
    }else{  //se estiver no meio ou fim
        aux = l->head;
        while (aux->next && time_start > aux->next->tstart){
            aux = aux->next;
        }
        new->next = aux->next;
        aux->next = new;

        
    }

    l->size++;

}

void PrintL(List *l){
    No *aux = l->head;

    if(l->head != NULL){  //se nao nuLL
        while(aux){ //loop pela lista
            printf("%d ", aux->tstart);       
            aux = aux->next;
        }

        printf("\n");
    }
}

void RealizeProcess(List *l, int *act_time){
    No *aux = l->head;
    No *temp = NULL;
    int val[100] = {0}, i, maior = 0;

    if(l->head){
        if(*act_time < aux->tstart){ //se for menor que o primeiro tempo
            printf("%d", aux->tcost);
            *act_time += aux->tcost;

            if(aux->next){
                temp = aux;
                aux = temp->next;
                free(temp);
            }else{
                l->head = NULL;
                completed = 1;
            }
            l->size--;
            return;

        }else{ //se estiver depois do meio
            i = 0;
            while(aux){
                if(aux->tstart <= *act_time){ //verifica quais sao menores que o tempo
                    val[i] = aux->tcost;
                    //printf(" i%d ", val[i]);
                    i++;
                }         
                aux = aux->next;
            }

            i = 0;
            maior = val[0]; //checa qual valor é o maior
            while(val[i+1] != 0){
                if(val[i] > val[i+1]){
                    maior = val[i];
                }else{
                    maior = val[i+1];
                }
                i++;
            }

            if(l->head->tcost == maior){ //se o valor for a head
                printf("rx%d ", l->head->tcost);
                *act_time += l->head->tcost;

                if(l->head->next){
                    temp = l->head;
                    l->head = temp->next;
                    //free(temp);
                }else{
                    l->head = NULL;
                    completed = 1;
                }

                l->size--;
                return;

            }else{
                aux = l->head;
                while(aux->next && aux->next->tcost != maior){             
                    aux = aux->next;
                }

                printf("r%d ", aux->next->tcost);
                *act_time += aux->next->tcost;

                if(aux->next){
                    temp = aux->next;
                    aux->next = temp->next;
                    //free(temp);

                }else{
                    aux = NULL; //entao é a tail
                }

                l->size--;   
            }       
        }
    }
}


int main(int argc, char const *argv[])
{
    List l;
    int num, i, cost, time, act_time = 0;

    CreateList(&l);

    scanf(" %d", &num);

    for(i = 0; i < num; i++){
        scanf(" %d", &time);
        scanf(" %d", &cost);
        InsertList(&l, time, cost);
    }

    PrintL(&l);
    while(completed == 0){
        RealizeProcess(&l, &act_time);
    }


    //printf("\n %d", act_time);
    
    return 0;
}
