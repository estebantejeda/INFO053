//Incluir Librerías

#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

int nPrimo(int x);

/*
* Se crea una estructura nodo que almacena un numero en cuestión (val) junto
* con un puntero que apunta al siguiente nodo (next)
*/

typedef struct nodoH {
	int val;
	struct nodoH *next;
}nodoH;

/*
* int h(int n, int x):
*
* Recibe: El largo que tiene el arreglo (int n) junto a un número que se
* encuentra en la posición 'i' del mismo (int x)
*
* Entrega: Entrega el resultado de la posición 'i' para la tabla de hash
*
* Explicación: Realiza una operación matemática para saber la key que debe
* tener el número 'x'. Esta key es la que se encarga de saber la posición
* del arreglo en que debe ir el número en cuestión.
*/

int h(int m, int x){
    /*int p = nPrimo(x);
    int z = x*n/p;*/
    return x%m; //hash temporal
}

/*
* void insert(nodoB **T, int n, int x):
*
* Recibe: Un arreglo de tipo Hash (nodoB **T), el largo del arreglo que se
* quiere ordenar (int n) y el número 'x' que se desea agregar el arreglo.
*
* Entrega: Al ser un método void no retorna nada, pero el método agregar el
* valor de 'x' a la tabla hash de orden ascendente.
*
* Explicación: El método cre aun nuevo nodo con el valor del número del arreglo
* que se desea ordenar (x) y lo inserta dentro de la tabla de hash en la
* posición h(n, x). Se validaron dos casos posibles a la hora de agregar
* (Hash en posición h vacía y Hash cuando ya posea un valor existe).
* El primer "if" valida si la posición en ese arreglo es nula, en caso de serlo
* lo agrega en primera posición.
* El "else" quiere decir que la posición del arreglo no está vacía, por lo que
* empezará a recorrerla hasta que la posición del puntero siguiente sea nula.
* Una vez hecho esto, conectará la última posición con el nuevo valor 'x'.
*/

void insertH(nodoH **T, int m, int x){
	int key = h(m, x);
	nodoH *nuevo = new nodoH;
	nuevo->next = nullptr;
    nuevo->val = x;
    if(T[key] == nullptr){
        T[key] = nuevo;
    }
    else{
        nodoH *p = T[key];
        while(p->next != nullptr){
            p = p->next;
    	}
        p->next = nuevo;
    }
}

/*
* int nPrimo(int x):
*
* Recibe: Recibe un número del arreglo (int x).
*
* Entrega: Retorna un int con el valor del mayor primo de 'x' que
* no sea potencia de 2 (En otras palabras, entrega el primo más
* cercado de la derecha de 'x').
* Esto solo en el caso de que 'x' no sea primo.
*
* Explicación: Primero hay que recordad que un primo es un número que se puede
* dividir solo por 1 y por sí mismo.
* Teniendo esto en cuenta, el algorimo crea una variable auxiliar 'k' el cúal
* almacenara la cantidad de veces que el resto de la división sea distinto de
* 0, junto a una copias del número al que se le desea calcular su primo más
* cercano (a).
* El algorimo empieza contando cada vez que el número 'a' sea mayor que '0',
* una vez hecho esto calcula el módulo entre el número 'x' y el número 'a'. Por
* cada iteración, a se irá restando en '1' hasta que este se haga '0'.
* Una vez sea '0' realiza la comprobación. Si la cantidad de k es igual a '2'
* (Eso indica que es primo) el algoritmo retornará el número en cuestión; en
* caso contrario sumará en '1' el valor de 'x' y volverá a llamar el
* algoritmo. Esto será recursivo hasta que encuentre el próximo más cercano.
*/

int nPrimo(int x){
    int k = 0;
    int a = x;
    while (a > 0){
        if (x%a == 0){
            k++;
        }
        a--;
    }
    if (k == 2 /*|| log2(x)%1 == 0*/){
        return x;
    }
    else{
        x++;
        x = nPrimo(x);
    }
}

/*
* void nullHash(nodoH **T, int n):
*
* Recibe: La tabla hash (nodoH **T), y el largo del arreglo (int n).
*
* Entrega: Al ser un método void no retorna nada, pero recorre la tabla
* hash para darle un valor nulo a cada elemento de este, con el fin de que
* no existan problemas de punteros a la hora de trabajar.
*
* Explicación: Este recorre con un for la tabla de hash y en cada celda T[i],
* le asigna el valor "NULL".
*/

void nullHash(nodoH **T, int n){
	for(int i = 0; i < n; i++){
        T[i] = NULL;
    }
}

/*
* void arrayInHash(nodoH **T, int *Array, int n):
*
* Recibe: La tabla hash (nodoH **T), el arreglo al que sus elementos se quieren
* agregar a la tabla (int *Array) y el largo del arreglo (int n).
*
* Entrega: Al ser un método void no retorna nada, pero recorre el arreglo
* y va insertando sus elementos en la tabla hash T.
*
* Explicación: Este recorre con un for el arreglo *Array completo y hace que
* cada uno de sus elementos sea agregado a la tabla hash por medio del método
* insertH().
*/

void arrayInHash(nodoH **T, int *Array, int n, int m){
	for(int i = 0; i < n; i++){
		insertH(T, m, Array[i]);
	}
}

/*
* int searchH(nodoH **T, int n, int x):
*
* Recibe: El arreglo la tabla de hash (NodoH **T), el tamaño del arreglo
* (int n) y el elemento que se desea buscar (int x).
*
* Entrega: El método retorna la cantidad de veces que encontró el elemento
* 'x' en el arreglo
*
* Explicación: El algoritmo crea un contador "k" inicializado en '0' (El cual
* indicará la cantidad de veces que se encontró con el elemento 'x' dentro del
* arreglo) y empieza a recorrer los punteros de la posición T[h(n, k)], cada
* vez que el valor 'x' coincida con el valor que posee la lista enlazada de esta
* posición, este sumará uno al contador y avanzará el puntero a la celda
* siguiente hasta que el puntero se encuentre en la posición nula (NULL).
*/

int searchH(nodoH **T, int m, int x){
    int k = 0;
		int key = h(m, x);
    if(T[key] != nullptr){
        nodoH *p = T[key];
        while(p != NULL){
            if(p->val == x){
                k++;
            }
            p = p->next;
        }
    }
    return k;
}
