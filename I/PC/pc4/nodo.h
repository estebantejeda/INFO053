#ifndef NODO_H
#define NODO_H

int max(int a, int b){
    return a>b? a : b;
}

typedef struct punto{
    int x, y;
}punto;

typedef struct nodo{
    punto puntos[MAXPUNTOS];
    int numpuntos;
    punto arriba_izq;
    punto abajo_der;
    struct nodo *q1;
    struct nodo *q2;
    struct nodo *q3;
    struct nodo *q4;
}nodo;

nodo* crear_nodo(punto p1, punto p2){
    nodo *n = (nodo*)malloc(sizeof(nodo));
    n->numpuntos=0;
    n->arriba_izq = p1;
    n->abajo_der = p2;
    n->q1 = NULL;
    n->q2 = NULL;
    n->q3 = NULL;
    n->q4 = NULL;
    return n;
}

// ejercicio (1)
int punto_en_cuadrante(punto p, nodo *n){
    return 0;
}

// ejercicio (2)
void qt_insertar(nodo **r, punto p){

}

// ejercicio (3)
void qt_imprimir(nodo *r){

}

#endif
