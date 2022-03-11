#include "main.h"

LINEA **cola_lineas;

int resolucion;
int cant_lineas;
int repeticiones;

void create_lines(){
    int i;
    time_t t;

    cola_lineas = (LINEA **)malloc(cant_lineas * sizeof(LINEA));
    for (i = 0; i < cant_lineas; i++){
        cola_lineas[i] = (LINEA*)malloc(sizeof(LINEA));
    }

    srand((unsigned) time(&t));
    for (i = 0; i < cant_lineas; i++){
        cola_lineas[i]->x0 = rand() % resolucion;
        cola_lineas[i]->y0 = rand() % resolucion;
        cola_lineas[i]->x1 = rand() % resolucion;
        cola_lineas[i]->y1 = rand() % resolucion;
    }

    for (int i = 0; i < cant_lineas; i++){
        printf("x0: %d, y0: %d \n",cola_lineas[i]->x0, cola_lineas[i]->y0);
        printf("x1: %d, y1: %d \n",cola_lineas[i]->x1, cola_lineas[i]->y1);
    }
};


void procesar_algoritmos_plotless(){
    int i,j;
    printf("Fuerza Bruta\n");
    for (i = 0; i < repeticiones; i++){
        for (j = 0; j < cant_lineas; j++ ){
            line1_plotless(cola_lineas[j]->x0, cola_lineas[j]->x1,
                           cola_lineas[j]->y0, cola_lineas[j]->y1);
        }
    }
    for (i = 0; i < repeticiones; i++){
        for (j = 0; j < cant_lineas; j++ ){
            line2_plotless(cola_lineas[j]->x0, cola_lineas[j]->x1,
                           cola_lineas[j]->y0, cola_lineas[j]->y1);
        }
    }
    for (i = 0; i < repeticiones; i++){
        for (j = 0; j < cant_lineas; j++ ){
            line3_plotless(cola_lineas[j]->x0, cola_lineas[j]->x1,
                           cola_lineas[j]->y0, cola_lineas[j]->y1);
        }
    }
    printf("Bresenham\n");
    for (i = 0; i < repeticiones; i++){
        for (j = 0; j < cant_lineas; j++ ){
            line4_plotless(cola_lineas[j]->x0, cola_lineas[j]->x1,
                           cola_lineas[j]->y0, cola_lineas[j]->y1);
        }
    }
}

void procesar_algoritmos(){
    int i,j;
    glColor3f(1,1,1);
    printf("Fuerza Bruta\n");
    for (i = 0; i < repeticiones; i++){
        for (j = 0; j < cant_lineas; j++ ){
            line1(cola_lineas[j]->x0, cola_lineas[j]->x1,
                  cola_lineas[j]->y0, cola_lineas[j]->y1);
        }
    }

    glColor3f(1,0,0);
    printf("Incremental v1\n");
    for (i = 0; i < repeticiones; i++){
        for (j = 0; j < cant_lineas; j++ ){
            line2(cola_lineas[j]->x0, cola_lineas[j]->x1,
                  cola_lineas[j]->y0, cola_lineas[j]->y1);
        }
    }
    glColor3f(0,1,1);
    printf("Incremental v2\n");
    for (i = 0; i < repeticiones; i++){
        for (j = 0; j < cant_lineas; j++ ){
            line3(cola_lineas[j]->x0, cola_lineas[j]->x1,
                  cola_lineas[j]->y0, cola_lineas[j]->y1);
        }
    }

    printf("Bresenham\n");
    glColor3f(0,0,1);
    for (i = 0; i < repeticiones; i++){
        for (j = 0; j < cant_lineas; j++ ){
            line4(cola_lineas[j]->x0, cola_lineas[j]->x1,
                  cola_lineas[j]->y0, cola_lineas[j]->y1);
        }
    }
}

void draw_scene(){
    //procesar_algoritmos_plotless();
    
    procesar_algoritmos();
    glFlush();
};

int main(int argc,char **argv){
    if (argc != 4)
    {
      (void) fprintf(stdout,"Usage: %s resolucion #lineas #veces\n",argv[0]);
      exit(0);
    }
    char* res_ptr;
    char* lin_ptr;
    char* rep_ptr;
    resolucion = strtol(argv[1],&res_ptr,10);
    cant_lineas = strtol(argv[2],&lin_ptr,10);
    repeticiones = strtol(argv[3],&rep_ptr,10);

    create_lines(cant_lineas);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(resolucion,resolucion);
    glutCreateWindow("Test");
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-0.5, resolucion +0.5, -0.5, resolucion + 0.5);
    glutDisplayFunc(draw_scene);
    glutMainLoop();

    return 0;
}