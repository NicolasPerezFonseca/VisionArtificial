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
  
  

  int x,y;
  Punto p1=puntos.front();
  puntos.pop_front();
  Punto p2=puntos.front();
  puntos.pop_front();
  Punto p3=puntos.front();
  puntos.pop_front();
  Punto p4=puntos.front();
  puntos.pop_front();

  Ecuacion e1(p1.i,p2.i,p1.j,p2.j);
  Ecuacion e2(p3.i,p4.i,p3.j,p4.j);
  e1.interseccion(&x,&y,e2);
  cout<< "x: "<<x<<" y: "<<y<<endl;

  Point Punto1(p1.j,p1.i);
  Point Punto2(y,x);
  dibujarlinea(imagen,Punto1,Punto2);
  escribirImagen(imagen,"lineas");
  
  return( 0 );
  
}


/* To DO 
 1. Calcular las scuacionesd de las lineas para econtrar el horizonte y=mx+b
 2. DIbujar la Linea 
*/