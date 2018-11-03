#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "nodo.h"

#define MAXDEPTH 100

int main(int argc, char **argv){
    if(argc != 3){
        fprintf(stderr, "ejecutar como ./prog n seed\n");
        exit(EXIT_SUCCESS);
    }
    int n = atoi(argv[1]);
    srand(atoi(argv[2]));
    int padres[MAXDEPTH];
    nodo *r = NULL;
    for(int i=0; i<n; ++i){
        int val = rand()%99;
        printf("insertando (%i elemento) = %i en avl\n", i, val);
        avl_insertar(&r, val);
        avl_imprimir(r, 0, padres);
        printf("\naltura = %i\n", avl_altura(r));
        printf("desbalanceado = %i\n", avl_desbalanceado(r));
        printf("balanceando......");
        avl_balancear(&r, val);
        printf("hecho\n");
        avl_imprimir(r, 0, padres);
        printf("\npress enter...\n");
        getchar();
    }
    printf("\n\nAhora se borraran n/2=%i nodos....press enter", n/2);
    getchar();
    srand(atoi(argv[2]));
    for(int i=0; i<n/2; ++i){
        int val = rand()%99;
        printf("eliminando (%i elemento) = %i en avl\n", i, val);
        avl_eliminar(&r, val);
        avl_imprimir(r, 0, padres);
        printf("\naltura = %i\n", avl_altura(r));
        printf("desbalanceado = %i\n", avl_desbalanceado(r));
        printf("balanceando......");
        avl_balancear(&r, val);
        printf("hecho\n");
        avl_imprimir(r, 0, padres);
        printf("press enter...\n");
        getchar();
    }
    return EXIT_SUCCESS;
}
