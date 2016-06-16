/**
 * Librería para gestión de matrices.
 * 
 * @author  Daniel Cantarín
 * @date    20160616
 * 
 * */


float promedio( float * vector , int tamanio) 
{
    int      i = 0;
    float prom = 0;
    for (i = 0; i < tamanio; i++) 
    {
        prom = prom + vector[i];
    }
    prom = prom / tamanio;
    return prom;
}
