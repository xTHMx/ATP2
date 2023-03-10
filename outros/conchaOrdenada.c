#include <stdio.h>
#include <string.h>
#include <math.h>

void shellSort(char arr[10000][100], int n){
    int i,j,k,l;
    char menor[100];

    k = 1;
    while(k <= n/4) k *= 2; //calculando passo inicial 

    while( k != 1){
        k = k/2; //acertando o passo para iteraçao atual

        for(i = k; i < n; i++){ //algoritimo de insertion adaptado
            strcpy(menor,arr[i]);
            j=i;

            while(j >= k && strcmp(arr[j-k], menor) > 0){
                strcpy(arr[j], arr[j-k]);
                j = j-k;
            }

            strcpy(arr[j], menor);
            
        }

        for(l = 0; l < n; l++) //print
            printf("%s ", arr[l]);
        printf("\n");

    }
    return;
}

int main(int argc, char const *argv[])
{
    int n, i;
    char arr[10000][100]; // indices / string size

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%s", arr[i]);

    shellSort(arr, n);

    return 0;
}
