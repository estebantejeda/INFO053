#include <iostream>
#include <cstdlib>

using namespace std;

/*
* Se crea una estructura nodo que almacena un numero en cuestión (val) junto
* con un puntero que apunta al siguiente nodo (next)
*/

typedef struct nodo {
	int val;
	struct nodo *next;
}nodo;

/*
* void quickSort(int *Array, int izq, int n)
*
* Recibe: El arreglo que se desea ordenar (int *Array), la posición del inicio
* del arreglo (int izq) y  su tamaño (int n).
*
* Entrega: Al ser un método void no retorna nada, pero el método va ordenando
* el arreglo en cuestión.
*
* Explicación: Se utilizan dos indices i (índice izquierdo) y j (índice derecho),
* y se recorre la lista de forma simultanea por ambos indices.
* Cuando el valor del indice i sea mayor que el pivote y el valor del indice j
* sea menor, los elementos son intercambiados. Este proceso se repite hasta que
* los dos indices se cruzan con en el mismo elemento, ese punto es la posicion
* correcta de p.
*/

void quickSort(int *Array, int izq, int n){
	int i = izq;
	int j = n;
	int aux;
    int p = Array[(n+izq)/2];
    while (i <= j){
        while (Array[i] < p){
			i++;
		}
        while (Array[j] > p){
			j--;
		}
        if (i <= j){
        	aux = Array[i];
            Array[i] = Array[j];
            Array[j] = aux;
            i++;
			j--;
		}
	}
    if (izq < j){
     	quickSort(Array, izq, j);
	}
    if (i < n){
      	quickSort(Array, i, n);
	}
}
