#ifndef PUNTO_H
#define PUNTO_H

// definicion de una estructura punto
typedef struct {
    float x;
    float y;
} punto;

void print_punto(punto p){
    printf("(%f, %f)\n", p.x, p.y);
}

float distancia(punto a, punto b){
    return sqrtf( (a.x - b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}


// p1 y p2 son vectores
float prod_punto(punto p1, punto p2){
    return p1.x*p2.x + p1.y*p2.y;
}

// retorna el vector perpendicular a p
punto normal(punto p){
    return (punto){p.y, -p.x};
}

punto trasladar(punto p, punto dp){
    punto newp = p;
    newp.x += dp.x;
    newp.y += dp.y;
    return newp;
}

// test punto en un poligono, retorna 1 si 'p' esta dentro, 0 si esta afuera
int punto_en_poligono(int nvert, punto *poly, punto p){
  int i, j, c = 0;
  for (i = 0, j = nvert-1; i < nvert; j = i++) {
    if ( ((poly[i].y > p.y) != (poly[j].y > p.y)) &&
        (p.x < (poly[j].x - poly[i].x) * (p.y-poly[i].y) / (poly[j].y-poly[i].y) + poly[i].x) )
       c = !c;
  }
  return c;
}





#endif
