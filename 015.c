/**
    015.
    Ejercicio Nº 3 de la guía Nº 3.
    
    @author Daniel Cantarín <canta@canta.com.ar>
    @date   20160519
*/

#include <stdio.h>
#include <math.h>

int main() 
{
    FILE * datos;
    float   temperatura, humedad, co2, max_temp, tmp;
    char    fecha[10];
    char    hora[8];
    int     col1, col2, col3, col4, cantidad;
    
    datos       = fopen("downloads/mediciones.txt","r");
    temperatura = 0;
    cantidad    = 0;
    humedad     = 0;
    co2         = 0;
    max_temp    = 0;
    
    while ( feof( datos ) == 0 )
    {
        col4 = 0;
        fscanf( datos, "%s  %s   %d    %d    %d    %d  "    , fecha, hora, &col1, &col2, &col3, &col4);
        //printf( "Fecha: %s. Hora: %s. Temperatura: %d. Humedad: %d. CO2: %d. Coso: %d.\n", fecha, hora, col1, col2, col3, col4 );
        if (feof( datos ) == 1 && col4 == 0) {
            break;
        }
        
        tmp         = (col1 / 100);
        temperatura = temperatura + tmp;
        humedad     = humedad + (( col2 - 0.16 ) / 0.0062);
        co2         = co2 + col3;
        cantidad    = cantidad + 1;
        if (tmp > max_temp) {
            max_temp = tmp;
        }
    }
    
    printf("%d mediciones leidas.\n"                    , cantidad);
    printf("Temperatura promedio: %2.2f ºC.\n"          , temperatura / cantidad);
    printf("Máxima temperatura registrada: %2.2f ºC.\n" , max_temp);
    printf("Humedad promedio: %2.2f.\n"                 , humedad / cantidad);
    printf("Concentración promedio de CO2: %2.2f PPM.\n"    , co2 / cantidad);
    fclose(datos);
    
    datos = fopen("resultados.015.txt", "w");
    fprintf(datos, "%d mediciones leidas.\n"                        , cantidad);
    fprintf(datos, "Temperatura promedio: %2.2f ºC.\n"              , temperatura / cantidad);
    fprintf(datos, "Máxima temperatura registrada: %2.2f ºC.\n"     , max_temp);
    fprintf(datos, "Humedad promedio: %2.2f.\n"                     , humedad / cantidad);
    fprintf(datos, "Concentración promedio de CO2: %2.2f PPM.\n"    , co2 / cantidad);
    return fclose(datos);
    
}
