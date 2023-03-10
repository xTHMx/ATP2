#include <stdio.h>
#include <stdlib.h>

void Labirinto(int size, int maze[size][size], int n, int m, int end, int curr)
{         
    if(n >= size || n < 0 || m < 0 || m >= size || maze[n][m] != 0)
            return;


    if(n == size-1 && m == end) {
            printf("%d\n", curr);
            exit(0);
    }      
    maze[n][m] = curr;

    Labirinto(size, maze, n + 1, m, end, curr + 1);
    Labirinto(size, maze, n, m + 1, end, curr + 1);
    Labirinto(size, maze, n, m - 1, end, curr + 1);
    maze[n][m] = 0;
    
}

void makeMaze(int size, int n, int m){
    int maze[size][size], i;

    for(i = 0; i < size*size; i++)
        scanf(" %d", &maze[i/size][i%size]);

    Labirinto(size, maze, 0, n, m, 0);
    
}

int main(int argc, char const *argv[])
{
    int size, n, m; //n,m -> x,y

    scanf("%d %d %d", &size, &n , &m);

    makeMaze(size,n,m);

    printf("-1\n");
    return 0;
}
