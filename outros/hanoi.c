#include <stdio.h>

void hanoi(int n, char orig, char dest ,char aux){
    if(n == 1){
        printf("(%c -> %c) ",orig, dest);
    }else{
        hanoi(n-1, orig,aux,dest);
        printf("(%c -> %c) ",orig, dest);
        hanoi(n-1, aux,dest,orig);
    }
}

int main(int argc, char const *argv[])
{
    int d = 3;

    hanoi(d,'A', 'C', 'B');
    
    return 0;
}
