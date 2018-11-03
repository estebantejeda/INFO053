#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define LIM 30

// global values
int a, b, n, L, p, seed;

#include "node.h"
#include "hash.h"

int main(int argc, char **argv){
    if(argc != 3){
        fprintf(stderr, "ejecutar como ./prog L n\n");
        exit(EXIT_FAILURE);
    }
    // reiniciar el prng en estado asociado al '101;
    L = atoi(argv[1]);
    n = atoi(argv[2]);


    // generar una funcion hash de forma aleatoria
    printf("generando una funcion hash universal...", L, MAXELEM); fflush(stdout);
    gen_hashfunc(L, &a, &b, &p);
    printf("ok\n"); fflush(stdout);

    // allocando tabla hash
    seed = time(NULL);
    srand(seed);
    nodo **ht = (nodo**)malloc(sizeof(nodo*)*L);
    for(int i=0; i<L; ++i){
        ht[i] = crear_nodo();
    }
   
    while(1){
        // insertar N numeros aleatorios
        printf("insertando %i elementos...( ", n); fflush(stdout);
        for(int i=0; i<n; ++i){
            int val = rand()%LIM;
            printf("%i ", val);
            ht_insertar(ht, val , h2);
        }
        printf(")...ok\n"); fflush(stdout);
        ht_print(ht, L);
        printf("presione Enter para eliminar (Ctrl + c para salir)....\n"); fflush(stdout);
        getchar();

        printf("eliminando %i elementos...( ", n); fflush(stdout);
        for(int i=0; i<n; ++i){
            int val = rand()%LIM;
            printf("%i ", val);
            ht_eliminar(ht, val, h2);
        }
        printf(")...ok\n"); fflush(stdout);
        ht_print(ht, L);
        printf("presione Enter para insertar (Ctrl + c para salir)....\n"); fflush(stdout);
        getchar();
    }
    return EXIT_SUCCESS;
}
