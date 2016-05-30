/**
 * Programa para resolver sudokus de 9x9.
 * 
 * @author  Daniel Cantarín
 * @date    20160526
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
    archivo = fopen("grilla_sudoku.txt", "r");
    
    printf("\nleyendo sudoku...\n");
    while ( feof(archivo) == 0 ) {
        fscanf( archivo, "%d", &sudoku[i1] );
        printf("%d\n",sudoku[i1]);
        i1++;
    }
    printf("...listo.\n");
    
    fclose(archivo);
    
    while (is_completed() == 0) 
    {
        iteraciones++;
        printf("\nIteración #%d.\n", iteraciones);
        for (i1 = 0; i1 < 81; i1++)
        {
            printf(" %d", sudoku[i1]);
            
            if (sudoku[i1] == 0 )
            {
                get_casilleros_from_index( lista, i1 );
                /*
                printf("\nlista: ");
                for (i3 = 0; i3 < 9; i3++)
                {
                    printf( "%d ", lista[i3] );
                }
                printf("\n");
                */
                not_found   = 0;
                encontrados = 0;
                for (i2 = 0; i2 < 9 ; i2++) {
                    if (lista[i2] == 0) {
                        encontrados++;
                        not_found = i2 + 1;
                    }
                }
                
                if (encontrados == 8) {
                    sudoku[i1] = not_found;
                }
            }
            
            if ( (i1 + 1) % 9 == 0 ) {
                printf("\n");
            }
        }
        
    }
    
    printf("\nSudoku resuelto.\n");
    
    return 0;
}
