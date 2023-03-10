#include <stdio.h>
#include <stdlib.h>

int buscaBinaria2(long int *arr, int esq, int dir, long int target, int inv){ //usando recursao -- nao funfou no domjudge
    int meio = (dir + esq) / 2; //posiçao do meio

    if (dir >= esq){
        if (arr[meio] == target)
            return meio;

        if(inv) //se é ordem decrescente
            if (arr[meio] < target)
                return buscaBinaria2(arr, esq, meio - 1, target, 1);
            else
                return buscaBinaria2(arr, meio + 1, dir, target, 1);
        else //senao
            if (arr[meio] > target)
                return buscaBinaria2(arr, esq, meio - 1, target, 0);
            else
                return buscaBinaria2(arr, meio + 1, dir, target, 0);
    }

    return -1; //nao existe valor
}

int buscaBinaria(long int *arr, int esq, int dir, long int target, int inv)
{
        int meio = dir/2;

        if(arr[0] == target) return 0;
        else if(arr[dir] == target) return dir;

        while(arr[meio] != target && esq <= dir) {
            meio = (dir + esq) / 2;

            if(arr[meio] == target) return meio;

            if(!inv){
                if(target > arr[meio]) {
                    esq = meio + 1;
                }else{
                    dir = meio - 1;
                }
            }else{
                if(target > arr[meio]) {
                    dir = meio - 1;
                }else {
                    esq = meio + 1;
                }
            }
        }

        if(arr[meio] == target) return meio;
        
        return -1;
}
 

int main(int argc, char const *argv[])
{
    int n, m, i, meio, ans;
    long int *arr, val;

    scanf("%d", &n);

    meio = n/2;
    arr = malloc(n * sizeof(long int));

    for(i = 0; i < n; i++){
        scanf("%ld", &arr[i]);
    }

    n--;

    scanf("%d",&m);
    for(i = 0; i < m; i++){
        scanf(" %ld", &val);

        ans = buscaBinaria(arr, 0, meio, val, 0);
        if(ans == -1)
            ans = buscaBinaria(arr, meio+1, n, val, 1);

        printf("%d ", ans);
    }
    
    return 0;
}
