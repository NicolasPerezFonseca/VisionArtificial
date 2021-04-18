#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "manejador.hpp"

using namespace cv;
using namespace std;

Mat binarizacion(Mat imagen){
    Mat imgGray,imgBlur,imgCanny,imageErode;
    cvtColor(imagen,imgGray,COLOR_BGR2GRAY);
    GaussianBlur(imagen,imgBlur,Size(3,3),3,0);
    Canny(imgBlur,imgCanny,35,75);
    return imgCanny;
}