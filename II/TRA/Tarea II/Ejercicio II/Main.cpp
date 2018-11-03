//Importar Librerías y demaces

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "Hash.h"
#include "QuickSort.h"
#define MAX 500

using namespace std;

void randomAdd(int *Array, int n);
void printArray(int *Array, int n, string name);
void copyArray(int *ArrayI, int *ArrayF, int n);

int main(int argc, char **argv){

    /*
    * Se comprueba que el usuario ingresó solo 1 variable a la hora de realizar
    * el main, además de que esta debe ser un número mayor que 1. De lo contrario
    * el programa imprimirá un error para luego cerrarse.
    */

    if (argc != 2 || atoi(argv[1]) <= 0){
        cout << "Error. Debe ejecutarse como ./main n (n > 0)" << endl;
        exit(EXIT_FAILURE);
    }

    /*
    * Se crea una variable 'n' con el parametro ingresado por el usuario para
    * luego crear un arreglo 'A' de n elementos.
    * Se crea un entero x, el cuál se generará de manera aleatoria. Este valor
    * es el que se buscará dentro de las tres estructuras dadas.
    * Se rellena el arrelgo con números aleatoreos con el método randomAdd().
    */

    int n = atoi(argv[1]);
    int *A = new int[n];
    int x = rand()%MAX;
    randomAdd(A, n);
    cout << "Número a buscar: " << x << endl;
    cout << " " << endl;

    /*
    * Arreglo Ordenado:
    * Se crea un arreglo Q al cuál se le hace una copia del arreglo A con
    * el método copyArray().
    * Se realiza el ordenamiento ascendente con el método qsort (El cúal ya
    * está implementado dentro de C++11).
    * Se finaliza con la creación de una variable 'q' la cuál indica la
    * cantidad de veces que método de búsqueda encontró el valor 'x'.
    */

    int *Q = new int[n];
    copyArray(A, Q, n);
    qsort(Q, n, sizeof(int), comp);
    int q = searchQ(Q, n, x);
    cout << "Coincidencias con QuickSort: " << q << endl;

    /*
    * Busqueda con Hash:
    * En esta sección del código se crea una tabla de hash H con un tamaño
    * al primo más cercano del tamaño del arreglo original divido entre 10.
    * Luego de esto, se inicializan con valores de la tabla hash con nulos
    * para evitar problemas con los punteros, esto gracias a nullHash().
    * Se pasan los números del arreglo A al hash H con arrayInHash().
    * Se finaliza con la creación de una variable 'h' la cuál indica la
    * cantidad de veces que método de búsqueda encontró el valor 'x'.
    */

    int m = n/4;
    nodoH **H = new nodoH*[m];
    nullHash(H, m);
    arrayInHash(H, A, n, m);
    int h = searchH(H, n, x);
    cout << "Coincidencias con HeapSort: " << h << endl;

    /*
    * Árbol AVL
    */

}

/*
* void randomAdd(int *Array, int n):
*
* Recibe: El arreglo de enteros que se desea ordenar (int *Array) y el tamaño
* de dicho arreglo (int n).
*
* Entrega: Al ser un método void no retorna nada, pero realiza el llenado
* del arreglo con números aletorios
*
* Explicación: El método crea un for de largo n (tamaño del arreglo) para luego
* empezar a rellenar este con números aleatorios utilziando el método rand.
*/

void randomAdd(int *Array, int n){
    for(int i = 0; i < n; i++){
        Array[i] = rand()%MAX;
    }
}

/*
* void printArray(int *Array, int n, string name)
*
* Recibe: El arreglo de enteros que se desea ordenar (int *Array) y el tamaño
* de dicho arreglo (int n).
*
* Entrega: Al ser un método void no retorna nada, pero realiza la impresión
* del arreglo
*
* Explicación: El método crea un for de largo n (tamaño del arreglo) para luego
* empezar a imprimir cada número que este posea.
*/

void printArray(int *Array, int n, string name){
    cout << "[" << name << "] = ";
    for(int i = 0; i < n; i++){
        cout << Array[i] << " ";
    }
    cout << endl;
}

/*
* void copyArray(int *ArrayI, int *ArrayF, int n)
*
* Recibe: El arreglo de enteros que posee los números aleatorios (int *ArrayI),
* el arreglo de enteros que se quiere copiar (int *ArrayF) y el tamaño de dicho
* arreglo (int n).
*
* Entrega: Al ser un método void no retorna nada, copia el arreglo original en
* el nuevo arreglo
*
* Explicación: El método crea un for de largo n (tamaño del arreglo) para luego
* designarle a cada celda del arrelgo que se va a copiar el valor del arreglo
* original.
*/

void copyArray(int *ArrayI, int *ArrayF, int n){
    for(int i = 0; i < n; i++){
        ArrayF[i] = ArrayI[i];
    }
}
