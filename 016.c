/**
 * Programa para resolver sudokus de 9x9.
 * 
 * @author  Daniel Cantarín
 * @date    20160616
 * 
 * */

#include <stdio.h>
#include "matrices.h"
#include "matrices.c"

int main () 
{
    float X[5]  = {1,2,3,4,5};
    float Y[5]  = {1,2,3,4,5};
    float X2[5] = {0,0,0,0,0};
    float XY[5] = {0,0,0,0,0};
    
    char i;
    for (i=0; i < 5; i++)
    {
        X2[i] = X[i] * X[i];
        XY[i] = X[i] * Y[i];
    }
    
    float prom_X  = promedio(X, 5);
    float prom_Y  = promedio(Y, 5);
    float prom_X2 = promedio(X2, 5);
    float prom_XY = promedio(XY, 5);
    
    printf("Promedio de X:  %f\n", promedio(X , 5));
    printf("Promedio de Y:  %f\n", promedio(Y , 5));
    printf("Promedio de X2: %f\n", promedio(X2, 5));
    printf("Promedio de XY: %f\n", promedio(XY, 5));
    
    float A = ( (prom_XY * 1) - (prom_Y * prom_X) ) / ( (prom_X2 * 1) - (prom_X * prom_X));
    float B = ( (prom_X2 * prom_Y) - (prom_X * prom_XY) ) / ( (prom_X2 * 1) - (prom_X * prom_X));;
    
    printf("La pendiente es : %f\n", A);
    printf("La ordenada de origen es : %f\n", B);
    
    return 0;
}
