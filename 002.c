#include <stdio.h>

int main() 
{
    int anio, mes, dia, edad;
    
    printf("Ingrese su fecha de nacimiento.\n");
    printf("Año:");
    scanf("%d", &anio);
    
    printf("Mes:");
    scanf("%d", &mes);
    
    printf("Día:");
    scanf("%d", &dia);
    
    int tmp1; 
    
    edad = 2016 - anio;
    tmp1 = 4 - mes;
    
    if ( tmp1 < 0 ) 
    {
        edad--;
    }
    
    printf("Tenés %d años.\n", edad);
    
    return 0;
}
