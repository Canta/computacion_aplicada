#include <stdio.h>
// Ejercicio Nº 2 de la guía

int main() 
{
    int a,c;
    
    printf("Ingrese una temperatura expresada en grados Farenheit:");
    scanf("%d", &a);
    
    
    c = (a - 32) * 50 / 90;
    printf("Eso son %d grados celcius.\n", c);
    
    return 0;
}
