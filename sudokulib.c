/**
 * Header para librería de sudoku.
 * 
 * @author  Daniel Cantarín
 * @author  Juan Miguel Lombardi Suzzi
 * @date    20160526
 * 
 * */


#include "sudokulib.h"

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
        j=0;
    }
    
    if (index >= 9 && index <= 17)
    {
        j=9;
    }
    
    if (index >= 18 && index <= 26)
    {
        j=18;
    }
    
    if (index >= 27 && index <= 35)
    {
        j=27;
    }
    
    if (index >= 36 && index <= 44)
    {
        j=36;
    }
    
    if (index >= 45 && index <= 53)
    {
        j=45;
    }
    
    if (index >= 54 && index <= 62)
    {
        j=54;
    }
    
    if (index >= 63 && index <= 71)
    {
        j=63;
    }
    
    if (index >= 72 && index <= 80)
    {
        j=72;
    }
    
    for (i=0; i < 9; i++)
    {
        fila[i] = sudoku[j];
        j++; 
    }
    
}

void get_cuadrante_from_index(char * cuadrante, int index)
{
    int i;
    int j;
    
    if (index == 0 
        || index == 1 
        || index == 2
        || index == 9
        || index == 10 
        || index == 11 
        || index == 18 
        || index == 19 
        || index == 20)
    {
        cuadrante[0] = sudoku[0];
        cuadrante[1] = sudoku[1];
        cuadrante[2] = sudoku[2];
        cuadrante[3] = sudoku[9];
        cuadrante[4] = sudoku[10];
        cuadrante[5] = sudoku[11];
        cuadrante[6] = sudoku[18];
        cuadrante[7] = sudoku[19];
        cuadrante[8] = sudoku[20];
    }
    
    if (index == 3 
        || index == 4 
        || index == 5
        || index == 12
        || index == 13 
        || index == 14 
        || index == 21 
        || index == 22 
        || index == 23)
    {
        cuadrante[0] = sudoku[3];
        cuadrante[1] = sudoku[4];
        cuadrante[2] = sudoku[5];
        cuadrante[3] = sudoku[12];
        cuadrante[4] = sudoku[13];
        cuadrante[5] = sudoku[14];
        cuadrante[6] = sudoku[21];
        cuadrante[7] = sudoku[22];
        cuadrante[8] = sudoku[23];
    }
    
    if (index == 6 
        || index == 7 
        || index == 8
        || index == 15
        || index == 16 
        || index == 17 
        || index == 24 
        || index == 25 
        || index == 26)
    {
        cuadrante[0] = sudoku[6];
        cuadrante[1] = sudoku[7];
        cuadrante[2] = sudoku[8];
        cuadrante[3] = sudoku[15];
        cuadrante[4] = sudoku[16];
        cuadrante[5] = sudoku[17];
        cuadrante[6] = sudoku[24];
        cuadrante[7] = sudoku[25];
        cuadrante[8] = sudoku[26];
    }
    
    if (index == 27 
        || index == 28 
        || index == 29
        || index == 36
        || index == 37 
        || index == 38 
        || index == 45 
        || index == 46 
        || index == 47)
    {
        cuadrante[0] = sudoku[27];
        cuadrante[1] = sudoku[28];
        cuadrante[2] = sudoku[29];
        cuadrante[3] = sudoku[36];
        cuadrante[4] = sudoku[37];
        cuadrante[5] = sudoku[38];
        cuadrante[6] = sudoku[45];
        cuadrante[7] = sudoku[46];
        cuadrante[8] = sudoku[47];
    }
    
    if (index == 30 
        || index == 31 
        || index == 32
        || index == 39
        || index == 40 
        || index == 41 
        || index == 48 
        || index == 49 
        || index == 50)
    {
        cuadrante[0] = sudoku[30];
        cuadrante[1] = sudoku[31];
        cuadrante[2] = sudoku[32];
        cuadrante[3] = sudoku[39];
        cuadrante[4] = sudoku[40];
        cuadrante[5] = sudoku[41];
        cuadrante[6] = sudoku[48];
        cuadrante[7] = sudoku[49];
        cuadrante[8] = sudoku[50];
    }
    
    if (index == 33 
        || index == 34 
        || index == 35
        || index == 42
        || index == 43 
        || index == 44 
        || index == 51 
        || index == 52 
        || index == 53)
    {
        cuadrante[0] = sudoku[33];
        cuadrante[1] = sudoku[34];
        cuadrante[2] = sudoku[35];
        cuadrante[3] = sudoku[42];
        cuadrante[4] = sudoku[43];
        cuadrante[5] = sudoku[44];
        cuadrante[6] = sudoku[51];
        cuadrante[7] = sudoku[52];
        cuadrante[8] = sudoku[53];
    }
    
    if (index == 54 
        || index == 55 
        || index == 56
        || index == 63
        || index == 64 
        || index == 65 
        || index == 72 
        || index == 73 
        || index == 74)
    {
        cuadrante[0] = sudoku[54];
        cuadrante[1] = sudoku[55];
        cuadrante[2] = sudoku[56];
        cuadrante[3] = sudoku[63];
        cuadrante[4] = sudoku[64];
        cuadrante[5] = sudoku[65];
        cuadrante[6] = sudoku[72];
        cuadrante[7] = sudoku[73];
        cuadrante[8] = sudoku[74];
    }
    
    if (index == 57 
        || index == 58 
        || index == 59
        || index == 66
        || index == 67 
        || index == 68 
        || index == 75 
        || index == 76 
        || index == 77)
    {
        cuadrante[0] = sudoku[57];
        cuadrante[1] = sudoku[58];
        cuadrante[2] = sudoku[59];
        cuadrante[3] = sudoku[66];
        cuadrante[4] = sudoku[67];
        cuadrante[5] = sudoku[68];
        cuadrante[6] = sudoku[75];
        cuadrante[7] = sudoku[76];
        cuadrante[8] = sudoku[77];
    }
    
    if (index == 60 
        || index == 61 
        || index == 62
        || index == 69
        || index == 70 
        || index == 71 
        || index == 78 
        || index == 79 
        || index == 80)
    {
        cuadrante[0] = sudoku[0];
        cuadrante[1] = sudoku[1];
        cuadrante[2] = sudoku[2];
        cuadrante[3] = sudoku[9];
        cuadrante[4] = sudoku[10];
        cuadrante[5] = sudoku[11];
        cuadrante[6] = sudoku[18];
        cuadrante[7] = sudoku[19];
        cuadrante[8] = sudoku[20];
    }
    
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
        j = 0;
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
        j=1;
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
        j=2;
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
        j=3;
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
        j=4;
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
        j=5;
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
        j=6;
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
        j=7;
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
        j=8;
    }
    
    for (i=0; i < 9; i++)
    {
        columna[i] = sudoku[j];
        j = j + 9;
    }
}
