#include<stdio.h>

void insertSort(double arr[], int size, int k){
    int i, j, m,n;
    double aux;

    for (i=1; i <= k; i++){
        aux = arr[i];
        j = i;
        while(j>0 && arr[j-1] > aux)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = aux;
    }

    for(m = k+1; m < size; m++){
        aux = arr[m];
        n = m;
        while (n > 0 && arr[n-1] < aux)
        {
            arr[n] = arr[n-1];
            n--;
        }
        arr[n] = aux;
    }
}


int main(){
 int i, k, n;
 scanf("%d %d", &n, &k);

 double arr[n];

 for (int i = 0; i < n; i++)
    scanf("%lf", &arr[i]);
 
 insertSort(arr,n,k);

 for (int i =0; i < n; i++)
    printf("%.3lf ", arr[i]);

     return 0;
} 