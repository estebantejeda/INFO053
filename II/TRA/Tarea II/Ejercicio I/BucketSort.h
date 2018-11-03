//Incluir Librerías

#include <iostream>
#include <cstdlib>

using namespace std;

/*
* Se crea una estructura nodo que almacena un numero en cuestión (val) junto
* con un puntero que apunta al siguiente nodo (next)
*/

typedef struct nodoB {
	int val;
	struct nodoB *next;
}nodoB;


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

int h (int n, int x){
    return (n*x)/100;
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
* posición h(n, x) de manera que sea ascenedente. Se validaron tres casos
* posibles a la hora de agregar (Hash en posición h vacía, Hash cuando ya
* posea un valor menor o igual al que ya existe y cuando sea mayor al existente).
* El primer "if" valida si la posición en ese arreglo es nula, en caso de serlo
* lo agrega en primera posición.
* El "else if" es en caso de que la primera posición no esté vacía, aquí lo que
* hace es preguntar si el nuevo valor a agregar es mayor que el valor que ya
* está en la primera posición. En caso de serlo, crea un puntero que recorre
* los nodos mientras el valor sea menor o igual; si esto ocurre lo agrega en
* la posición siguiente.
* El "else" verifica en caso de que el nuevo valor a ingresar en
* el arreglo es menor, en caso de ser así (Es la única opción que queda), lo
* agrega al inicio, haciendo que este nuevo nodo apunte al inicial y luego que
* la raíz apunte al nuevo nodo.
*/

void insert(nodoB **T, int n, int x){
	nodoB *nuevo = new nodoB;
	nuevo->next = nullptr;
    nuevo->val = x;

    if(T[h(n, x)] == nullptr){
        T[h(n, x)] = nuevo;
    }
    else if(nuevo->val > T[h(n, x)]->val){
        nodoB *p = T[h(n, x)];
        while(p->next != nullptr && (p->next)->val <= nuevo->val){
            p = p->next;
        }
        p->next = nuevo;
    }
    else{
        nuevo->next = T[h(n, x)];
        T[h(n, x)] = nuevo;
        }
}


/*
* void orderInArray(nodoB **T, int *Array, int n)
*
* Recibe:  Un arreglo de tipo Hash (nodoB **T), el arreglo que se desea
* ordenar (int *Array) y el largo del arreglo a ordenar (int n).
*
* Entrega: Al ser un método void no retorna nada, pero realiza el método
* va recorriendo el hash y agregando los números que encuentre al arreglo Array.
*
* Explicación: El algoritmo crea un j inicializado en 0 que representa la
* posición que tendrá el arreglo que se desea ordenar.
* Luego de esto se crea un for para recorrer la tabla de hash. Cada vez que
* en la tabla de hash se encuentre un número, este lo almacenará en la posición
* 'j' del arrelgo Array.
* Una vez realizado esto, a j se le sumará '1' para que pase a la celda
* siguiente del arreglo.
*/

void orderInArray(nodoB **T, int *Array, int n){
	int j = 0;
	for(int i = 0; i < n; i++){
			if(T[i] != nullptr){
					nodoB *p = T[i];
					while(p != nullptr){
							Array[j] = p->val;
							j++;
							p = p->next;
					}
			}
	}
}
