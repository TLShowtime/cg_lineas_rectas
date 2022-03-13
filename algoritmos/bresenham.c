#include "bresenham.h"

void line4(int x0, int x1, int y0, int y1){
  int Delta_E, Delta_NE, Delta_N, Delta_NO, x, xAbs, d;
  int Delta_O, Delta_SO, Delta_S, Delta_SE, y, yAbs;

  d = 2*(y1-y0) - (x1-x0); //Valor que determina que pixel se debe pintar de acuerdo a su signo
  x = x0; y = y0;
  plot(x, y);

  if (x0 <= x1){
    xAbs = x1 - x0;
  }else{
    xAbs = x0 - x1;
  }
  if (y0 <= y1){
    yAbs = y1 - y0;
  }else{
    yAbs = y0 - y1;
  }
  
  if (x0<=x1){
    if (y0<=y1){
      Delta_NE  =  2 * ((y1 - y0) - (x1 - x0)); //Valor para avanzar un pixel hacia arriba y uno a la derecha
      if (xAbs>=yAbs){ //octante 1
        Delta_E   =  2 * (y1 - y0);                 //Valor para avanzar un pixel a la derecha
        while (x < x1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d <= 0){
            x++;
            d = d + Delta_E;
          }
          else{
            x++; y++;
            d = d + Delta_NE;
          }
          plot(x,y);
        }
      }
      else{ //octante 2
        Delta_N  = -2 * (x1 - x0);             //Valor para avanzar un pixel hacia arriba
        while (y < y1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d >= 0){
            y++;
            d = d + Delta_N;
          }
          else{
            x++; y++;
            d = d + Delta_NE;
          }
          plot(x,y);
        }
      }
    }
    else{
      Delta_SE  =  2 * ((y1 - y0) + (x1 - x0)); //Valor para avanzar un pixel hacia abajo y uno a la derecha
      if (xAbs<=yAbs){ //octante 7
        Delta_S   =  2 * (x1 - x0);             //Valor para avanzar un pixel hacia abajo
        while (y > y1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d <= 0){
            y--;
            d = d + Delta_S;
          }
          else{
            x++; y--;
            d = d + Delta_SE;
          }
          plot(x,y);
        }
      }
      else{ //octante 8
        Delta_E   =  2 * (y1 - y0);                 //Valor para avanzar un pixel a la derecha
        while (x < x1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d >= 0){
            x++;
            d = d + Delta_E;
          }
          else{
            x++; y--;
            d = d + Delta_SE;
          }
          plot(x,y);
        }
      }
    }
  }
  else{
    if (y0<=y1){
      Delta_NO  = -2 * ((y1 - y0) + (x1 - x0)); //Valor para avanzar un pixel hacia arriba y uno a la izquierda
      if (yAbs>=xAbs){ //octante 3
        Delta_N   = -2 * (x1 - x0);             //Valor para avanzar un pixel hacia arriba
        while (y < y1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d <= 0){
            y++;
            d = d + Delta_N;
          }
          else{
            x--; y++;
            d = d + Delta_NO;
          }
          plot(x,y);
        }
      }    
      else{ //octante 4
        Delta_O   = -2 * (y1 - y0);                 //Valor para avanzar un pixel a la izquierda
        while (x > x1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d >= 0){
            x--;
            d = d + Delta_O;
          }
          else{
            x--; y++;
            d = d + Delta_NO;
          }
          plot(x,y);
        }
      }
    }
    else{
      Delta_SO  = -2 * ((y1 - y0) - (x1 - x0)); //Valor para avanzar un pixel hacia abajo y uno a la izquierda
      if (xAbs>=yAbs){ //octante 5
        Delta_O   = -2 * (y1 - y0);                 //Valor para avanzar un pixel a la izquierda
        while (x > x1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d <= 0){
            x--;
            d = d + Delta_O;
          }
          else{
            x--; y--;
            d = d + Delta_SO;
          }
          plot(x,y);
        }
      }
      else{ //octante 6
        Delta_S   =  2 * (x1 - x0);               //Valor para avanzar un pixel hacia abajo
        while (y > y1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d >= 0){
            y--;
            d = d + Delta_S;
          }
          else{
            x--; y--;
            d = d + Delta_SO;
          }
          plot(x,y);
        }
      }
    }
  }
};

void line4_plotless(int x0, int x1, int y0, int y1){
  int Delta_E, Delta_NE, Delta_N, Delta_NO, x, xAbs, d;
  int Delta_O, Delta_SO, Delta_S, Delta_SE, y, yAbs;

  d = 2*(y1-y0) - (x1-x0); //Valor que determina que pixel se debe pintar de acuerdo a su signo
  x = x0; y = y0;
  plot_nothing(x, y);

  if (x0 <= x1){
    xAbs = x1 - x0;
  }else{
    xAbs = x0 - x1;
  }
  if (y0 <= y1){
    yAbs = y1 - y0;
  }else{
    yAbs = y0 - y1;
  }

  
  if (x0<=x1){
    if (y0<=y1){
      Delta_NE  =  2 * ((y1 - y0) - (x1 - x0)); //Valor para avanzar un pixel hacia arriba y uno a la derecha
      if (xAbs>=yAbs){ //octante 1
        Delta_E   =  2 * (y1 - y0);                 //Valor para avanzar un pixel a la derecha
        while (x < x1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d <= 0){
            x++;
            d = d + Delta_E;
          }
          else{
            x++; y++;
            d = d + Delta_NE;
          }
          plot_nothing(x,y);
        }
      }
      else{ //octante 2
        Delta_N  = -2 * (x1 - x0);             //Valor para avanzar un pixel hacia arriba
        while (y < y1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d >= 0){
            y++;
            d = d + Delta_N;
          }
          else{
            x++; y++;
            d = d + Delta_NE;
          }
          plot_nothing(x,y);
        }
      }
    }
    else{
      Delta_SE  =  2 * ((y1 - y0) + (x1 - x0)); //Valor para avanzar un pixel hacia abajo y uno a la derecha
      if (x1+y1<=y0){ //octante 7
        Delta_S   =  2 * (x1 - x0);             //Valor para avanzar un pixel hacia abajo
        while (y > y1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d <= 0){
            y--;
            d = d + Delta_S;
          }
          else{
            x++; y--;
            d = d + Delta_SE;
          }
          plot_nothing(x,y);
        }
      }
      else{ //octante 8
        Delta_E   =  2 * (y1 - y0);                 //Valor para avanzar un pixel a la derecha
        while (x < x1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d >= 0){
            x++;
            d = d + Delta_E;
          }
          else{
            x++; y--;
            d = d + Delta_SE;
          }
          plot_nothing(x,y);
        }
      }
    }
  }
  else{
    if (y0<=y1){
      Delta_NO  = -2 * ((y1 - y0) + (x1 - x0)); //Valor para avanzar un pixel hacia arriba y uno a la izquierda
      if (x1+y1>=x0){ //octante 3
        Delta_N   = -2 * (x1 - x0);             //Valor para avanzar un pixel hacia arriba
        while (y < y1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d <= 0){
            y++;
            d = d + Delta_N;
          }
          else{
            x--; y++;
            d = d + Delta_NO;
          }
          plot_nothing(x,y);
        }
      }    
      else{ //octante 4
        Delta_O   = -2 * (y1 - y0);                 //Valor para avanzar un pixel a la izquierda
        while (x > x1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d >= 0){
            x--;
            d = d + Delta_O;
          }
          else{
            x--; y++;
            d = d + Delta_NO;
          }
          plot_nothing(x,y);
        }
      }
    }
    else{
      Delta_SO  = -2 * ((y1 - y0) - (x1 - x0)); //Valor para avanzar un pixel hacia abajo y uno a la izquierda
      if (xAbs>=yAbs){ //octante 5
        Delta_O   = -2 * (y1 - y0);                 //Valor para avanzar un pixel a la izquierda
        while (x > x1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d <= 0){
            x--;
            d = d + Delta_O;
          }
          else{
            x--; y--;
            d = d + Delta_SO;
          }
          plot_nothing(x,y);
        }
      }
      else{ //octante 6
        Delta_S   =  2 * (x1 - x0);               //Valor para avanzar un pixel hacia abajo
        while (y > y1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d >= 0){
            y--;
            d = d + Delta_S;
          }
          else{
            x--; y--;
            d = d + Delta_SO;
          }
          plot_nothing(x,y);
        }
      }
    }
  }
};