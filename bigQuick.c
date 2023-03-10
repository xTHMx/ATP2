#include <stdio.h>
#define max 200000

//==========================Structs=================================//

typedef struct Biggo{
    int high, low;
}BigInt;

//==========================Funçoes=================================//

void quicksort(BigInt *arr,int esq, int dir, int big, int inv){
    //big -> se iremos utilizar o valor maior ou menor do BigInt
    //inv -> se é ordem crescente ou decrescente -> para numeros negativos

    int pivot; //ponto de referencia
    int l = esq, r = dir;
    BigInt aux; //segura o valor do

    if(big) //muda o pivot dependendo de qual ordenar
        pivot = arr[dir].high;
    else 
        pivot = arr[dir].low;
    
    while(l <= r){
        if(big){
            if(inv){
                while(arr[l].high > pivot) l++; //anda até achar um valor maior -> para os big int
                while(arr[r].high < pivot) r--; //anda até achar um valor menor, mas de forma oposta
            }else{
                while(arr[l].high < pivot) l++; //inverso
                while(arr[r].high > pivot) r--;
            }
        }else{
            if(inv){
                while(arr[l].low > pivot) l++;  //para valors small int -> bigint.low
                while(arr[r].low < pivot) r--; 
            }else{
                while(arr[l].low < pivot) l++; //inverso
                while(arr[r].low > pivot) r--;
            }
        }

        if(l <= r){
            aux = arr[r];  //troca
            arr[r] = arr[l];
            arr[l] = aux;
            l++;  //anda mais um passo
            r--;
        }
    }
    if(esq < r) quicksort(arr,esq,r, big, inv); //repete o processo com os dois vetores resultante
    if(l < dir) quicksort(arr,l, dir, big, inv);
}

void quicksortLow(BigInt *arr,int l, int r){
    int i,j, count = 0, valor, pos = 0;
    BigInt aux;   
    
    while(pos <= r){
        valor = arr[pos].high;
        while(arr[pos + count].high == valor && pos+count <= r) //agrupa em mesmos valores BigInt.high
            count++; //quantos valores tem o grupo

        if(count > 1){ //se ouver mais valores Big iguais
            if(valor < 0)
                quicksort(arr, pos, pos+count-1, 0, 1); //se for negativo é decrescente     
            else
                quicksort(arr, pos, pos+count-1, 0, 0);     

            pos += count;
            count = 0;
        }else{ //se nao houver um grupo, avance a posiçao
            pos++;
            count = 0;
        }
                
    }
}

//==========================Principal=================================//

int main()
{
    BigInt arr[max];
    int i, size = 0;
    FILE *in, *out; //out -> quick.dat

    if((in = fopen("bigint.dat","r")) == NULL){ //verifica se existe arquivo
        printf("Arquivo de entrada nao existe");
        return 0;
    }

     i = 0;
    while(fscanf(in, "%d %d", &arr[i].high, &arr[i].low) != EOF){ //recebe os valores
        size++;
        i++;
    }
    fclose(in); //fecha arquivo
        
    quicksort(arr,0,size-1, 1, 0); //lembre-se do size-1 ja que estamos mexendo com o vetor
    quicksortLow(arr,0,size); //ordenaçao no small number

    out = fopen("quick.dat", "w");

    for(i = 0; i < size; i++)
        fprintf(out, "%d %d\n", arr[i].high, arr[i].low); //falta trocar pra fprintf
    fclose(out);

    return 0;
}
