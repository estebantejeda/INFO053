#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "punto.h"
#include "figura.h"

int main(int argc, char **argv){
    if(argc != 1){
        fprintf(stderr, "ejecutar como ./prog\n");
        exit(EXIT_FAILURE);
    }

    // datos circulo
    punto pc[1] = {1.0f, 1.0f};
    float radio = 1.0f;

    // datos rectangulo
    punto pr[4] = { {2.8, 1.0f}, {6.0f, 1.0f}, {6.0f, 5.0f}, {2.8f, 5.0f} };

    // datos triangulo
    punto pt[3] = { {1.5f, 1.0f}, {3.0f, 0.5f}, {3.0f, 2.0f} };

    // creando figuras
    figura c = crear_figura(TYPE_CIRCULO,    pc, 1, radio);
    figura r = crear_figura(TYPE_RECTANGULO, pr, 4, 0.0f);
    figura t = crear_figura(TYPE_TRIANGULO,  pt, 3, 0.0f);

    // imprimir info figuras
    imprimir_info_figura(c, "circulo");
    imprimir_info_figura(r, "rectangulo");
    imprimir_info_figura(t, "triangulo");
        
    
    // areas 
    printf("Areas:\n");
    printf(" A(c) = %f    A(r) = %f   A(t) = %f\n", area(c), area(r), area(t) );


    // colisiones
    printf("Colisiones:\n");
    printf("C(c, r) = %i      C(c, t) = %i      C(r, t) = %i\n", colision(c, r), colision(c, t), colision(r, t));
    return EXIT_SUCCESS;
}
