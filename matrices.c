/**
 * Librería para gestión de matrices.
 * 
 * @author  Daniel Cantarín
 * @date    20160616
 * 
 * */

#include <math.h>

float promedio( float * vector , int tamanio) 
{
    int      i = 0;
    float prom = 0;
    for (i = 0; i < tamanio; i++) 
    {
        prom = prom + vector[i];
    }
    prom = prom / tamanio;
    return prom;
}

void multiplicar( float * matriz[], float * vector , int tamanio, float * resultado) 
{
    int i;
    int j;
    
    float * matriz2;
    
    for (i = 0; i < tamanio; i++)
    {
        resultado[i] = 0;
    }
    
    for (i = 0; i < tamanio; i++)
    {
        for(j = 0; j < tamanio; j++) 
        {
            matriz2 = &matriz[i];
            resultado[i] = resultado[i] + (matriz2[j] * vector[j]);
        }
    }
}


void dividir( float * matriz[], float * vector , int tamanio, float * resultado) 
{
    int i;
    int j;
    float * matriz2;
    
    for (i = 0; i < tamanio; i++)
    {
        resultado[i] = 0;
    }
    
    for (i = 0; i < tamanio; i++)
    {
        for(j = 0; j < tamanio; j++) 
        {
            matriz2 = &matriz[i];
            resultado[i] = resultado[i] + (matriz2[j] / vector[j]);
        }
    }
}


float cota_vector( float * vector1, float * vector2, int tamanio) 
{
    float   cotas[tamanio];
    float   cota = 0;
    int     i;
    for ( i = 0; i < tamanio; i++)
    {
        cotas[i] = fabs(vector1[i] - vector2[i]);
     }
    
    
    for ( i = 0; i < tamanio; i++)
    {
        if (cotas[i] > cota) 
        {
            cota = cotas[i];
        }
    }
    
    return cota;
}

void sumar_vectores( float * vector1, float * vector2, int tamanio, float * resultado )
{
    int i;
    for (i = 0; i < tamanio; i++) {
        resultado[i] = vector1[i] + vector2[i];
    }
}


