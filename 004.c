#include <stdio.h>
#include <math.h>

int main () {
    
    float a, b, err, delta;
    
    printf("Ingrese dos números a y b determinar un entorno cerrado [a,b].\n");
    printf("a:");
    scanf("%f", &a);
    
    printf("b:");
    scanf("%f", &b);
    
    // defino un error fijo.
    err     = 0.0002;
    delta   = 1;
    
    
    
    while ( delta > err ) {
        delta = delta - err;
        printf("%f\n", delta);
    }
    
    return 0;
}
