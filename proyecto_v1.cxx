#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "manejador.hpp"
#include "binarizacion.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
  Mat imagen = leerImagen(argv[1]);
  Mat res = binarizacion(imagen);
  escribirImagen(res,"resultado");
  return( 0 );
}
