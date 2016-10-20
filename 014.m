# Guia #4, Ej #3.
# @author   Daniel Cantarín <canta@canta.com.ar>
# @date     20161021

function salida = struct_file( f )
    
    x.dia   = 0;
    x.mes   = 0;
    x.anio  = 0;
    x.hora  = 0;
    
    x.tensiones  = [];
    x.corrientes = [];
    
    fid = fopen( f ,'r');
    ten = [];
    cor = [];
    i   = 0;
    
    fscanf( fid, '%s', 1 );
    fscanf( fid, '%s', 1 );
    tmp = fscanf( fid, '%s', 1 );
    [x.dia, x.mes, x.anio]  = strsplit( tmp, '-'){1,:};
    x.hora = fscanf( fid, '%s', 1 );
    fscanf( fid, '%s', 2 );
    
    while feof(fid) == 0
      i   = i + 1;
      tmp = fscanf( fid, '%f', 2);
      #tmp
      if size(tmp) > 0
        x.tensiones(i)   = tmp(1);
        x.corrientes(i)  = tmp(2);
      end
    end
    
    salida = x;
endfunction

