/**
    013.
    Lee datos de un archivo y calcula el promedio.
    
    @author Daniel Cantarín <canta@canta.com.ar>
    @date   20160512
*/

#include <stdio.h>
#include <math.h>

int main() 
{
    FILE * datos;
    float dato, suma, promedio, cantidad;
    
    datos       = fopen("medicion.txt","r");
    suma        = 0;
    cantidad    = 0;
    
    while ( feof( datos ) == 0 )
    {
        dato        = 0;
        fscanf( datos, "%f", &dato);
        if (feof( datos ) == 1 && dato == 0) {
            break;
        }
        printf("Leí %2.2f\n", dato);
        suma        = suma + dato;
        cantidad    = cantidad + 1;
    }
    
    printf("La suma de todos los datos leidos es %2.2f. El promedio, %2.2f.\n", suma, suma / cantidad);
    
    return fclose(datos);
}
