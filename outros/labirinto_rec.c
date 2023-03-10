#include <stdio.h>

void CheckMaze(int m[][10], int px, int py, int opx,int opy){
    //int opx = px, opy = py;
    if(px == 9 && py == 9){
        printf("==Tem soluçao== ");
        printf("[9][9] ");
        return;
    }

    if(m[px+1][py] == 1 && px+1 != opx){
        opx = px;
        opy = py;
        px = px+1;
        CheckMaze(m,px,py,opx,opy);
        printf("[%d][%d] ", px,py);
        
    }else if(m[px][py+1] == 1  && py+1 != opy){
        opx = px;
        opy = py;
        py = py+1;
        CheckMaze(m,px,py,opx,opy);
        printf("[%d][%d] ", px,py);
        
    }else if(m[px-1][py] == 1 && px-1 != opx ){
        opx = px;
        opy = py;
        px = px-1;
        CheckMaze(m,px,py,opx,opy);
        printf("[%d][%d] ", px,py);
        
    }else if(m[px][py-1] == 1 && py-1 != opy){
        opx = px;
        opy = py;
        py = py-1;
        CheckMaze(m,px,py,opx,opy);
        printf("[%d][%d] ", px,py);
        
    }else{
        printf("==Sem soluçao== ");
        return;
    }
}

int main(int argc, char const *argv[])
{
    int maze[][10] = {  {1,1,0,0,0,0,0,0,0,0},
                        {0,1,0,0,0,0,0,0,0,0},
                        {0,1,0,0,0,0,0,0,0,0},
                        {0,1,0,0,0,0,0,0,0,0},
                        {0,1,0,0,0,0,0,0,0,0},
                        {0,1,1,1,1,0,0,0,0,0},
                        {0,0,0,0,1,0,1,1,1,0},
                        {0,0,0,0,1,0,1,0,1,0},
                        {0,0,0,0,1,1,1,0,1,1},
                        {0,0,0,0,0,0,0,0,0,1}
    };


    CheckMaze(maze,0,0,0,0);
    
    return 0;
}
