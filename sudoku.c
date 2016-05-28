/**
 * Programa para resolver sudokus de 9x9.
 * 
 * @author  Daniel Cantarín
 * @date    20160526
 * 
 * */

#include <stdio.h>

void get_casilleros_from_index( char * unicos, int index);
char is_completed( );
void get_cuadrante_from_index( char * cuadrante, int index);
void get_fila_from_index( char * fila, int index);
void get_columna_from_index( char * columna, int index );

int sudoku[81];

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

void get_casilleros_from_index( char * unicos, int index ) 
{
    
    char cuadrante[9]   = {0};
    char fila[9]        = {0};
    char columna[9]     = {0};
    int i               = 0;
    int coso            = 0;
    
    //printf("loop unicos\n");
    
    get_cuadrante_from_index( cuadrante, index );
    get_fila_from_index( fila, index );
    get_columna_from_index( columna, index );
    
    for ( i = 0; i < 9; i++) {
        unicos[i] = 0;
    } 
    
    //printf("loop gordo\n");
    for ( i = 0; i < 9; i++) {
        
        //printf("loop cuadrantes[%d] (%d)\n", i,cuadrante[i]);
        coso = cuadrante[i];
        if ( cuadrante[i] > 0 ) {
            unicos[ cuadrante[i] -1 ] = 1;
        }
        //printf("loop filas[%d] (%d)\n", i,fila[i]);
        
        coso = fila[i];
        if ( fila[i] > 0 ) {
            unicos[ fila[i] - 1 ] = 1;
        }
        //printf("loop columnas[%d] (%d)\n", i,columna[i]);
        
        coso = columna[i];
        if ( columna[i] > 0 ) {
            unicos[ columna[i] - 1 ] = 1;
        }
    }
    
}

void get_fila_from_index(char * fila, int index)
{
    int i;
    int j;
    
    if (index >= 0 && index <= 8)
    {
        for (i=0; i < 9; i++)
        {
            j=0;
            fila[i] = sudoku[j];
            j++; 
        }
    }
    
    if (index >= 9 && index <= 17)
    {
        for (i=0; i < 9; i++)
        {
            j=9;
            fila[i] = sudoku[j];
            j++; 
        }
    }
    
    if (index >= 18 && index <= 26)
    {
        for (i=0; i < 9; i++)
        {
            j=18;
            fila[i] = sudoku[j];
            j++; 
        }
    }
    
    if (index >= 27 && index <= 35)
    {
        for (i=0; i < 9; i++)
        {
            j=27;
            fila[i] = sudoku[j];
            j++; 
        }
    }
    
    if (index >= 36 && index <= 44)
    {
        for (i=0; i < 9; i++)
        {
            j=36;
            fila[i] = sudoku[j];
            j++; 
        }
    }
    
    if (index >= 45 && index <= 53)
    {
        for (i=0; i < 9; i++)
        {
            j=45;
            fila[i] = sudoku[j];
            j++; 
        }
    }
    
    if (index >= 54 && index <= 62)
    {
        for (i=0; i < 9; i++)
        {
            j=54;
            fila[i] = sudoku[j];
            j++; 
        }
    }
    
    if (index >= 63 && index <= 71)
    {
        for (i=0; i < 9; i++)
        {
            j=63;
            fila[i] = sudoku[j];
            j++; 
        }
    }
    
    if (index >= 72 && index <= 80)
    {
        for (i=0; i < 9; i++)
        {
            j=72;
            fila[i] = sudoku[j];
            j++;       
        }
    }
    /*
    for (i=0; i < 9; i++)
    {
        printf("fila %d: %d\n", i, fila[i]);
    }
    */
}

void get_columna_from_index(char * columna, int index)
{
    int i;
    int j;
    
    if (index == 0 
        || index == 9 
        || index == 18 
        || index == 27 
        || index == 36 
        || index == 45 
        || index == 54 
        || index == 63 
        || index == 72)
    {
        for (i=0; i < 9; i++)
        {
            j=0;
            columna[i] = sudoku[j];
            j = j + 9;
        }
    }
    
    if (index == 1 
        || index == 10 
        || index == 19 
        || index == 28 
        || index == 37 
        || index == 46 
        || index == 55 
        || index == 64 
        || index == 73)
    {
        for (i=0; i < 9; i++)
        {
            j=1;
            columna[i] = sudoku[j];
            j = j + 9;
        }
    }
    
    if (index == 2 
        || index == 11 
        || index == 20 
        || index == 29 
        || index == 38 
        || index == 47 
        || index == 56 
        || index == 65 
        || index == 74)
    {
        for (i=0; i < 9; i++)
        {
            j=2;
            columna[i] = sudoku[j];
            j = j + 9;
        }
    }
    
    if (index == 3 
        || index == 12 
        || index == 21 
        || index == 30 
        || index == 39 
        || index == 48 
        || index == 57 
        || index == 66 
        || index == 75)
    {
        for (i=0; i < 9; i++)
        {
            j=3;
            columna[i] = sudoku[j];
            j = j + 9;
        }
    }
    
    if (index == 4 
        || index == 13 
        || index == 22 
        || index == 31 
        || index == 40 
        || index == 49 
        || index == 58 
        || index == 67 
        || index == 76)
    {
        for (i=0; i < 9; i++)
        {
            j=4;
            columna[i] = sudoku[j];
            j = j + 9;
        }
    }
    
    if (index == 5 
        || index == 14 
        || index == 23 
        || index == 32 
        || index == 41 
        || index == 50 
        || index == 59 
        || index == 68 
        || index == 77)
    {
        for (i=0; i < 9; i++)
        {
            j=5;
            columna[i] = sudoku[j];
            j = j + 9;
        }
    }
    
    if (index == 6 
        || index == 15 
        || index == 24 
        || index == 33 
        || index == 42 
        || index == 51 
        || index == 60 
        || index == 69 
        || index == 78)
    {
        for (i=0; i < 9; i++)
        {
            j=6;
            columna[i] = sudoku[j];
            j = j + 9;
        }
    }
    
    if (index == 7 
        || index == 16 
        || index == 25 
        || index == 34 
        || index == 43 
        || index == 52 
        || index == 61 
        || index == 70 
        || index == 79)
    {
        for (i=0; i < 9; i++)
        {
            j=7;
            columna[i] = sudoku[j];
            j = j + 9;
        }
    }
    
    if (index == 8
        || index == 17 
        || index == 26 
        || index == 35 
        || index == 44 
        || index == 52 
        || index == 62 
        || index == 71 
        || index == 80)
    {
        for (i=0; i < 9; i++)
        {
            j=8;
            columna[i] = sudoku[j];
            j = j + 9;
        }
    }
    
    /*
    for (i=0; i < 9; i++)
    {
        printf("columna %d: %d\n", i, (int) columna[i]);
    }
    */
}


void get_cuadrante_from_index( char * cuadrante, int index ) {
    char i = 0;
    
    for ( i = 0; i < 9; i++) {
        cuadrante[i] = 0;
    } 
    
}

char is_completed() 
{
    char ret = 1;
    char i   = 0;
    
    for (i = 0; i < 81; i++)
    {
        if ( sudoku[i] == 0 ) {
            ret = 0;
            break;
        }
    }
    
    //printf("is completed %d.\n",ret);
    return ret;
}
