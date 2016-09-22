# Abrir archivos.
# @author   Daniel Cantarín <canta@canta.com.ar>
# @date     20160915


fid = fopen( "temperaturas_bsas.txt","r");
i   = 0;
x   = 1:1;

while i < 12
    mes  = fscanf( fid, "%s", 1);
    fila = fscanf( fid, "%f", 3);
    otro = fscanf( fid, "%f", 6);
    
    
    i++;
    x(i) = i;
    maximos(i)   = max(fila);
    minimos(i)   = min(fila);
    promedios(i) = mean(fila);
    
    humedad(i)     = otro(1);
    viento(i)      = otro(2);
    claro(i)       = otro(3);
    cubierto(i)    = otro(4);
    lluvia(i)      = otro(5);
    lluvia_mes(i)  = otro(6);
    
end
fclose(fid);

subplot( 2, 2, 1);
plot(   x, maximos, 
        x, minimos, 
        x, promedios);
title ("Temperaturas");
legend( "Máximas", 
        "Minimas", 
        "Medias");

subplot( 2, 2, 2);

plot(   x, humedad,
        x, viento);
title("Pluscuamperfectuidad");
legend( "Humedad relativa",
        "Viento");

subplot( 2, 2, 3);       

plot(   x, claro,
        x, cubierto);
title("Cielo");
legend( "Claro",
        "Cubierto");

subplot( 2, 2, 4);

plot( x, lluvia_mes,
      x, lluvia,
      x, lluvia_mes ./ lluvia );
title("Precipitaciones");
legend( "cm3 mensuales",
        "Días en el mes",
        "Promedio");
