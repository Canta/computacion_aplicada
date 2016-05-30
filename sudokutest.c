/**
 * Pruebas para la librería de sudoku.
 * 
 * @author  Daniel Cantarín
 * @date    20160529
 * 
 * */

#include <stdio.h>
#include "sudokulib.h"
#include "sudokulib.c"

int main() 
{
    FILE   * archivo;
    char   lista[9]    = {0};
    int    i1          = 0;
    int    i2          = 0;
    int    i3          = 0;
    int    encontrados = 0;
    int    not_found   = 0;
    int    iteraciones = 0;
    archivo = fopen("grilla_sudoku_test.txt", "r");
    
    printf("\nleyendo sudoku...\n");
    while ( feof(archivo) == 0 ) {
        fscanf( archivo, "%d", &sudoku[i1] );
        printf("%d\n",sudoku[i1]);
        i1++;
        if (i1 >= 81){
            break;
        }
    }
    printf("...listo.\n");
    
    //get_columna_from_index( lista, 23);
    get_fila_from_index( lista, 50);
    //get_cuadrante_from_index( lista, 40);
    
    for( i1 = 0; i1 < 9; i1++ ) {
        printf( "%d\n", lista[i1]);
    }
    
    return 0;
}
