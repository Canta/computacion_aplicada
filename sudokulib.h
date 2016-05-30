/**
 * Header para librería de sudoku.
 * 
 * @author  Daniel Cantarín
 * @author  Juan Miguel Lombardi Suzzi
 * @date    20160526
 * 
 * */

void get_casilleros_from_index( char * unicos, int index);
char is_completed( );
void get_cuadrante_from_index( char * cuadrante, int index);
void get_fila_from_index( char * fila, int index);
void get_columna_from_index( char * columna, int index );

int sudoku[81];

