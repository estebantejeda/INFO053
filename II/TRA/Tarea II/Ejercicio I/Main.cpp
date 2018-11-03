//Importar Librerías y demaces

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "BucketSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#define MAX 100

using namespace std;

//Declaración de Métodos

void bucketSort(int *Array, int n);
void heapSort(int *Array, int n);
void quickSort(int *Q,int izq,int n);
void randomAdd(int *Array, int n);
void sortA(int *A, int n);
void printArray(int *Array, int n, string name);
void printArrayH(int *Array, int n, string name);
void copyArray(int *ArrayI, int *ArrayF, int n);
void copyArrayH(int *ArrayI, int *ArrayF, int n);
int comp (const void *a, const void *b);

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
    * Una vez realizado esto, se rellena este arreglo 'A' con números aleatorios
    * utilziando el randomAdd() y finalmente se inician los métodos de ordenamientos
    * utilziando sortA().
    */

    int n = atoi(argv[1]);
    int *A = new int[n];

    randomAdd(A, n);
	sortA(A, n);
}

//Creación de Método Principal

/*
* void SortA(int *A, int n):
*
* Recibe: El arreglo original que se desea ordenar (int *A) y el largo de este
* (int n).
*
* Entrega: Al ser un método void no retorna nada, pero lo que realiza son
* los métodos de ordenamientos indicados para la tarea.
*
* Explicación: Cada paso está claramente detallado dentro del algoritmo.
*/

void sortA(int *A, int n){

    /*
    * Se crean los arreglos a los cuales se les implementarán los algoritmos
    * de ordenamiento
    */

    int *Q = new int[n]; //QuickSort Creado
    int *S = new int[n]; //QuickSort Implemetado por C++
    int *H = new int[n+1]; //HeapSort
    int *B = new int[n]; //BucketSort

    /*
    * En esta sección van los métodos previos para ordenamiento, lo primero es
    * llenar el arreglo A con números aleatorios (randomAdd) y luego copiar
    * este arreglo a los demás (copyArray) con el fin de realizar los métodos de
    * ordenamiento solicitados.
    */

    copyArray(A, B, n);
    copyArray(A, S, n);
    copyArray(A, Q, n);
    copyArrayH(A, H, n);

    /*
    * Se imprime en patalla el arreglo que será usado para los métodos
    * de ordenamiento
    */

    cout << endl;
    cout << "Arreglo Original:" << endl;
    printArray(A, n, "A");

    /*
    * Se llama a los métodos de ordenamiento
    */

    bucketSort(B, n);
    qsort(S, n, sizeof(int), comp);
    heapSort(H, n);
    quickSort(Q,0,n);

    /*
    * Se imprimen en pantalla los arreglos ya ordenados
    */

    cout << endl;
    cout << "Arreglos ordenados: " << endl;
    printArray(B, n, "B");
    printArray(S, n, "S");
    printArrayH(H, n, "H");
    printArrayH(Q, n, "Q");

}

//Creación de Métodos de Ordenamiento

/*
* void bucketSort(int *Array, int n):
*
* Recibe: El arreglo de enteros que se desea ordenar (int *Array) y el tamaño
* de dicho arreglo (int n).
*
* Entrega: Al ser un método void no retorna nada, pero realiza el ordenamiento
* del arreglo recibido (int *Array).
*
* Explicación: Este método crea un nuevo arreglo de tipo hashing enlazado de
* tamaño n el cual se rellena inicializa con valores Nulos para evitar posbiles
* errores con los punteros.
* Una vez realizado lo anterior, se llama al método insert(), el cual toma
* las variables del arreglo original y las va ingresando a la tabla de hash
* de manera ascendente.
* Para finalizar, se llama al método orderInArray(), el cual se encarga de
* agregar los elementos de la tabla (Los cuales se encuentrar ahora de manera
* ascendente) en el arreglo que recibió el método (Array).
*/

void bucketSort(int *Array, int n){
    nodoB **A = new nodoB*[n];
    for(int i = 0; i < n; i++){
        A[i] = NULL;
    }
    for(int i = 0; i < n; i++){
        insert(A, n, Array[i]);
    }
    orderInArray(A, Array, n);
}

/*
* void heapSort(int *Array, int n):
*
* Recibe: El arreglo de enteros que se desea ordenar (int *Array) y el tamaño
* de dicho arreglo (int n).
*
* Entrega: Al ser un método void no retorna nada, pero realiza el ordenamiento
* del arreglo recibido (int *Array).
*
* Explicación: Primero se crea un arreglo auxiliar el cuál contendrá los elementos
* del arreglo ordenado.
* El algoritmo inicia con la función makeMinHeap(), la cual convierte el arreglo
* Array en un min-Heap.
* Una vez realizo lo anterior, el algoritmo inicia un for para recorrer todo el
* arreglo, guardando el elemeno ordenado dentro del arreglo auxiliar y reodenándolo
* con heapify.
* Para finalizar, el algoritmo copia el contenido del arrelgo auxiliar dentro
* del arreglo original.
*/

void heapSort(int *Array, int n){
    int *ArrayAux = new int[n];
    makeMinHeap(Array, n);
    for(int i = 1; i<= n; i++){
        ArrayAux[i-1] = Array[1];
        Array[1]=Array[n+1-i];
        heapify(Array, n-i);
    }
    copyArrayH(ArrayAux, Array, n);
}


//Creación de Métodos Auxiliares

/*
* int comp(const void *a, const void *b):
*
* Recibe: El arreglo recibe dos números que se desean comparar (const void *a)
* y (const void *b).
*
* Entrega: Retorna un entero el cúal representa un número positivo, negativo
* o un '0'
*
* Explicación: Este método se encarga de entregar la diferencia que se encuentra
* entre los dos números dados del arreglo. Dependiento de los tres posibles
* resultados (a < b v a > b v a = b), la función qsort() determinará si uno de
* estos dos números deban moverse hacia la izquiera, derecha o mantener su posición.
*/

int comp (const void *a, const void *b){
    return (*(int*)a - *(int*)b);
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
*
* Otros: printArrayH() es unan variación de printArray() con la única diferencia
* de que el contador del for inicia en '1' en vez de '0'. Esto se debe a que
* el arreglo del HeapSort requiere que la primera celda del arreglo esté vacía.
*/

void printArray(int *Array, int n, string name){
    cout << "[" << name << "] = ";
    for(int i = 0; i < n; i++){
        cout << Array[i] << " ";
    }
    cout << endl;
}

void printArrayH(int *Array, int n, string name){
    cout << "[" << name << "] = ";
    for(int i = 1; i <= n; i++){
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
*
* Otros: copyArrayH() es una variación de copyArray(), con la diferencia de que
* en este, se deja la primera posición en 0, ya que en el HeapSort la primera
* posición del arreglo debe estar vacía. Además se corre en uno el arreglo final
* para que se pueda copiar de maera correcta el arreglo, ya que en el HeapSort
* la posición del arreglo está desviada en '1'.
*/

void copyArray(int *ArrayI, int *ArrayF, int n){
    for(int i = 0; i < n; i++){
        ArrayF[i] = ArrayI[i];
    }
}

void copyArrayH(int *ArrayI, int *ArrayF, int n){
    ArrayF[0] = 0;
    for(int i = 0; i < n; i++){
        ArrayF[i+1] = ArrayI[i];
    }
}
