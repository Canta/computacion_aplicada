# Manipular imágenes.
# @author   Daniel Cantarín <canta@canta.com.ar>
# @date     20160922

clear all;
clc;

imagen  = imread("imagen.jpg");
tamanio = size(imagen);
largo   = tamanio(1);
alto    = tamanio(2);
canales = tamanio(3);
vacio   = zeros(largo, alto);


subplot(2,2,1);
imshow(imagen);
title("Original");

subplot(2,2,2);
roja = cat(3, imagen(:,:,1), vacio, vacio);
imshow( roja );
title("Roja");

subplot(2,2,3);
verde = cat(3, vacio, imagen(:,:,2), vacio);
imshow(verde);
title("Verde");

subplot(2,2,4);
azul = cat(3, vacio, vacio, imagen(:,:,3));
imshow(azul);
title("Azul");
