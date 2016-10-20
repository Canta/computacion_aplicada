# Guia #4, Ej #4.
# @author   Daniel Cantarín <canta@canta.com.ar>
# @date     20161021

function horas = calcular_file( f )
    x = struct_file( f );
    s = size(x.tensiones)(2);
    
    horas = s / 60 / 60;
    printf('Se tardaron %f horas en medir las %d tensiones y corrientes.\n', horas, s);
endfunction

