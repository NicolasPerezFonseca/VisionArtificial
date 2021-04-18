#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "manejador.hpp"
#include "binarizacion.hpp"
#include "transformaciones.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
  Mat imagen = leerImagen(argv[1]);
  Mat res = binarizacion(imagen);
  res = cierre(res, 30, 30);
  escribirImagen(res,"resultado");
  return( 0 );
}
