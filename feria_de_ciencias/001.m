# Pseudo theremin de captura de imágenes.
# 
# @author Daniel Cantarín <canta@canta.com.ar>
# @author Bárbara Menares <barbara.menares@gmail.com>
# @date 20161029
# @requires image-acquisition
#
# Basado en:
# https://tty1.net/blog/2009/audio-with-gnu-octave_en.html
# http://wiki.octave.org/Image_acquisition_package

# Configuraciones de la aplicación en general
clc;
clear all;
close all;
pkg load image-acquisition
running     = true;
screensize  = get(0, 'Screensize');

# Configuraciones de audio
bps         = 16;       % bits per sample
sps         = 8000;     % sample rate [samples/s]
freq        = 4;        % frecuencia del tono [Hz]
nsecs       = 0.2;      % segundos de duración del audio
nsamples    = sps*nsecs;

time        = linspace(0, nsecs, nsamples); # "Espacio linear". Línea.
onda        = sin(time*2*pi*freq)';         # Onda parametrizada.

# Configuraciones de video
largo       = 320
alto        = 240
cam         = videoinput("v4l2", "/dev/video0")
vacio       = zeros(alto, largo);
semivacio   = zeros(alto, largo/2);
set(cam, "VideoFormat", "RGB3");
set(cam, "VideoResolution", [largo alto]);
set(cam, "brightness", 128);
start(cam);

printf("\nIniciando cámara...\n");
fflush(stdout);
pause(3)
printf("...listo.\n");
fflush(stdout);
figure('Position',[50,250,400,400]);

# Loop principal
set(gcf, 'Position', [ screensize(3)/4, screensize(4)/4, screensize(3)/2, screensize(4)/2]);
while running
    img = getsnapshot(cam);
    #subplot(2,3,2);
    #a   = imshow( img );
    #title('Captura:');
    
    # Separamos dos mitades de la imagen
    A=img(:,  1             :   largo/2     ,:);
    B=img(:,  largo/2 + 1   :   largo       ,:);
    
    # A la vamos a usar para la amplitud.
    # B la vamos a usar para la frecuencia.
    subplot(1,2,1);
    grayval = 0.35*A(:,:,1) + 0.09*A(:,:,2) + 0.09*A(:,:,3);
    mask    = (grayval > 128);
    imshow( A.* repmat(mask, [1 1 3]) );
    
    subplot(1,2,2);
    grayval = 0.09*B(:,:,1) + 0.09*B(:,:,2) + 0.35*B(:,:,3);
    mask    = (grayval > 128);
    imshow( B.* repmat(mask, [1 1 3]) );
    
    pause(0.01);
end
