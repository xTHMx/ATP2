#include <stdio.h>
#include <string.h>

int GetRoman(char str)
{
    switch(str)
    {
        case 'I': return 1; break;
        case 'V': return 5; break;
        case 'X': return 10; break;
        case 'L': return 50; break;
        case 'C': return 100; break;
        case 'D': return 500; break;
        case 'M': return 1000; break;  
        default: return -1; break;
        
    }
}

void MakeRoman(int num)
{
    int val[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char *rom[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    char str[100] = {"\0"};
    int i = 0;

 
    while(num > 0){   
        while(num / val[i]){          //first base value that divides num is largest base value
            strcat(str,rom[i]);
            //printf("%s",rom[i]);    //print roman symbol equivalent to largest base value

            num -= val[i];
           
        }

        i++;               
    }

    printf("%s\n", str);
    strcpy(str, ""); //limpa string

}

int main(int argc, char const *argv[])
{
    int i, c, n, size, val[100], res, decimal , total = 0;
    char romano[100], out_romano[100];

    scanf("%d", &n);

    while(n > 0)
    {
        scanf("%d", &c);

        if(c == 2){                           //======== Decimal -> Romano ===========
            scanf("%d", &decimal);

            MakeRoman(decimal);
            n--;

        }else if(c == 1){                     //========= Romano -> Decimal ===========
            scanf("%s", romano);

            size = strlen(romano);

            for(i = 0; i < size; i++) //pega valor correspondente
            {
                val[i] = GetRoman(romano[i]);
            }

            res = val[size-1]; //-1 pois a posiçao começou no 0 e o val[size] n tem valor senod o final [size-1]

            for(i = size-1; i > 0; i--) //leia de sentido oposto e observando o anterior(proximo)
            {
                if(val[i] > val[i-1]){ //se for maior que o proximo
                    res -= val[i-1];

                }else if(val[i] < val[i-1] || val[i] == val[i-1]){ //se for menor ou igual
                    res += val[i-1];

                }
            }


            total += res;
            printf("%d\n", res);
            n--;

        }

    }

    printf("%d\n", total);

    return 0;
}
