#include "incremental_v1.h"

void line2(int x0, int x1, int y0, int y1){
    long double m, y, mx, my;
    int i, var_inicial, var_final;

    my = (y1 - y0); //Se usa para evitar problemas de punto flotante
    mx = (x1 - x0); //Se usa para evitar problemas de punto flotante
    m = my / mx;

    if (abs(x0 - x1) >= abs(y0 - y1)){ //Se usa si hay mas x
        if (x1 > x0 ){ //Se usa si x0 es el izquierdo
            var_inicial = x0;
            var_final = x1;
            y = y0;
        }
        else{ //Se usa si x1 es el izquierdo
            var_inicial = x1;
            var_final = x0;
            y = y1;
        }
        for (i = var_inicial; i <= var_final; i++){
            plot(i,(round(y)));
            y += m;
        }    
    } else { //Se usa si hay mas y
        if (y1 > y0 ){ //Se usa si y0 es el izquierdo
            var_inicial = y0;
            var_final = y1;
            y = x0;
        }
        else{ //Se usa si y1 es el izquierdo
            var_inicial = y1;
            var_final = y0;
            y = x1;
        }
        for (i = var_inicial; i <= var_final; i++){
            plot(round(y),i);
            y += 1/m; // delta x es 1/m
        }
    }
    
};

void line2_plotless(int x0, int x1, int y0, int y1){
    long double m, y, mx, my;
    int i, var_inicial, var_final;

    my = (y1 - y0); //Se usa para evitar problemas de punto flotante
    mx = (x1 - x0); //Se usa para evitar problemas de punto flotante
    m = my / mx;

    if (abs(x0 - x1) >= abs(y0 - y1)){ //Se usa si hay mas x
        if (x1 > x0 ){ //Se usa si x0 es el izquierdo
            var_inicial = x0;
            var_final = x1;
            y = y0;
        }
        else{ //Se usa si x1 es el izquierdo
            var_inicial = x1;
            var_final = x0;
            y = y1;
        }
        for (i = var_inicial; i <= var_final; i++){
            plot_nothing(i,(round(y)));
            y += m;
        }    
    } else { //Se usa si hay mas y
        if (y1 > y0 ){ //Se usa si y0 es el izquierdo
            var_inicial = y0;
            var_final = y1;
            y = x0;
        }
        else{ //Se usa si y1 es el izquierdo
            var_inicial = y1;
            var_final = y0;
            y = x1;
        }
        for (i = var_inicial; i <= var_final; i++){
            plot_nothing(round(y),i);
            y += 1/m; // delta x es 1/m
        }
    }
};