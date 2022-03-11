#include "incremental_v2.h"

int max(int num1, int num2){
    return (num1 > num2) ? num1 :num2;
}

void line3(int x0, int x1, int y0, int y1){
    long double x, y, paso_x, paso_y;
    int i, ancho;

    ancho = max (abs(x1 - x0), abs(y1 - y0));
    paso_x = (long double)(x1 - x0) / ancho;
    paso_y = (long double)(y1 - y0) / ancho;
    x = x0;
    y = y0;

    for (int i = 0; i <= ancho; i++){
        plot(round(x),round(y));
        x += paso_x;
        y += paso_y;
    }
};

void line3_plotless(int x0, int x1, int y0, int y1){
    long double x, y, paso_x, paso_y;
    int i, ancho;

    ancho = max (abs(x1 - x0), abs(y1 - y0));
    paso_x = (long double)(x1 - x0) / ancho;
    paso_y = (long double)(y1 - y0) / ancho;
    x = x0;
    y = y0;

    for (int i = 0; i <= ancho; i++){
        plot_nothing(round(x),round(y));
        x += paso_x;
        y += paso_y;
    }
};