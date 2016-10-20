# Guia #4, Ej #1.
# @author   Daniel Cantarín <canta@canta.com.ar>
# @date     20161021

function [ten, cor] = leer_file( f )
    fid = fopen( f ,'r');
    ten = [];
    cor = [];
    i   = 0;
    
    fscanf( fid, '%s', 1 );
    fscanf( fid, '%s', 3 );
    fscanf( fid, '%s', 2 );
    
    
    while feof(fid) == 0
      i   = i + 1;
      tmp = fscanf( fid, '%f', 2);
      #tmp
      if size(tmp) > 0
        ten(i)  = tmp(1);
        cor(i)  = tmp(2);
      end
    end
    
endfunction

