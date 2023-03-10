#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binary_search(int *arr, int left, int right, int target){
    int half;

    if(arr[left] == target) return left;
    if(arr[right] == target) return right;

    while(right >= left){
        half = (left + right) / 2;

        if(arr[half] == target) return half;
        if(arr[half] > target)  right = half - 1;
        else if(arr[half] < target)  left = half + 1;
    }

    return -1;
}


void insertionSort(int arr[], int n){
    //compara com os posteriores para ordenar
    int i, j, aux;

    for(i = 1; i <= n; i++){ //começa no segundo
        aux = arr[i]; //menor valor
        j = i;

        while(j > 0 && arr[j-1] > aux){
            arr[j] = arr[j-1];
             j--;
        }
        
        arr[j] = aux;
    }
}

void selectionSort(int arr[], int n){
    //vai buscando o menor
    int i,j,aux,menor;

    for(i = 0; i < n; i++){
        menor = i;
        for(j = i+1; j < n; j++){ //i+1 pois estamos comparando o i
            if(arr[j] < arr[menor])
                menor = j;
        }

        if(i != menor){
            aux = arr[i];
            arr[i] = arr[menor];
            arr[menor] = aux;
        }
    }
}

void merge(int *arr, int start, int meio, int end){
    int *temp, p1, p2, size, end1 = 0, end2 = 0;
    int i,j,k;

    size = end - start+1;
    p1 = start;
    p2 = meio+1;
    temp = malloc(size*sizeof(int)); //usamos um array auxiliar

    if(temp != NULL){
        for(i = 0; i < size; i++){
            if(!end1 && !end2){ //combina ordenado
                if(arr[p1] < arr[p2])
                    temp[i] = arr[p1++]; //incremento direto nas pos.
                else
                    temp[i] = arr[p2++]; 

                if(p1 > meio) end1=1; //verifica se acabaram os vetores
                if(p2 > end)  end2=1;

            }else{
                if(!end1)  //copia oq sobrou
                    temp[i] = arr[p1++];
                else
                    temp[i] = arr[p2++];
            }
        }

        for(j = 0, k = start; j < size; j++, k++) //copia do temp para o original
            arr[k] = temp[j];

        free(temp);

    }

}
void mergeSort(int arr[], int start, int end){
    //dividir e conquistar ->divisao do vetor no meio ->combinaçao dos ordenados
    int meio;

    if(start < end){
        meio = floor((start+end)/2); //media redonda
        mergeSort(arr,start,meio);
        mergeSort(arr,meio+1,end); //meio+1 ,pois ja ordenamos o "meio"

        merge(arr,start,meio,end); //funde as partes
    }


}

int partition(int arr[], int esq, int dir){
    int pivo = dir;
    int pos = esq; //ponto de troca para o elem maior
    int i, aux;

    for(i = esq; i < dir; i++){ //i < dir pois dir é pivo
        if(arr[i] <= arr[pivo]){ //troca o valor se menor
            //pos++;
            aux = arr[pos];
            arr[pos] = arr[i];
            arr[i] = aux;
            pos++; //avanço para quando trocar novamente ser colocado na frente do ja ordenado
            
        }
    }

    //troca o pivo com o maior elemento de pos
    aux = arr[pivo];
    arr[pivo] = arr[pos];
    arr[pos] = aux;

    return pos; //retorna o novo pivo

    //---------------OBS:------------------//
    //caso queira utilizar o pivo como esq
    //troque i = esq+1, i <= dir(se nao sai do arr)
    //troque pos++; na frente dos outros no if()

}

void quickSort(int arr[], int esq, int dir){
    int pos;

    if(esq<dir){
        pos = partition(arr,esq,dir); //organiza e devolve o pivo entre os maiores/menores
        quickSort(arr,esq,pos-1); //menores
        quickSort(arr,pos+1,dir); //maiores
    }

}

void quickSortFacil(int arr[],int esq, int dir){
    int pivot = arr[esq]; //ponto de referencia ->caso pivot seja a esq é so trocar aqui direto
    int l = esq, r = dir;
    int aux; //segura o valor do
    
    while(l <= r){
        while(arr[l] < pivot) l++; //anda até achar um valor maior
        while(arr[r] > pivot) r--; //anda até achar um valor menor, mas de forma oposta 
        //para decrescente inverta os < e > do while acima

        //OBS: no do aleardo quando l = r ele troca o pivo e separa os vetores -> mais eficiente

        if(l <= r){
            aux = arr[r];  //troca
            arr[r] = arr[l];
            arr[l] = aux;
            l++;  //anda mais um passo
            r--;
        }
    }
    if(esq < r) quickSortFacil(arr,esq,r); //repete o processo com os dois vetores resultante
    if(l < dir) quickSortFacil(arr,l, dir);
}

void shellSort(int arr[], int n){
    int i,j,k, valor;

    k = 1;
    while(k < n/2) k *= 2; //k = 3*k + 1; //calculando passo inicial ->ex 10/2 -> k =8;

    while( k != 1){
        k = k/2; //acertando o passo para iteraçao atual

        for(i = k; i < n; i++){ //algoritimo de insertion adaptado
            valor = arr[i];
            j=i;

            while(j >= k && arr[j-k] > valor){
                arr[j] = arr[j-k];
                j = j-k;
                
            }

            arr[j] = valor; //devolve o valor de teste
            
        }
        
    }
    return;
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,4,3,2,1,10,9,8,7,6};
    int size = sizeof(arr) / sizeof(int);
    int i;

    //mergeSort(arr,0,size);
    //quickSortFacil(arr,0,size-1); //lembra do -1
    shellSort(arr,size);
    //insertionSort(arr,size-1);

    for(i = 0; i < size; i++ )
        printf("%d ", arr[i]);
    printf("\n");


    return 0;
}
