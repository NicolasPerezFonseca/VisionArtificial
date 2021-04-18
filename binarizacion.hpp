#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <list>
#include <math.h>

using namespace cv;
using namespace std;

int MetodoOtsu(float ratio[]){
  
  float  media[256]={0.0};
  float  varianza[256]={0.0};
  float  probabilidad[256]={0.0};
  int    umbral=0;
  float  vmax=0.0;
  probabilidad[0]=ratio[0];
  
  for(int a=1;a<256;a++){
      probabilidad[a]=probabilidad[a-1]+ratio[a];
      media[a]=media[a-1]+(a*ratio[a]);
  }
  for(int b=0;b<256;b++){
      if(probabilidad[b]!=0 && probabilidad[b]!=1){
         varianza[b]=pow(media[255]*probabilidad[b]-media[b],2)/(probabilidad[b]*(1.0-	   probabilidad[b]));
        
       }
       else {
       varianza[b]=0.0;
   
       }
       if(varianza[b]>vmax){
         vmax=varianza[b];
         umbral=b;
       }
       
         
  }
  return umbral;
}

Mat binarizcion(Mat imagen)
{
  Size size((int)(imagen.cols), (int)(imagen.rows));
  Mat imgGris= Mat::zeros(size, CV_64F );
  int arreglo[256]={0};
  float ratio[256]={0.0};
  cvtColor(imagen,imgGris,COLOR_BGR2GRAY);
  MatIterator_<uchar> Itini,ItFin;
  Itini=imgGris.begin<uchar > ();
  ItFin=imgGris.end<uchar > ();
  for(int i=0;Itini!= ItFin; ++Itini)
  {
    float valor=(float)(*Itini);
    arreglo[(int)(valor)]+=1;
  }
  for(int a=0;a<256;a++){
   ratio[a]=(float)(arreglo[a])/(imgGris.cols*imgGris.rows);
   }
   
   int Outsu=MetodoOtsu(ratio);
   
  Itini=imgGris.begin<uchar > ();
  ItFin=imgGris.end<uchar > ();
  for(int i=0;Itini!= ItFin; ++Itini)
  {  
    float valor=(float)(*Itini);
    if(valor<Outsu){
       (*Itini)=0;
    }
  }
  Itini=imgGris.begin<uchar > ();
  ItFin=imgGris.end<uchar > ();
  for(int i=0;Itini!= ItFin; ++Itini)
  {  
    float valor=(float)(*Itini);
    if(valor>=Outsu){
       (*Itini)=255;
    }
  }
  return (imgGris);
}

