#include <iostream>
#include <stdio.h>

using namespace std;

/*
Estructura:
val: entero creado aleatoriamente
alturaIzq: Valor de la altura izquierda del nodo
alturaDer: Valor de la altura derecha del nodo
fe: Almacenara el factor equilibrio

Punteros:
izq: Apunta a la izquierda del nodo
der: Apunta a la derecha del nodo
padre Apunta hacia el padre del nodo
*/

typedef struct nodo{
	int val;
	struct nodo *izq, * der,*padre;
	int alturaIzq, alturaDer,fe;
}avl;

avl* creanodo(int val);
void insertarNuevo(avl *recorrer, avl *nuevo,avl *padre);
void verArbol(avl* recorrer,int n);

avl* creanodo(int val){
	avl *nuevo= new avl;
	nuevo->val=val;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	nuevo->alturaIzq=0;
	nuevo->alturaDer=0;
	nuevo->fe = nuevo->alturaDer-nuevo->alturaIzq;
	
	return nuevo;
}

avl *raiz, *nuevo,*recorrer,*padre,*hijo,*predecesor,*abuelo,*nieto;

void insertarNuevo(avl *recorrer, avl *nuevo,avl *padre){
	if(raiz==NULL){
		raiz = nuevo;
		raiz->padre=NULL;
	}
	else{
		if(nuevo->val<=recorrer->val){
			if(recorrer->izq!=NULL){
				padre = recorrer->izq;
				insertarNuevo(recorrer->izq,nuevo,padre);
			}
			else{
				recorrer->izq=nuevo;
				nuevo->padre=padre;
				return;
			}
			
		}
		else if(nuevo->val>recorrer->val){
			if(recorrer->der!=NULL){
				padre=recorrer->der;
				insertarNuevo(recorrer->der,nuevo,padre);
			}
			else{
				recorrer->der=nuevo;
				nuevo->padre=padre;
				return;
			}
		}
	}
}

void verArbol(avl* recorrer,int n){
		if(recorrer == NULL){
			return;
		}
		verArbol(recorrer->der,n+1);

		for(int i = 0 ;i<n;i++)
			cout<<"   ";

		cout<<recorrer->val<<endl;
		
		verArbol(recorrer->izq,n+1);
		
	}

int main(int argc, char **argv){
	int n=8;
	for(int i=0;i<n;i++){
		instertarNuevo(recorrer,creanuevo(random()%20),padre);		
	}
	verArbol(recorrer,n);	
}	
