#include "drawer.h"

void plot_nothing(int x, int y){};

void plot(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
};