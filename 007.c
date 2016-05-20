#include <stdio.h>
#include <math.h>

// Ejercicio Nº 5 de la guía Nº 2.

/**
 * Función Cos(x) - x
 * 
 * @author Daniel Cantarín
 * @date 20160421
 **/
double f1( double );


/**
 * Función f1'
 * 
 * @author Daniel Cantarín
 * @date 20160421
 **/
double fd1( double );


int main() 
{
    double x0, x1, cota, error;
    printf("Ingrese x0:");
    scanf("%lf", &x0);
    
    printf("Ingrese margen de error:");
    scanf("%lf", &error);
    
    cota = 50;
    while ( cota > error ) { 
        x1   = x0 -  f1(x0) / fd1(x0);
        cota = fabs(x1 - x0);
        //printf("Error: %lf, Cota: %lf, x0: %lf, x1: %lf\n", error, cota, x0, x1);
        x0   = x1;
    }
    
    printf("Tomá: %lf\n", x0);
    
    return 0;
}


double f1 ( double x ) 
{
    double z;
    
    z = x - cos(x);
    
    return z;
}


double fd1 ( double x ) 
{
    double z;
    
    z = 1 + sin(x);
    
    return z;
}

