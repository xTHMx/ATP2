#include <stdio.h>
#include <string.h>

int checkString(char temp[], int x1, int x2)
{
    if(x1 > x2)
        return 1;
    else if(temp[x1] != temp[x2])
        return 0;

    return checkString(temp, x1+1, x2-1); 
}

int Palindromeio(char str[])
{
    int tam = strlen(str);
    int i, maior = 1, j;

    for(i = 0; i < tam; i++) {
        for(j = tam; j > i; j--) {
            if(str[i] == str[j] && checkString(str, i, j)) {
                if(j - i + 1 > maior)
                    maior = j - i + 1;
            }
        }
    }

    return maior;
}

int main()
{
    char pal[2001];

    scanf("%s", pal);
    printf("%d\n", Palindromeio(pal));

    return 0;
}