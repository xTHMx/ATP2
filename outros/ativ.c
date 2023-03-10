#include <stdio.h>


void ChecaValor(int n[4][4], int k, int px, int py){
    int i,j, mpx,mpy;
    mpx = px;
    mpy = py;
    for(i = px-k; i < px + k; i++ ){
            for(j=py-k; j < py+k; j++){
                
                if( n[mpx][mpy] <= n[px+i][py+j] && px+i >0 && py+j > 0){
                    mpx =px+i;
                    mpy =py+j;
                }
                
            }
    }

    printf("Maior valor: %d -> [%d,%d]", n[mpx][mpy], mpx, mpy);
}


int main(int argc, char const *argv[])
{
    int n[][4] = {  {1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16}
    };


    ChecaValor(n,1,0,0);

    
    return 0;
}
