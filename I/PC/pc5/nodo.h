#ifndef NODO_H
#define NODO_H

int max(int a, int b){
    return a>b? a : b;
}

typedef struct nodo{
    int val;
    struct nodo *izq;
    struct nodo *der;
}nodo;

nodo* crear_nodo(int val){
    nodo *n = (nodo*)malloc(sizeof(nodo));
    n->val = val;
    n->izq = NULL;
    n->der = NULL;
    return n;
}








int avl_eshoja(nodo *r){
    if(r->izq == NULL && r->der == NULL){
        return 1;
    }
    else{
        return 0;
    }
}



void avl_imprimir(nodo *r, int depth, int *padres){
    if(r != NULL){
        printf("(%i)", r->val);
        char buf[512] = "  ";
        for(int i=0; i<depth; ++i){
            if(padres[i] == 1){
                strcat(buf, " \t");
            }
            else{
                strcat(buf, "|\t");
            }
        }
        if(avl_eshoja(r)){
            return;
        }
        //printf("\n%s|----", buf);
        printf("---", buf);
        padres[depth] = 0;
        avl_imprimir(r->izq, depth+1, padres);

        printf("\n%s|-----", buf);
        padres[depth] = 1;
        avl_imprimir(r->der, depth+1, padres);
    }
}

int avl_altura(nodo *r){
    if(r == NULL){ return -1; }
    return max(avl_altura(r->izq), avl_altura(r->der)) + 1;
}

int avl_bfactor(nodo *r){
    return avl_altura(r->der) - avl_altura(r->izq);
}

int avl_desbalanceado(nodo *r){
    if(r != NULL){
        if( abs(avl_bfactor(r)) > 1 ){
            return 1;
        }
        else{
            return avl_desbalanceado(r->der) + avl_desbalanceado(r->izq);
        }
    }
    else{
        return 0;
    }
}

int avl_rot_der(nodo **r){
    printf("rot_der...");
    nodo *pivot = (*r)->izq;
    if(pivot == NULL){
        fprintf(stderr, "cannot rotate, pivot NULL\n");
        return 0;
    }
    (*r)->izq = pivot->der;
    pivot->der = (*r);
    (*r) = pivot;
    printf("ok\n");
    return 1;
}

int avl_rot_izq(nodo **r){
    nodo *pivot = (*r)->der;
    if(pivot == NULL){
        fprintf(stderr, "cannot rotate, pivot NULL\n");
        return 0;
    }
    (*r)->der = pivot->izq;
    pivot->izq = (*r);
    (*r) = pivot;
    return 1;
}

int avl_rot_izqizq(nodo **x){
    avl_rot_izq(x);
    return 1;
}

int avl_rot_derder(nodo **x){
    avl_rot_der(x);
    return 1;
}

int avl_rot_derizq(nodo **x){
    avl_rot_der(&(*x)->der);
    avl_rot_izq(x);
    return 1;
}

int avl_rot_izqder(nodo **x){
    avl_rot_izq(&(*x)->izq);
    avl_rot_der(x);
    return 1;
}

void avl_insertar(nodo **r, int val){
    if((*r) == NULL){
        (*r) = crear_nodo(val);
        return;
    }
    if(val > (*r)->val){
        if((*r)->der == NULL){
            (*r)->der = crear_nodo(val);
        }
        else{
            avl_insertar(&((*r)->der), val);
        }
    }
    else{
        if((*r)->izq == NULL){
            (*r)->izq = crear_nodo(val);
        }
        else{
            avl_insertar(&((*r)->izq), val);
        }
    }
}

// busca el nodo con valor "val", y modifica b,p para indicar el nodo buscado y su padre respectivamente.
// si no encuentra el nodo, entonces b,p son null.
// si b no tiene padre, entonces p es null.
// NOTA: llamar esta funcion pasando b y p como nulos
void avl_buscar(nodo **r, int val, nodo **b, nodo **p){
   if(*r != NULL){
        if((*r)->val == val){
            *b = *r;
            return;
        }
        else{
            if(val > (*r)->val){
                *p = *r;
                avl_buscar(&(*r)->der, val, b, p);
            }
            else{
                *p = *r;
                avl_buscar(&(*r)->izq, val, b, p);
            }
        }
   }
   else{
       *p = NULL;
   }
}


// (1)
void avl_eliminar(nodo **r, int val){
}



// (2)
// la variable aux puede servirles para algun proposito, si no lo van a usar pueden pasar siempre un "0".
nodo* avl_balancear(nodo **x, int aux){
    return NULL;
}

#endif
