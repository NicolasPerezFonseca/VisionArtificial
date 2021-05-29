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
  escribirImagen(res,"binarizado");
  res = cierre(res, 10, 10);
  cout<<"cerrado..."<<endl;
  escribirImagen(res,"cierre");
  return( 0 );
}
