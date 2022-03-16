#include "bruta.h"

void line1(int x0, int x1, int y0, int y1){
  long double b, m, y, x, my, mx;
  int i;

  my = (y1 - y0); //Se usa para evitar problemas de punto flotante
  mx = (x1 - x0); //Se usa para evitar problemas de punto flotante
  m = my/mx;
  b = y0 - m*x0;
  x = x1-x0; x = fabs(x); 
  y = y1-y0; y = fabs(y); 
  if (x>=y){  //Se realizan comparaciones para averiguar sobre cual eje ir pintando y en que dirección pintar
    if (x0 > x1){
      for (i = x1; i<=x0; i++){ //Pinta hacia la izquierda usando el eje x como base
        y = m*i + b;            //Se utiliza la fórmula para encontrar y
        plot(i, round(y));
      }
    }
    else{
      for (i = x0; i<=x1; i++){ //Pinta hacia la derecha usando el eje x como base
        y = m*i + b;            //Se utiliza la fórmula para encontrar y
        plot(i, round(y));
      }
    }
  }
  else{
    if (y0 > y1){
      for (i = y1; i<=y0; i++){ //Pinta hacia la izquierda usando el eje y como base
        y = (i - b); //Se usa para evitar problemas de punto flotante
        x = y/m;                //Se utiliza la fórmula para encontrar x
        plot(round(x), i);
      }
    }
    else{
      for (i = y0; i<=y1; i++){ //Pinta hacia la derecha usando el eje y como base
        y = (i - b); //Se usa para evitar problemas de punto flotante
        x = y/m;                //Se utiliza la fórmula para encontrar x
        plot(round(x), i);
      }
    }
  }
};

void line1_plotless(int x0, int x1, int y0, int y1){
  long double b, m, y, x, my, mx;
  int i;

  my = (y1 - y0); //Se usa para evitar problemas de punto flotante
  mx = (x1 - x0); //Se usa para evitar problemas de punto flotante
  m = my/mx;
  b = y0 - m*x0;
  x = x1-x0; x = fabs(x); 
  y = y1-y0; y = fabs(y); 

  if (x>=y){  //Se realizan comparaciones para averiguar sobre cual eje ir pintando y en que dirección pintar
    if (x0 > x1){
      for (i = x1; i<=x0; i++){ //Pinta hacia la izquierda usando el eje x como base
        y = m*i + b;            //Se utiliza la fórmula para encontrar y
        plot_nothing(i, round(y));
      }
    }
    else{
      for (i = x0; i<=x1; i++){ //Pinta hacia la derecha usando el eje x como base
        y = m*i + b;            //Se utiliza la fórmula para encontrar y
        plot_nothing(i, round(y));
      }
    }
  }
  else{
    if (y0 > y1){
      for (i = y1; i<=y0; i++){ //Pinta hacia la izquierda usando el eje y como base
        y = (i - b); //Se usa para evitar problemas de punto flotante
        x = y/m;                //Se utiliza la fórmula para encontrar x
        plot_nothing(round(x), i);
      }
    }
    else{
      for (i = y0; i<=y1; i++){ //Pinta hacia la derecha usando el eje y como base
        y = (i - b); //Se usa para evitar problemas de punto flotante
        x = y/m;                //Se utiliza la fórmula para encontrar x
        plot_nothing(round(x), i);
      }
    }
  }
};