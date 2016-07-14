/**
 * Header para librería de gestión de matrices.
 * 
 * @author  Daniel Cantarín
 * @date    20160616
 * 
 * */
 
float   promedio( float * vector , int tamanio);
void    multiplicar( float * matriz, float * vector , int tamanio, float * resultado) ; 
void    dividir( float * matriz, float * vector , int tamanio, float * resultado) ;
float   cota_vector( float * vector1, float * vector2, int tamanio) ;
void    sumar_vectores( float * vector1, float * vector2, int tamanio , float * resultado);
