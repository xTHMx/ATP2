#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Planeta{
    char nome[21];
    double peso;
    double x,y,z;

}P;

double Pot2(double n1){
    return n1*n1;
}

double Dist(char *a, char *b, int n, P *p){
    double px[2], py[2], pz[2], dist = 0 , c1, c2, c3;
    int i = 0, founda = 0, foundb = 0, complete = 0;;

    do{
        if(strcmp(a, (p+i)->nome) == 0){
            px[0] = (p+i)->x;
            py[0] = (p+i)->y;
            pz[0] = (p+i)->z;
            founda = 1;
        }
        if(strcmp(b, (p+i)->nome) == 0){
            px[1] = (p+i)->x;
            py[1] = (p+i)->y;
            pz[1] = (p+i)->z;
            foundb = 1;
        }
        i++;
        if(founda ==1 && foundb ==1){
            complete = 1;
        }

    }while(i < n-1 || complete != 1);
    
    c1 = px[1] - px[0];
    c2 = py[1] - py[0];
    c3 = pz[1] - pz[0];
    //pow(pz[1] - pz[0],2)

    dist = sqrt( Pot2(c1) + Pot2(c2) + Pot2(c3) );
    return dist;
}

void ShowCoord(char *a, int n, P *p){
    int i = 0, found = 0;

    do{
        if(strcmp(a, (p+i)->nome) == 0){
            printf("%0.0lf %0.0lf %0.0lf \n", (p+i)->x, (p+i)->y, (p+i)->z);
            found = 1;
        }
        i++;

    }while(i < n+1 || found != 1);
}

void ShowMass(char *a, int n, P *p){
    int i = 0, found = 0;

    do{
        if(strcmp(a, (p+i)->nome) == 0){
            printf("%0.2lf \n", (p+i)->peso);
            found = 1;
        }
        i++;

    }while(i < n+1 || found != 1);
}

int main(int argc, char const *argv[])
{
    int N, M, i, op;
    char n1[21], n2[21];

    P *p = (P*) malloc(10000 * sizeof(struct Planeta));

    //printf("Start:\n");
    scanf("%d %d", &N, &M);

    for(i = 0; i < N; i++){
        //printf("insira:\n");
        scanf("%s", (p+i)->nome); //acessa o struct de acordo com +i -> só funciona
        scanf("%lf", &(p+i)->peso);
        scanf("%lf", &(p+i)->x);
        scanf("%lf", &(p+i)->y);
        scanf("%lf", &(p+i)->z);

    }


    for(i = 0; i < M; i++){
        scanf("%d", &op);

        switch(op){
            case 1: 
                //printf("insira 1:\n");
                scanf("%s %s", n1, n2);
                printf("%0.2lf\n", Dist(n1,n2,N, p));
                break;

            case 2: 
               // printf("insira 2:\n");
                scanf("%s", n1);
                ShowCoord(n1, N, p);
                break;

            case 3:
                //printf("insira 3:\n");
                scanf("%s", n1);
                ShowMass(n1, N, p);
                break;
        }
    }

    
    return 0;
}
