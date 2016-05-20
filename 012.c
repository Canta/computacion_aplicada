/**
    012.
    Lee cinco datos de un archivo, y calcula el promedio.
    
    @author Daniel Cantarín <canta@canta.com.ar>
    @date   20160512
*/

#include <stdio.h>
#include <math.h>

int main() 
{
    FILE * datos;
    float valores[5];
    float promedio;
    
    datos = fopen("medicion.txt","r");
    
    fscanf( datos, "%f", &valores[0]);
    fscanf( datos, "%f", &valores[1]);
    fscanf( datos, "%f", &valores[2]);
    fscanf( datos, "%f", &valores[3]);
    fscanf( datos, "%f", &valores[4]);
    
    printf("Leí estos números: %2.2f, %2.2f, %2.2f, %2.2f, y %2.2f.\n", valores[0],valores[1],valores[2],valores[3],valores[4]);
    
    promedio = (valores[0] + valores[1] + valores[2] + valores[3] + valores[4]) / 5;
    
    printf("El promedio es %2.2f.\n", promedio);
    
    return fclose(datos);
}
