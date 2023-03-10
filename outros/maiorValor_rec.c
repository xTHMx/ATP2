#include <stdio.h>

int MaiorValor(int v[], int tam, int pos){
    if(tam == 0){
        return v[pos]; //maior elemento
    }else{
        if(v[pos] > v[tam-1]){
            return MaiorValor(v,tam-1,pos);
        }else{
            return MaiorValor(v,tam-1,tam-1);
        }
    }
}


int main(int argc, char const *argv[])
{
    int v[10] = {1,2,3,4,19,2,5,6,21,19};

    printf("Maior valor: %d", MaiorValor(v,10,0));
    
    return 0;
}
