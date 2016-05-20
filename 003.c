#include <stdio.h>
#include <math.h>
// Ejercicio Nº 1 de la guía.


int main() 
{
    float a, b, c, d;
    
    printf("Ingrese a, b, y c, para un polinomio ax^2 + bx + c.\n");
    printf("a:");
    scanf("%f", &a);
    
    printf("b:");
    scanf("%f", &b);
    
    printf("c:");
    scanf("%f", &c);
    
    //d = ( 4 * a * c )^(1/2);
    d = sqrt( 4 * a * c );
    
    if (d < 0) {
        printf("ERROR: No es posible obtener las raices del polinomio dado. Imposible continuar.\n");
        printf("%f\n",d);
        return 1;
    }
    
    float x1, x2;
    
    x1 = ( (b * -1) + d ) / (2 * a);
    x2 = ( (b * -1) - d ) / (2 * a);
    
    printf("Las raices son %f y %f.\n", x1, x2);
    
    return 0;
}
