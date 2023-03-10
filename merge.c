#include <stdlib.h>
#include <stdio.h>



void merge(int *arr, int esq, int meio, int dir){
    int *aux, i,j,k;
    i = esq; 
    j = meio; 
    k = 0;

    aux = malloc((dir-esq)*sizeof(int));

    while(i < meio && j < dir){
        if(arr[i] <= arr[j]){ //insere ordenado
            aux[k++] = arr[i++]; //menor para esquerda

        }else{
            aux[k++] =arr[j++];//maior para direita

        }
    }

    while(i < meio)  //copia oq sobrou
        aux[k++] = arr[i++];

    while (j < dir)  //copia oq sobrou
        aux[k++] = arr[j++];
    
    for(i = esq; i < dir; i++) //passa para o array original
        arr[i] = aux[i-esq];

    free(aux);

}


void mergeSort(int *arr, int esq, int dir){
    if(esq < dir-1){
        int meio = (dir+esq)/2;
        mergeSort(arr,esq,meio);
        mergeSort(arr,meio,dir);
        merge(arr,esq,meio,dir);
    }
}


int main(int argc, char const *argv[])
{
    int arr[] = {4,2,3,1,5,7,6,8,10,9};

    mergeSort(arr,0,10);

    int i = 0;
    while(i < 10){
        printf("%d ", arr[i++]);
    }

    return 0;
}
