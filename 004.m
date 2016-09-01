# Ejecución de bisección
# 
# @author   Daniel Cantarín <canta@canta.com.ar>
# @date     20160824

a = 0;
b = 2;

step = (b - a) / 10;
vecY = 0:step:10;
vecX(1) = 0;

for i = 1:length(vecY)
    vecX(i) = biseccion( 'sin', i, 10 );
end

plot(vecX, vecY);
