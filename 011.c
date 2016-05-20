/**
    011.
    Abre, lee, y cierra un archivo.
    
    @author Daniel Cantarín <canta@canta.com.ar>
    @date   20160512
*/

#include <stdio.h>
#include <math.h>

int main() 
{
    FILE * datos;
    float a, b, c;
    
    datos = fopen("medicion.txt","r");
    
    fscanf( datos, "%f", &a);
    fscanf( datos, "%f", &b);
    fscanf( datos, "%f", &c);
    
    printf("Leí estos números: %2.2f, %2.2f, y %2.2f .\n", a, b, c);
    
    return fclose(datos);
}
