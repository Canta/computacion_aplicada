# Guia #4, Ej #2.
# @author   Daniel Cantarín <canta@canta.com.ar>
# @date     20161021

function graficar_file( f )
    [a,b] = leer_file( f );
    
    c     = 0:size(a)(2) - 1;
    
    plot(a, c , b , c);
    
endfunction

