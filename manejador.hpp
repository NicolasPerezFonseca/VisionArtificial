#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Mat leerImagen(string nombre);
void escribirImagen(Mat imagen, string nombre);

Mat leerImagen(string nombre){
   
   Mat imagen;
   imagen= imread(nombre,1);
   
  if ( !imagen.data )
  {
    cerr << "Error: no se encontro la imagen :(" << endl;
  }
  return imagen;
}

void escribirImagen(Mat imagen, string nombre){
    imwrite(nombre + ".jpg",imagen);
}