#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "manejador.hpp"
#include "binarizacion.hpp"
#include "transformaciones.hpp"
#include "encontrarEsquinas.hpp"
#include "linea.hpp"
#include <list>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
  Mat imagen = leerImagen(argv[1]);
  cout<<"binarizando..."<<endl;
  Mat res = binarizacion(imagen);
  escribirImagen(res,"binarizado");
  res = cierre(res, 10, 10);

  cout<<"cerrando..."<<endl;
  escribirImagen(res,"cierre");
  res = erosion(res,10);

  cout<<"calculando esquinas..."<<endl;
  list<Punto> puntos;
  Mat esquinas = encontrarEsquinas(res, 180, &puntos);
  escribirImagen(esquinas,"esquinas");

  for(Punto p:puntos)
  {
    cout<<"fila: "<< p.i<<" columna: "<<p.j<<endl;
  }
  Point Punto1(puntos.front().j,puntos.front().i);
  Point Punto2(puntos.back().j,puntos.back().i);
  
 
  dibujarlinea(imagen,Punto1,Punto2);
  escribirImagen(imagen,"lineas");
  return( 0 );
  
}
/* To DO 
 1. Calcular las scuacionesd de las lineas para econtrar el horizonte y=mx+b
 2. DIbujar la Linea 
*/