#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;


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

Mat binarizacion(Mat imagen){
    Mat imgGray,imgBlur,imgCanny,imageErode,imgDia;
    cvtColor(imagen,imgGray,COLOR_BGR2GRAY);
    GaussianBlur(imgGray,imgBlur,Size(3,3),3,0);
    Canny(imgBlur,imgCanny,35,75);
    imgDia = dilatacion(imgCanny,20);
    imgDia =  erosion(imgDia,2);
    return imgCanny;
}
