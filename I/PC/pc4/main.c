#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXPUNTOS 10
#define WIDTH 64
#define HEIGHT 64

#include "nodo.h"
int main(int argc, char **argv){
    if(argc != 2){
        fprintf(stderr, "ejecutar como ./prog N\n");
        exit(EXIT_FAILURE);
    }
    int N = atoi(argv[1]);
    nodo *r = NULL;
    printf("insertando %i puntos.......", N); fflush(stdout);
    for(int i=0; i<N; ++i){
        punto p;
        p.x = rand()%WIDTH;
        p.y = rand()%HEIGHT;
        qt_insertar(&r, p);
    }
    printf("hecho\n", N); fflush(stdout);
    qt_imprimir(r);
    return EXIT_SUCCESS;
}
