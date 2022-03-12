#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <ctype.h>

#include "algoritmos/bruta.h"
#include "algoritmos/incremental_v1.h"
#include "algoritmos/incremental_v2.h"
#include "algoritmos/bresenham.h"

typedef struct {
    int x0;
    int x1;
    int y0;
    int y1;
} LINEA ;
