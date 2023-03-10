#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No{
    char str[100];
    struct No *next;
}No;

typedef struct Lista{
    No *head;
    int size;
}Lista;


void CreateList(Lista *l){ //cria a lista
    l->head = NULL;
    l->size = 0;
}

//nao deve repitir
void InsertList(Lista *l, char str[]){
    No *new = malloc(sizeof(No));
    No *aux;

    strcpy(new->str,str);

    if(l->head == NULL){ //ise nao houver elementos
        l->head = new;
        new->next = NULL;

    }else if(strcmp(str,l->head->str) < 0 && strcmp(str,l->head->str) != 0){ //se a head for um valor maior
        new->next = l->head;
        l->head = new;

    }else{
        aux = l->head; //defino como head para começar o loop por aqui
        while(aux->next && strcmp(str,aux->next->str) >= 0){ //loop pra verificar se o valor é menor a algum ou se chegamos ao fim
            aux = aux->next;
        }

        if(strcmp(aux->str, str) != 0){ //se nao for repetido
            new->next = aux->next;
            aux->next = new;
        }else{
            l->size--;
        }
    }

    l->size++;    
}


void PrintL(Lista *l){
    No *aux = l->head;

    if(l->head != NULL){  //se nao nuLL
        while(aux){ //loop pela lista
            printf("%s ", aux->str);       
            aux = aux->next;
        }

        printf("\n");
    }
}

void RemoveList(Lista *l, char str[]){
    No *aux = l->head; //nao preciso alocar denovo, so pegar o ja criado
    No *temp;
    char aux_str[100];

    if(l->head == NULL || l->size <= 0){
        printf("NULL\n");

    }else if(strcmp(str, l->head->str) == 0){ //se o valor for a head
        if(l->head->next == NULL){ //se for o unico elemento
            l->head = NULL; 
            printf("NULL\n");

        }else{
            temp = l->head->next; //se tiver algo ainda na lista
            l->head = temp;

        }
        l->size--;

    }else{
        while(aux->next && strcmp(str,aux->next->str) != 0){ //anda pela lista
            aux = aux->next;
        }
        if(aux->next){  //se nao NULL
            temp = aux->next;
            aux->next = temp->next; //troca
            free(temp);
            l->size--; //reduz
        }
    }

}


int main(int argc, char const *argv[])
{
    Lista l;
    int str_num, op_num, i, op;
    char str[100];

    scanf("%d", &str_num);
    scanf("%d", &op_num);

    CreateList(&l);

    for(i=0;i<str_num;i++){
        scanf(" %s",str);
        InsertList(&l,str);
    }
    //PrintL(&l);

    for(i=0; i< op_num; i++){
        scanf(" %d", &op);
        scanf(" %s", str);

        if(op == 1){
            InsertList(&l,str);
            //PrintL(&l);

        }else if(op == 0){
            RemoveList(&l,str);
            PrintL(&l);

        }
    }
  
    return 0;
}
