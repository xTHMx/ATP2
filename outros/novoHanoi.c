#include <stdio.h>

//(t)torres 0->orig  1-> aux 2->dest;
int k, t[3][20];

int newHanoi(int n, int x, int y, int x2, int y2, int a, int a2){
    if(k!=0){
        if(n == 1){
        t[a][a2] = t[x][y];
        t[x][y] = 0;

        k--;
        return 1;

        } 
        else{
            newHanoi(n-1, x, y+1 ,a, a2, x2, y2);
            if(k != 0){
                t[a][a2] = t[x][y];
                t[x][y] = 0;
                k--;

                newHanoi(n -1, x2, y2, x, y, a, a2+1);
            }
            else return 0;
        }
    }
    else return 0;
}

void Print(){
    int i, aux;
    i=0;
    
    while(t[0][i]) i++;

    if(i==0)  printf("0");

    for(aux=i-1; aux>=0; aux--)
        printf("%d ", t[0][aux]);

    printf("\n");

    i=0;
    while(t[1][i]) i++;

    if(i==0)  printf("0");

    for(aux=i-1; aux>=0; aux--)
        printf("%d ", t[1][aux]);

    printf("\n");

    i=0;
    while(t[2][i]) i++;

    if(i==0)  printf("0");

    for(aux=i-1; aux>=0; aux--)
        printf("%d ", t[2][aux]);

    printf("\n");
}

int main(){
    int n, i;

    
    scanf("%d %d", &n, &k);

    for(i=0; i<n;i++){
        t[0][i] = n - i;
    }

    newHanoi(n, 0, 0, 1, 0, 2, 0);

    Print();

    return 0;
}