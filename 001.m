# Primer script para GNU Octave.
# 
# @author   Daniel Cantarín <canta@canta.com.ar>
# @date     20160818

x = 1:0.1:10;
y = cos(x);
z = sin(x);

plot(x, y, x, z);
pause();
