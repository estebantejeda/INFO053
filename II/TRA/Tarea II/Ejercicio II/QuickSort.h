//Incluir Librerías

#include <iostream>
#include <cstdlib>

using namespace std;

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
* int searchQ(int *Array, int n, int x):
*
* Recibe: El arreglo el arreglo que está ordenado de forma ascendente
* (int *Array), el tamaño del arreglo (int n) y el elemento que se desea
* buscar (int x).
*
* Entrega: El método retorna la cantidad de veces que encontró el elemento
* 'x' en el arreglo
*
* Explicación: El algoritmo crea un contador "k" inicializado en '0' (El cual
* indicará la cantidad de veces que se encontró con el elemento 'x' dentro del
* arreglo) y realiza un for que recorre todo el arreglo.
* Cuando el valor Array[i] del arreglo sea igual al elemento buscado 'x', el
* algoritmo sumará '+1' al contador 'k'.
* Una vez finalizado, retornará el valor de 'k'
*/

int searchQ(int *Array, int n, int x){
    int k = 0;
    for(int i = 0; i < n; i++){
        if(Array[i] == x){
            k++;
        }
    }
    return k;
}
