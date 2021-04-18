#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <list>
#include <math.h>

Mat erosion(Mat imagen, int tam)
{
  cv::Size size(imagen.cols,imagen.rows);
  Mat element = getStructuringElement( MORPH_ELLIPSE , Size( 2*tam + 1, 2*tam+1 ),Point( tam, tam));
  Mat destino = Mat::zeros(size, CV_64F);
  erode( imagen, destino, element );
  return destino;
}
Mat dilatacion(Mat imagen, int tam)
{
  cv::Size size(imagen.cols,imagen.rows);
  Mat element = getStructuringElement( MORPH_ELLIPSE , Size( 2*tam + 1, 2*tam+1 ),Point( tam, tam));
  Mat destino = Mat::zeros(size, CV_64F);
  dilate( imagen, destino, element );
  return destino;
}

Mat cierre(Mat imagen, int dil, int ero)
{
    Mat imgero = erosion(imagen, ero);
    Mat imgdil = dilatacion(imgero, dil);
    return(imgdil);
}
