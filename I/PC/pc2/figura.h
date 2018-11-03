#ifndef FIGURAS_H
#define FIGURAS_H

#define TYPE_CIRCULO 0
#define TYPE_RECTANGULO 1
#define TYPE_TRIANGULO 2

typedef struct{
    int tipo;
    int n;
    punto *puntos;
    float aux;
} figura;



figura crear_figura(int tipo, punto *puntos, int n, float aux){
    figura fig;
    fig.tipo = tipo;
    fig.n = n;
    fig.puntos = (punto*)malloc(sizeof(punto)*n);
    memcpy(fig.puntos, puntos, sizeof(punto)*n);
    fig.aux = aux;
    return fig;
}


void imprimir_info_figura(figura fig, const char *msg){
    printf("%s\n", msg);
    for(int i=0; i<fig.n; ++i){
        print_punto(fig.puntos[i]);
    }
    printf("aux=%f\n", fig.aux);
    printf("\n");
    return;
}


// (1) area
float area(figura fig){
    float area_fig;
    if (fig.tipo == 0){
        area_fig = 3.14*fig.aux*fig.aux;
    }
    else if (fig.tipo == 1){
        float a = distancia(fig.puntos[0], fig.puntos[1]);
        float b = distancia(fig.puntos[1], fig.puntos[2]);
        area_fig = a*b; 
    }
    else{
        float a = fig.puntos[0].x * fig.puntos[1].y; 
        float b = fig.puntos[1].x * fig.puntos[2].y;
        float c = fig.puntos[2].x * fig.puntos[0].y;
        float d = fig.puntos[1].x * fig.puntos[0].y;
        float e = fig.puntos[2].x * fig.puntos[1].y;
        float f = fig.puntos[0].x * fig.puntos[2].y;
        area_fig = 0.5*(a+b+c-d-e-f);
    }
    return area_fig;
}



// (2) colision
int colision(figura f1, figura f2){
    return 0;
}
































#endif
