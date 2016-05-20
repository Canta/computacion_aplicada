#include <stdio.h>
#include <math.h>

// Idem 009, pero que calcule solito m y b.

int main() 
{
    int     n;
    float   X[100] ;
    float   Y[100] ;
    float   F[100] ;
    int     i;
    float   e;
    float   m;
    float   b;
    
    printf("Ingrese la pendiente:");
    scanf("%f", &m);
    
    printf("Ingrese ordenada al origen:");
    scanf("%f", &b);
    
    
    printf("Ingrese la cantidad de mediciones:");
    scanf("%d", &n);
    
    if ( n <= 0 )
    {
        printf("No. %d no. No jodamos.\n", n);
        return 1;
    }
    
    for (i = 0; i < n; i++)
    {
        printf("X[%d]:", i);
        scanf("%f", &X[i]);
        printf("Y[%d]:", i);
        scanf("%f", &Y[i]);
        
        F[i] = m * X[i] + b;
    }
    
    e = 0;
    
    for (i = 0; i < n; i++)
    {
        e = e + powf( (Y[i] - F[i]) , 2);
    }
    
    e = sqrtf(e / n);
    
    if ( e > 0.75 )
    {
        printf("Poné números como la gente, dejate de joder.\n");
        return 1;
    }
    
    printf("Error cuadrático medio: %f\n", e);

    
    return 0;
}
