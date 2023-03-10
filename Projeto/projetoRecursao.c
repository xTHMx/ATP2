#include <stdio.h>
#include <stdlib.h>

//Variaveis Globais
int count = 0, num_entrada, num_saida, pass;

//======================================================Funçoes=====================================================================//
//faz a soma dos valores no vetor
int SomaArray(int arr[], int size, int compare){ 
    int soma = 0, i;

    for(i = 0; i < size; i++)
        soma += arr[i];
    
    if(compare == soma)
        return 1;
  
    return 0;
}

/* Combinacao() - realiza o processo de combinar e calcular a soma de um vetor referente a um int
   nums = array com valores pra combinar
   result = array pra segurar a combinaçao temporaria
   temp = array pra segurar a combinaçao final
   val = valor pra comparar com a soma
   start/end = onde começa e onde termina de pegar pra combinar
   index = offset do numero que eu vou comerçar usando
   n = numero de valores dentro de cada combinaçao
   aux[] = vetor auxiliar para verificaçao
*/
void Combinacao(int nums[], int result[], int temp[], int val, int start, int end, int index, int n){
    int i, aux[n];

    pass++; //variavel que define qual o inicio da chamada da funçao

    //testa a combinaçao se houver|
    if (index == n){
        if(SomaArray(temp, n, val) == 1){
            if(temp[n-1] != 0){ //se for maior que o anterior
              for(i = 0; i < n; i++){ //insere o valor do array ou resultado final e passa ao auxiliar
                aux[i] = result[i];
                result[i] = temp[i];

              }

              if(result[n-1] < aux[n-1]){ //se o valor anterior era maior, retorne valores do anterior
                  for(i = 0; i < n; i++){
                  result[i] = aux[i];
                }
              }
            }
               
            count++;
        }
        return; //terminei essa parte, retorno
    }
 
    //cria as combinaçoes
    for (i=start; i < end ; i++){
        temp[index] = nums[i];
        Combinacao(nums, result, temp, val, i+1, end, index+1, n); //chamo a funçao pra pegar o proximo valor
        pass--;
    }

    //verifica se ja testamos todas as combinaçoes
    if(n < num_entrada && pass == 1){
        //pass define que a funçao retornou a primeira chamada
        pass = 0;
        Combinacao(nums, result, temp, val, 0, end, 0, n+1);
    }
}
 
//========================================================Principal================================================================//
int main(int argc, char const *argv[])
{
    int i, j, temp[1000000], size;
    int entr[21], said[100], result[1000000];

    //entrada de valores
    scanf("%d", &num_saida);
    scanf("%d", &num_entrada);

    // cria um array com os valores do conjunto inicial para combinaçao
    for(i = 0; i < num_entrada; i++){
        scanf(" %d", &entr[i]);
    }

    // cria um array com os valores de que devem ser usados na verificaçao da combinaçao
    for(i = 0; i < num_saida; i++){
        scanf(" %d", &said[i]);
    }

    //realiza o processo e printa tudo
    for(i = 0; i < num_saida; i++){
        pass = 0;
        Combinacao(entr, result, temp, said[i], 0, num_entrada, 0, 1);
      
        //se o resultado existir printe a sequencia
        if(result[0] != 0){
            printf("\n[%d] ", count);
          
            j=0;
            while(result[j] != 0){ //loop pela sequencia
              printf("%d ", result[j]);
              result[j] = 0; //reseta o valor pra 0, para proxima funçao
              j++;
            }
        }else{ //nao existe resposta
            printf("\n0\n");
        }

        //reseta o contador 
        count = 0;
    }
    
    return 0;
}
