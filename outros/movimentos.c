#include <stdio.h>
#include <math.h>

double DistanciaMRU(double v, double t)
{
    return v*t;
}

double VelocidadeMRU(double s, double t)
{
    return s/t;
}

double TempoMRU(double s, double v)
{
    return s/v;
}

double DistanciaMRUV(double v, double a, double t)
{
    return v*t + (a * t*t)/2;
}

double VelInicMRUV(double s, double a, double t)
{
    return (s-(a*t*t)/2)/t;
}

double VelFinMRUV(double v, double a, double t)
{
    return  v + a*t;
}

double TempoTotal(double s, double v, double a)
{
    double x, delta;
    
    //return sqrt(b*b) + (2*a*c);
    
    delta = (4*v*v)-(4*a*s*(-2));
    x = ((2*v*-1) + sqrt(delta) )/ (2*a);
    return x; 
}


//=========Principal============//

int main(int argc, char const *argv[])
{
    int o, n, i;
    double a, b, c, res;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf(" %d", &o);
    
    
	scanf(" %lf %lf", &a, &b);
    switch(o)
        {
            case 1: 
                res =  DistanciaMRU(a,b);
                printf("%.2lf\n", res);
                
            break;

            case 2:  
                 res =  VelocidadeMRU(a,b);
                	printf("%.2lf\n", res);
            break;

            case 3: 
                 res =   TempoMRU(a,b);
                	printf("%.2lf\n", res);
            break;

            case 4:
                scanf(" %lf", &c);
                res =   DistanciaMRUV(a,b,c);
                printf("%.2lf\n", res);
            break;

            case 5:
                scanf(" %lf", &c);
                res =    VelFinMRUV(a,b,c);
                printf("%.2lf\n", res);
            break;

            case 6:
                scanf(" %lf", &c);
                res =   VelInicMRUV(a,b,c);
                printf("%.2lf\n", res);
                
            break;

            case 7: 
                scanf(" %lf", &c);
                 res =   TempoTotal(a,b,c);
                 printf("%.2lf\n", res);
                
            break;          

        }
        
        
    }

    return 0;
}
