# Abrir archivos.
# @author   Daniel Cantarín <canta@canta.com.ar>
# @date     20161013

clear all;
clc;

fid = fopen( "tensiones.txt","r");
i   = 0;
x   = 1:1;
min = [];
max = [];

tiempos = [];
titulos = fscanf( fid, "%s", 3 );


while feof(fid) == 0
    i   = i + 1;
    tmp = fscanf( fid, "%f", 3);
    if size(tmp) > 0
      min(i)    = tmp(1);
      max(i)    = tmp(2);
      tiempo(i) = tmp(3);
    end
end
fclose(fid);

if size(tiempo)(2) > 0
  limite = tiempo(1);
  
  i = 1;
  X = [];
  Y = [];
  t = 0;
  #limite
  
  while t < limite
    
    if i > 2
      last = tiempo(i-1) + tiempo(i);
    elseif i > 1
      last = tiempo(i);
    else
      last = 0;
    end
    
    dV     = max(i) - min(i);
    Y(t+1) = ( ( dV / tiempo(i) ) * (t - last) ) + min(i);
    X(t+1) = t;
    
    if (t + 1 == limite) && size(tiempo)(2) > i
      i      = i + 1;
      limite = limite + tiempo(i);
      #limite
    end
    
    t = t + 1;
  end
  plot(X,Y)
end
