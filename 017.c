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
    float X1[3]         = { 0 };
    float X2[3]         = { 0 };
    float tolerancia    = 0.001;
    
    char i;
    char j;
    printf("Matriz inicial (\"E\"):\n");
    for (i=0; i < N; i++)
    {
        C[i]    =   b[i] / A[i][i];
        X1[i]   =   1;
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
    
    printf("\nMi flautagorquio de ptolomeo (\"C\") es el siguiente:\n");
    for (i = 0; i < N; i++)
    {
        printf("C[%d]: %lf\n", i, C[i]);
    }
    printf("-------------------\n");
    
    float cota = cota_vector(X1, X2, N);
    //printf("cota: %lf\n", cota); 
    while ( cota > tolerancia )
    {
        multiplicar(E, X1, N, X2);
        sumar_vectores(X2, C, N, X2);
        cota = cota_vector(X1, X2, N);
        //printf("cota: %lf\n", cota);
        //for (i = 0; i < N; i++)
        //{
        //    printf("X1[%d]: %lf ; X2[%d]: %lf.\n", i, X1[i], i, X2[i]);
        //}
        for(i =0; i < N; i++) {
            X1[i] = X2[i];
        }
    }
    
    printf("\nMi vector final es el siguiente:\n");
    for (i = 0; i < N; i++)
    {
        printf("X[%d]: %lf\n", i, X2[i]);
    }


    
    multiplicar(A, X2, N, X1);
    printf("\nMultiplicado por la matriz inicial, me dá esto:\n");
    for (i = 0; i < N; i++)
    {
        printf("X[%d]: %lf\n", i, X1[i]);
    }
    
    printf("\nMe tendría que dar algo cercano a esto:\n");
    for (i = 0; i < N; i++)
    {
        printf("b[%d]: %lf\n", i, b[i]);
    }
    return 0;
}
