#include <stdio.h>
#include <math.h>
// Ejercicio Nº 3 de la guía

int main() 
{
    int a,b,c, s, area;
    
    printf("Ingrese las longitudes de los tres lados de un triángulo:\n");
    printf("Primer lado:\n");
    scanf("%d", &a);
    printf("Segundo lado:\n");
    scanf("%d", &b);
    printf("Tercer lado:\n");
    scanf("%d", &c);
    
    s = ( a + b + c ) / 2;
    
    area = ( s * ( (s-a) * (s-b) * (s-c) ) ) ^ (1/2);
    
    printf("El área del triángulo es %d.\n", area);
    
    return 0;
}
