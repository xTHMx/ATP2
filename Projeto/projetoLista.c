#include <stdio.h>
#include <stdlib.h>

//===========================================================Structs==========================================================//

typedef struct No
{
    int i,k,o;
    struct No *next;
}No;


typedef struct Circular
{
    No *start, *end;
    int size;
}Circular;

//===========================================================Funçoes==========================================================//

void createList(Circular *list){ //inicializa os valores
    list->start = NULL;
    list->end = NULL;
    list->size = 0;
}

void list_insert(Circular *list, int val, int op, No *reinsert){ //insere os valores na lista
    No *aux, *new = malloc(sizeof(No));

    if(new){
        list->size++; //incrementa tamanho
        if(reinsert == NULL){
            new->i = list->size;
            new->k = val;
            new->o = op;
            
            if(list->start == NULL){ //inicio
                new->next = new; //aponta pra ele mesmo
                list->start = new;
                list->end = new;
                
            }else{   //meio
                aux = list->start;//comeca do inicio
                while(aux->next != list->start)
                    aux = aux->next;
                
                if(aux->next == list->start){ //se é final da lista
                    list->end->next = new; //antigo end aponta pra new
                    list->end = new;       //new se torna novo end
                    new->next = list->start; //liga end-start
                    
                }else{
                   new->next = aux->next; //troca
                    aux->next = new; 
                }
            }
            
        }else{
            new->i = reinsert->i; 
            new->k = reinsert->k;
            new->o = 0;
            
            //val sera usado como comparaçao de posiçao nessa parte do codigo
        
            
            if(list->start == NULL){ //inicio
                new->next = new; //aponta pra ele mesmo
                list->start = new;
                list->end = new;
    
            }else if(val < list->start->i){ //menor que inicio
                new->next = list->start;
                list->start = new;
                list->end->next = list->start; //religo ao novo start
    
            }else{   //meio
                aux = list->start;//comeca do inicio
                while(aux->next != list->start && val > aux->next->i){ //roda até que encontre um valor maior que aux ou caso seja o final
                    aux = aux->next;
                }
                
                if(aux->next == list->start){ //se é final da lista
                    list->end->next = new; //antigo end aponta pra new
                    list->end = new;       //new se torna novo end
                    new->next = list->start; //liga end-start
                    
                }else{
                   new->next = aux->next; //troca
                    aux->next = new; 
                }
            }
        }
    }
}

No* list_remove(Circular *list, int id){ //remove elemento
    No *aux, *rem = NULL;

    if(list->size != 0){ //se existe 
        if(list->start == list->end && list->start->k == id){ //se lista tem 1 elem.
             /* rem = list->start;
            list->start = NULL;
            list->end = NULL;
            list->size--; */
            
            list->size--;
            free(list->start);
            return NULL;           //ultimo valor, para loop
            
        }else if(list->start->i == id){ //se valor for o start
            rem = list->start;
            list->start = rem->next;
            list->end->next = list->start; //revinculei ao start novo
            list->size--;
            
        }else{
            aux = list->start;
            while(aux->next != list->start && aux->next->i != id) //loop pela list
                aux = aux->next;

            if(aux->next == list->end){ //se é o end
                list->end = aux;       //redefine novo end 
            }
                
            rem = aux->next;        //salva o removido
            aux->next = rem->next; 
                
            list->size--;
            
        }
        return rem;
        
    }
    
    return NULL; //falhou
}

void list_show(Circular *list){ //nao necessario no programa -> debug
    int i = 0;
    No *aux;
    
    aux = list->start;
    do{
        printf("%d ", aux->i);
        aux = aux->next;
        i++;
    }while(aux->next != list->start);
    

}

void list_update(Circular *list){ //realiza o processo principal
    int m = list->size, n, op, val;
    No *aux = list->start;
    No *rem = NULL, *temp;
    
    op = aux->o; //começo pelo primeiro elemento
    val = aux->k;

    while(list->size > 1){ //loop até sobrar um valor
        if(op == 1){
            
            list_insert(list,rem->i,0,rem); //insere o elemento novamente
            temp = list_remove(list,temp->i); //removo o elem que estou
            
            aux = temp->next; //começo do proximo
            for(n = 1; n < temp->k; n++){ //loop de k do elem anterior
                aux = aux->next;
            }

            rem = temp;
            op = 0; //ira remover o que ele parar
            val = 0; //loop já feito
            
        }else{
            temp = aux;
            for(n = 1; n < val; n++){//loopar pelo valor
                temp = temp->next;
            }
            
            if(temp->o != 1 ){ // se proximo for remoçao salve o removido
                if(rem) //apaga o rem anterior da memoria
                    free(rem);

                rem = list_remove(list,temp->i);
                
                aux = rem->next; //passe pro proximo e realize a operaçao anterior
                op = rem->o;
                val = rem->k;
                
            }else{   //deixo pra remover na op == 1
                op = temp->o;
                
            }

        }
        
    }
    
    printf("%d\n", list->start->i); //valor final
    
}


//===========================================================Principal==========================================================//
int main(int argc, char const *argv[])
{
    int n, k, o, i; //variaveis
    Circular list;

    createList(&list); //cria a lista(inicializa)

    scanf("%d", &n); //n° de valores

    for(i = 0; i < n; i++){ //scan de todos os valores da lista
        scanf(" %d %d", &k, &o);
        list_insert(&list,k,o,NULL);
    }

    list_update(&list); //processo Principal

    return 0;
}
