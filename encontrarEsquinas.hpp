#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <list>
using namespace cv;
using namespace std;

struct Punto
{
    int i;
    int j;
};
Mat encontrarEsquinas( Mat imagen,int thresh, list<Punto> *puntos)
{
    
    int max_thresh = 255;
    int blockSize = 2;
    int apertureSize = 3;
    double k = 0.04;
    Mat dst = Mat::zeros( imagen.size(), CV_32FC1 );
    cornerHarris( imagen, dst, blockSize, apertureSize, k );
    Mat dst_norm, dst_norm_scaled;
    normalize( dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat() );
    convertScaleAbs( dst_norm, dst_norm_scaled );
    for( int i = 0; i < dst_norm.rows ; i++ )
    {
        for( int j = 0; j < dst_norm.cols; j++ )
        {
            if( (int) dst_norm.at<float>(i,j) > thresh )
            {
                circle( dst_norm_scaled, Point(j,i), 5,  Scalar(0), 2, 8, 0 );
                Punto nuevo;
                nuevo.i=i;
                nuevo.j=j;
                puntos->push_back(nuevo);
            }
        }
    }
    
    return( dst_norm_scaled );
}