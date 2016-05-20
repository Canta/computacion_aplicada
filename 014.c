/**
    014.
    Ejercicio Nº 5 de la guía Nº 1
    
    @author Daniel Cantarín <canta@canta.com.ar>
    @author Bárbara Menares <fily@fily.com.ar>
    @date   20160514
*/

#include <stdio.h>
#include <math.h>

float p( float x );

int main() 
{
    
    float i;
    
    for (i = -1; i <= 1 ; i = i + 0.1)
    {
        printf( "p(%2.2f) = %2.2f.\n", i, p(i) );
    }
    
    
    return 0;
}


float p ( float x )
{
    float ret, tmp;
    
    ret = x * ( 2 / 3.1416);
    tmp = 1 - (powf(x,2.0) / 6) + ( powf(x,4.0) / 40 ) + ( powf(x, 6.0) / 336 ) + ( powf(x,8.0) / 3456) ;
    
    ret = ret * tmp;
    
    return ret;
}
