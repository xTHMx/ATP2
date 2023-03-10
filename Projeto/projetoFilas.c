#include <stdio.h>
#include <stdlib.h>

//======================================== Funcoes =========================================================================// 

typedef struct Elemento{ //itens e suas propriedades
    int i, o, c; //i-identificaçao o-tempo de chegada c-custo de tempo
    struct Elemento *next;
}Elem;

typedef struct Fila{ //fila do caixa
    int tempo;
    Elem *first;
}Fila;

void createFila(Fila *f){
    f->first = NULL;
    f->tempo = 0;
}

void insertItem(Fila *f, int id, int o, int c, Fila *faux){ //fila com prioridade
    Elem *new = malloc(sizeof(Elem));
    Elem *aux;
    int stop = 0;
    
    if(id != 0){ //nao é transferencia de fila ->definida por id que tem que ser >0
        new->i = id;
        new->o = o;
        new->c = c;  
    }else{           //é tranferencia de fila
        aux = faux->first;
        new->i = aux->i;
        new->o = aux->o;
        new->c = aux->c; 
        if(aux)
            faux->first = aux->next;
        free(aux);
    }
    new->next = NULL;  
    
    if(f->tempo < new->o) // se o item chegara mais tarde
                f->tempo = new->o; //incremento o tempo de espera
    f->tempo += new->c; //incrementa tempo de processo

    if(f->first == NULL){ //se fila vazia
        f->first = new;

    }else{ 
        if(f->first->o > new->o){ //prioridade no inicio por tempo de chegada
            new->next = f->first;
            f->first = new;

        }else if(f->first->o == new->o  && new->i < f->first->i ){//se for igual e o novo é menor -> prioridade de posiçao    
            new->next = f->first;
            f->first = new;

        }else{                           //valor n é no inicio
            aux = f->first;
            while(aux->next && new->o > aux->next->o) //loop pela lista
                aux = aux->next;

            if(aux->next && new->o == aux->next->o){ //loop pelos valores iguais -> prioridade de posiçao
                while(aux->next && new->i > aux->next->i) 
                    aux = aux->next;
            }

            new->next = aux->next;
            aux->next = new;      
        
        }   
    //printf("inserido ");
    }
}

void clearFila(Fila *f){ // limpa a fila
    Elem *rem = NULL;
    
    if(f->first){
        while(f->first){
            rem = f->first;
                
            if(f->first->next) //se houver mais elementos na fila
                f->first = rem->next;
            else              //ultimo
                f->first = NULL;

            free(rem);  //remove o item
        }
    }
}

//======================================== Principal =========================================================================// 

int main(int argc, char const *argv[])
{
    int n, m , i, j, menor, id, o, c; //n-elementos, m-processadores
    Fila centros[10];
    Fila aux; //ordena os itens para passar ás filas

    scanf("%d %d", &n, &m);

    for(i = 0; i < m; i++) //cria as filas
        createFila(&centros[i]);
    createFila(&aux); //cria fila de itens
    
    for(i = 0; i < n; i++){
        scanf(" %d %d %d", &id,&o,&c);
        insertItem(&aux,id,o,c, &aux); //ordena os itens em uma fila
    }
    
    for(i = 0; i < n; i++){ //insere na menor fila
        menor = 0;
        
        for(j = 0; j < m; j++){ //loop pelas filas para ver qual a menor
            if(centros[menor].tempo > centros[j].tempo)
                menor = j;
        }
        
        insertItem(&centros[menor],0,0,0, &aux); //insere o item da fila aux na menor fila
    }

    printf("\n");
    for(i = 0; i < m; i++){
        clearFila(&centros[i]); //limpa a fila -> ja temos o tempo final       
        printf("%d ", centros[i].tempo); //tempo que a fila levou pra terminar

    }

    return 0;
}
