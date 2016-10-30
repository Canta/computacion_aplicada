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
pkg load image-acquisition image
running     = true;
screensize  = get(0, 'Screensize');

# Configuraciones de audio
bps         = 16;       % bits per sample
sps         = 8000;     % sample rate [samples/s]
freq        = 1;        % frecuencia del tono [Hz]
amp         = 100;      % amplitud
nsecs       = 1;        % segundos de duración del audio
nsamples    = sps*nsecs;
time        = linspace(0, nsecs, nsamples); # "Espacio linear". Línea.

# Configuraciones de video
largo       = 320
alto        = 240
interval    = 0.001
counter     = 0
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
onda    = sin(time*2*pi*freq)';
player  = audioplayer(onda * amp, sps, bps);
last    = datevec(now());
while running
    img     = getsnapshot(cam);
    gris    = 0.35 * img(:,:,1) + 0.09 * img(:,:,2) + 0.09 * img(:,:,3);
    mask    = ( gris > 128);
    [By,Bx] = find(mask==1); # Pixels blancos
    #bwi     = img.* repmat(mask, [1 1 3]);
    
    if isplaying(player) == false #&& sum(datevec(now()) - last) > nsecs 
    #if sum(datevec(now()) - last) > nsecs 
        last    = datevec(now);
        onda    = sin(time*2*pi*freq);
        player  = audioplayer(onda * amp, sps, bps);
        #playaudio(onda * amp);
        subplot(1,2,1);
        plot( onda * amp );
        try
            play(player);
        catch err
            warning(err.identifier, err.message);
        end_try_catch
    end
    
    subplot(1,2,2);
    imshow( mask );
    
    if length(By) > 20 
        pory = mean(By) * 100 / alto;
        porx = mean(Bx) * 100 / largo;
        amp  = pory;
        freq = porx / 10;
    end
    
    pause( interval );
end
