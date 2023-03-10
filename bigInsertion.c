#include <stdio.h>
#define max 200000

//==========================Structs=================================//
typedef struct Biggo{
    int high, low;
}BigInt;


//==========================Funçoes=================================//
void insertsort(BigInt *arr, int n){
    int i,j;
    BigInt aux;
    
    for(i = 1; i < n; i++){
        j = i;
        while(j > 0 && arr[j-1].high > arr[j].high){ //insertion normal para bigint.high
            aux = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = aux;
            
            j = j-1;
        }
    }
}

void insertsortLow(BigInt *arr, int n){
    int i,j, count = 0, valor, pos = 0;;
    BigInt aux;
    
    
    while(pos <= n){
        valor = arr[pos].high;
        while(arr[pos + count].high == valor && pos+count <= n) //agrupa em mesmos valores BigInt.high
            count++; //quantos valores tem no grupo

        if(count > 1){ //se o grupo tiver mais de 1 valor
            for(i = pos+1; i < pos + count; i++){ //loop até o fim do grupo
                j = i;
                if(valor > 0){           //se for positivo
                    while(j > pos && arr[j-1].low > arr[j].low){
                        aux = arr[j];
                        arr[j] = arr[j-1];
                        arr[j-1] = aux;
                        
                        j = j-1;
                    }
                }else{                  //se for negativo
                    while(j > pos && arr[j-1].low < arr[j].low){
                    aux = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = aux;
                    
                    j = j-1;
                }
                }
            }
            pos += count; //acerta a pos inicial
            count = 0;
        }else{
            pos++; //se n ouver grupo, avance 1 posiçao
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

    if((in = fopen("bigint.dat","r")) == NULL){//verifica se existe arquivo
        printf("Arquivo de entrada nao existe");
        return 0;
    }

    i = 0;
    while(fscanf(in, "%d %d", &arr[i].high, &arr[i].low) != EOF){ //recebe os valores
        size++;
        i++;
    }
    fclose(in); //fecha arquivo
        
    insertsort(arr,size); //ordenaçao no big number
    insertsortLow(arr,size); //ordenaçao no small number

    out = fopen("insert.dat", "w");   
    for(i = 0; i < size; i++)
        fprintf(out, "%d %d\n", arr[i].high, arr[i].low);
    fclose(out);

    return 0;
}
