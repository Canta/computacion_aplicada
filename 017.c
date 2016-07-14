/**
 * Programa para resolver una matriz estrictamente diagonal de NxN .
 * 
 * @author  Daniel Cantarín
 * @date    20160623
 * 
 * */

#include <stdio.h>
#include "matrices.h"
#include "matrices.c"

int main () 
{
    int   N             = 3; 
    float A[3][3]       = { { 2, 0.3, 0.2 }, { 0.1, 3, 0.4 }, { 0.1, 0.2, 5 } };
    float b[3]          = { 12, 12, 10 };
    float E[3][3]       = { {0} };
    float C[3]          = { 0, 0, 0 };
    float X[2][3]       = { {0} };
    float tolerancia    = 0.001;
    
    char i;
    char j;
    printf("Matriz inicial:\n");
    for (i=0; i < N; i++)
    {
        C[i]    =   b[i] / A[i][i];
        X[0][i] =   1;
        for(j=0; j < N; j++) 
        {
            if (i == j) 
            {
                E[i][j] = 0;
            } 
            else 
            {
                E[i][j] = (A[i][j] * -1) / A[i][i]; 
            }
            printf("%lf ", E[i][j]);
        }
        printf("\n");
    }
    printf("-------------------\n");
    
    float cota = cota_vector(X[0], X[1], N);
    printf("cota: %lf\n", cota); 
    while ( cota > tolerancia )
    {
        multiplicar(E, X[0], N, X[1]);
        sumar_vectores(X[1], C, N, X[1]);
        cota = cota_vector(X[0], X[1], N);
        printf("cota: %lf\n", cota);
        for(i =0; i < N; i++) {
            X[0][i] = X[1][i];
        }
        
    }
    
    printf("\nMi vector final es el siguiente:\n");
    for (i = 0; i < N; i++)
    {
        printf("X[%d]: %lf\n", i, X[1][i]);
    }


    
    multiplicar(A, X[1], N, X[0]);
    printf("\nMultiplicado por la matriz inicial, me dá esto:\n");
    for (i = 0; i < N; i++)
    {
        printf("X[%d]: %lf\n", i, X[0][i]);
    }
    
    return 0;
}
