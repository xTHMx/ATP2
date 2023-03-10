#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int num = 200000;
    int min1 = -50, max1 = 100;
    int min2 = 1, max2 = 100000;

    FILE *big = fopen("bigint.dat","w");

    for(int i = 0; i < num; i++){
        fprintf(big, "%d %d\n", min1 + rand() % ( max1 - min1 + 1 ),
                                 min2 + rand() % ( max2 - min2 + 1 ) ); //(min) + rand() % (max - min + 1);
    }
    fclose(big);
    
    return 0;
}
