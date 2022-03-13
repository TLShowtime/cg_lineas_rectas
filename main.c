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
};


void procesar_algoritmos_plotless(){
    int i,j;
    double seconds, microseconds;
    double elapsed;
    struct timeval begin, end;
    printf("\n");
    printf("Plotless\n");
    printf("Fuerza Bruta:\n");
    gettimeofday(&begin, 0);
    for (i = 0; i < repeticiones; i++){
        for (j = 0; j < cant_lineas; j++ ){
            line1_plotless(cola_lineas[j]->x0, cola_lineas[j]->x1,
                           cola_lineas[j]->y0, cola_lineas[j]->y1);
        }
    }
    gettimeofday(&end, 0);
    seconds = (end.tv_sec - begin.tv_sec)* 1e6;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = (seconds + microseconds)*1e-6;
    printf("Execution time: %f seconds\n", elapsed);
    
    printf("Incremental v1\n");
    gettimeofday(&begin, 0);
    for (i = 0; i < repeticiones; i++){
        for (j = 0; j < cant_lineas; j++ ){
            line2_plotless(cola_lineas[j]->x0, cola_lineas[j]->x1,
                           cola_lineas[j]->y0, cola_lineas[j]->y1);
        }
    }
    gettimeofday(&end, 0);
    seconds = (end.tv_sec - begin.tv_sec)* 1e6;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = (seconds + microseconds)*1e-6;
    printf("Execution time: %f seconds\n", elapsed);
    
    printf("Incremental v2\n");
    gettimeofday(&begin, 0);
    for (i = 0; i < repeticiones; i++){
        for (j = 0; j < cant_lineas; j++ ){
            line3_plotless(cola_lineas[j]->x0, cola_lineas[j]->x1,
                           cola_lineas[j]->y0, cola_lineas[j]->y1);
        }
    }
    gettimeofday(&end, 0);
    seconds = (end.tv_sec - begin.tv_sec)* 1e6;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = (seconds + microseconds)*1e-6;
    printf("Execution time: %f seconds\n", elapsed);
    
    printf("Bresenham\n");
    gettimeofday(&begin, 0);
    for (i = 0; i < repeticiones; i++){
        for (j = 0; j < cant_lineas; j++ ){
            line4_plotless(cola_lineas[j]->x0, cola_lineas[j]->x1,
                           cola_lineas[j]->y0, cola_lineas[j]->y1);
        }
    }
    gettimeofday(&end, 0);
    seconds = (end.tv_sec - begin.tv_sec)* 1e6;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = (seconds + microseconds)*1e-6;
    printf("Execution time: %f seconds\n", elapsed);
}

void procesar_algoritmos(){
    int i,j;
    double seconds, microseconds;
    double elapsed;
    struct timeval begin, end;
    glColor3f(1,1,1);
    printf("\n");
    printf("Plot\n");
    printf("Fuerza Bruta\n");
    
    gettimeofday(&begin, 0);
    for (i = 0; i < repeticiones; i++){
        for (j = 0; j < cant_lineas; j++ ){
            line1(cola_lineas[j]->x0, cola_lineas[j]->x1,
                  cola_lineas[j]->y0, cola_lineas[j]->y1);
        }
    }
    gettimeofday(&end, 0);
    seconds = (end.tv_sec - begin.tv_sec)* 1e6;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = (seconds + microseconds)*1e-6;
    printf("Execution time: %f seconds\n", elapsed);
    glFlush();
    glutSetWindowTitle("Fuerza Bruta");
    sleep(3);
    glColor3f(1,0,0);
    printf("Incremental v1\n");
    
    gettimeofday(&begin, 0);
    for (i = 0; i < repeticiones; i++){
        for (j = 0; j < cant_lineas; j++ ){
            line2(cola_lineas[j]->x0, cola_lineas[j]->x1,
                  cola_lineas[j]->y0, cola_lineas[j]->y1);
        }
    }
    gettimeofday(&end, 0);
    seconds = (end.tv_sec - begin.tv_sec)* 1e6;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = (seconds + microseconds)*1e-6;
    printf("Execution time: %f seconds\n", elapsed);
    glFlush();
    glutSetWindowTitle("Incremental v1");
    sleep(3);
    glColor3f(0,1,1);
    printf("Incremental v2\n");
    
    gettimeofday(&begin, 0);
    for (i = 0; i < repeticiones; i++){
        for (j = 0; j < cant_lineas; j++ ){
            line3(cola_lineas[j]->x0, cola_lineas[j]->x1,
                  cola_lineas[j]->y0, cola_lineas[j]->y1);
        }
    }
    gettimeofday(&end, 0);
    seconds = (end.tv_sec - begin.tv_sec)* 1e6;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = (seconds + microseconds)*1e-6;
    printf("Execution time: %f seconds\n", elapsed);
    glFlush();
    glutSetWindowTitle("Incremental v2");
    sleep(3);
    glColor3f(0,0,1);
    printf("Bresenham\n");
   
    gettimeofday(&begin, 0);
    for (i = 0; i < repeticiones; i++){
        for (j = 0; j < cant_lineas; j++ ){
            line4(cola_lineas[j]->x0, cola_lineas[j]->x1,
                  cola_lineas[j]->y0, cola_lineas[j]->y1);
        }
    }
    gettimeofday(&end, 0);
    seconds = (end.tv_sec - begin.tv_sec)* 1e6;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = (seconds + microseconds)*1e-6;
    printf("Execution time: %f seconds\n", elapsed);
    glFlush();
    glutSetWindowTitle("Bresenham");
}

void draw_scene(){
    procesar_algoritmos_plotless();
    
    procesar_algoritmos();
    
};

int isNumber (char number[]){
    int i = 0;

    for (; number[i] != 0; i++){
        if (!isdigit(number[i])){
            return 0;
        }
    }
    return 1;
}

int main(int argc,char **argv){
    if (argc != 4)
    {
      (void) fprintf(stdout,"Usage: %s resolucion #lineas #veces\n",argv[0]);
      exit(0);
    }

    if (isNumber(argv[1]) == 0 || isNumber(argv[2]) == 0 || isNumber(argv[3]) == 0 ) {
        printf("Los valores deben ser numeros naturales \n");
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
