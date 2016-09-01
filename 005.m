# Usos de loops.
#
# @author   Daniel Cantarín <canta@canta.com.ar>
# @date     20160901

function salida = punto_fijo_1( f, x0 , n)
    x1     = 0;
    for i=1:n
        x1 = feval(f, x0);
        x0 = x1;
    end
    salida = x1;
endfunction


function salida = punto_fijo_2( f, x0 , cota)
    x1     = 0;
    
    while abs(x0 - x1) > cota
        x1 = feval(f, x0);
        x0 = x1;
    end
    #whos;
    salida = x1;
endfunction


function salida = punto_fijo_3( f, x0 , n)
    for i=1:n
        x1 = feval(f, x0);
        x0 = x1;
        vecx(i) = i;
        vecy(i) = x0;
    end
    plot(vecx, vecy);
    
    salida = x1;
endfunction
