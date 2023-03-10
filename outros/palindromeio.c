#include <stdio.h>
#include <string.h>


int Palindromeio(char *str, int pos, int aux, int count){
    int i, k, temp_count = 0, stop = 0, temp_aux = aux;

    i = 0;
    while(i <= pos && stop == 0){ 
        if(str[temp_aux] == str[pos-i]){
            temp_aux++;
            temp_count++;
        }else{
            if(temp_count > 0){
                stop = 1;
            }
        }

        i++;
    }

    if(temp_count > count){
        count = temp_count;
    }

    if(aux == pos){
        return count;
    }

    return Palindromeio(str, pos, aux+1, count);
    
}

int main(int argc, char const *argv[])
{
    char s[2001];
    int count = 0, size;

    scanf("%s", s);

    printf("%d\n", Palindromeio( s, strlen(s) , 0, count));

    return 0;
}
