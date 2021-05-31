#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


class Ecuacion{
    int x1,x2,y1,y2;
    float m;
    float b;
    public:
    Ecuacion(int x1,int x2, int y1,int y2){
        this->x1=x1;
        this->x2=x2;
        this->y1=y1;
        this->y2=y2;
        this->m=((y2-y1)/(x2-x1));
        this->b=y1-(m*x1);
    }
    void interseccion(int *x, int *y,Ecuacion linea2){
         (*x)=((linea2.b - this->b)/(this->m - linea2.m));
         (*y)=(this->m*(*x)+this->b);
    }

};



void dibujarlinea( Mat img, Point start, Point end )
{
  int thickness = 10;
  int lineType = LINE_8;
  line( img,start,end,Scalar( 0, 0, 0 ),thickness,lineType );
}
list<Punto> extraerEsquinas(list<Punto> puntos){
    //Point Punto1(puntos.front().j,puntos.front().i);
    Punto inicial = puntos.front();
    Punto finali = puntos.back();
    list<Punto> retorno;
    int diferencia = (finali.i-inicial.i)/2;
    Punto min1=inicial, min2=finali,max1 = inicial, max2 = finali; 
    while(!puntos.empty())
    {
        Punto p= puntos.front();
        if(p.i<inicial.i+diferencia){
            if(p.j<min1.j)
            {
                min1.i=p.i;
                min1.j=p.j;
            }
            if(p.j>max1.j)
            {
                max1.i=p.i;
                max1.j=p.j;
            }
        }
        else{
            if(p.j<min2.j)
            {
                min2.i=p.i;
                min2.j=p.j;

            }
            if(p.j>max2.j)
            {
                max2.i=p.i;
                max2.j=p.j;
            }
        }
        puntos.pop_front();
    }
    retorno.push_back(inicial);
    retorno.push_back(min1);
    retorno.push_back(max1);
    retorno.push_back(min2);
    retorno.push_back(max2);
    retorno.push_back(finali);
    return retorno;

}