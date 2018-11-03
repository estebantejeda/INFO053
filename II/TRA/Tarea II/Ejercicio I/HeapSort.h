//Incluir Librerías

#include <iostream>
#include <cstdlib>
#include <stdlib.h>

/*
* void makeMinHeap(int *Array, int n):
*
* Recibe: El arreglo que se desea ordenar (int *Array) junto a su tamaño (int n).
*
* Entrega: Al ser un método void no retorna nada, pero lo que hace es convertir
* el arreglo en un min-heap.
*
* Explicación: TERMINAR
*/

void makeMinHeap(int *Array, int n){
    int x, i, j, k;
    for (int i = 2; i <= n; i++){
        x = Array[i];
        k = i/2;
        j = i;
        while(k  && x < Array[k]){
            Array[j] = Array[k];
            j = k;
            k = k/2;
        }
        Array[j] = x;
    }
}

/*
* void heapify(int *Array, int n):
*
* Recibe: El arreglo que se desea ordenar (int *Array) junto a su tamaño (int n).
*
* Entrega: TERMINAR
*
* Explicación: TERMINAR
*/

void heapify(int *Array, int n){
    int m = 2;
    int i = 1;
    int val = Array[1];

    while(m < n){
        if (m+1 < n && Array[m] > Array[m+1]){
            m++;
        }
        if (val > Array[m]){
            Array[i] = Array[m];
            i = m;
            m <<= 1;
        }
        else{
            break;
        }
    }
    Array[i] = val;
}
