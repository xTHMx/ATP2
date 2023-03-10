#include <stdio.h>

int Menor(int size, int matrix[size][size], int a, int b)
{
        int i, j, menor = matrix[a][a];

        for(i = a; i <= b; i++)
                for(j = a; j <= b; j++)
                        if(matrix[i][j] < menor)
                                menor = matrix[i][j];


        return menor;
}

void Solucao(int lin, int col)
{
        int matrix[lin][lin];
        int i, a, b, temp;

        for(i = 0; i < lin*lin; i++)
            scanf(" %d", &matrix[i/lin][i%lin]);

        for(i = 0; i < col; i++) {
                scanf("%d %d", &a, &b);
                temp = Menor(lin, matrix, a-1, b-1);
                printf("%d\n", temp);
        }
}

int main()
{
        int n, m;
        
        scanf("%d %d", &n, &m);
        Solucao(n, m);

        return 0;
}

