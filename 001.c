#include <stdio.h>

int main() 
{
    int a, b, c ;
    
    printf("Ingrese un numero:");
    scanf("%d", &a);
    
    printf("Ingrese otro:");
    scanf("%d", &b);
    
    c = a + b;
    printf("La suma es: %d\n", c);
    
    return 0;
}
