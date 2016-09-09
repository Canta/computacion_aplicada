# Derivada y otras funciones.
# @author   Daniel Cantarín <canta@canta.com.ar>
# @date     20160908

function salida = secante_aux( f, a, b )
    
    f0 = feval( f , a);
    f1 = feval( f , b);
    
    c  = (a - b) + 0.001;
    
    salida = (f0 - f1) / c;
endfunction


function salida = secante( f, a, b , cota )
    
    i      = 1;
    x0     = a;
    ret(i) = b;
    comp   = abs(a - b);
    
    while comp > cota
        i      = i + 1;
        f0     = feval( f , a);
        f1     = feval( "secante_aux" , f, a, b) + 0.001;
        b      = a - ( f0 / f1 );
        comp   = abs(a - b);
        a      = b;
        if (b == 0)
            comp = cota;
        end
        ret(i) = b;
    end
    
    salida = ret;
endfunction


function salida = newton( x0, f, f1, cota )
    
    x1     = 0;
    i      = 1;
    ret(i) = x0;
    comp   = cota  * 100;
    
    while comp > cota
        i       = i + 1;
        x1      = x0 - ( feval(f, x0) / feval( f1, x0 ) );
        comp    = abs(x0 - x1);
        x0      = x1;
        ret(i)  = x1;
    end
    
    salida = ret;
    
endfunction

function salida = menos_seno( a )
    
    salida = sin( a ) * (-1);
    
endfunction
