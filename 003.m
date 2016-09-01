# Librería de bisección
# @author   Daniel Cantarín <canta@canta.com.ar>
# @date     20160825

function salida = biseccion( f, a, b )
    a0 = a;
    b0 = b;
    x0 = (a0 + b0) / 2;
    
    
    fa0 = feval( f , a0);
    fx0 = feval( f , x0);
    
    if ( fa0 * fx0 ) < 0
        a1 = a0;
        b1 = x0;
    else
        a1 = x0;
        b1 = b0;
    end
    
    x1 = ( a1 + b1 ) / 2;
    
    salida = x1;
endfunction
