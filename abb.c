#include <stdlib.h>
#include <stdio.h>
#include "abb.h"


void inserta(int dato, Arbol * a){
	if (*a == NULL){
		*a = malloc(sizeof(NodoAbb));

		if(*a != NULL){
			(*a)->dato = dato;
			(*a)->izq = NULL;
			(*a)->der = NULL;

		}else{
			printf("No hay memoria disponible");
		}
	}else{
		if(dato < (*a)->dato){
			inserta(dato,&((*a)->izq));
		}else if(dato > (*a)->dato){
			inserta(dato,&((*a)->der));
		}else{
			printf("ese dato ya existe...");
		}
	}

}

void enorden(Arbol a){
	if(a != NULL){
		enorden(a->izq);
		printf("%d ",a->dato);
		enorden(a->der);
	}
	
}

void preorden(Arbol a){

	if(a != NULL){
		printf("%d ",a->dato);
		preorden(a->izq);
		preorden(a->der);
	}
	
}

void postorden(Arbol a){

	if(a != NULL){
		postorden(a->izq);
		postorden(a->der);
		printf("%d ",a->dato);
	}
	
}

int busca(int i, Arbol a){
	Arbol actual = a;	
	
	while(actual != NULL){
		if(actual->dato == i){
			return 1;
		}else if(i < actual->dato){
			actual = actual->izq;
		}else if(i > actual->dato){
			actual = actual->der;
		}
	}
	return 0;
}


void elimina(int dato, Arbol * a){
	Arbol padre = NULL;
	Arbol actual;
	Arbol nodo;
	int aux;

	actual = *a;

	while (actual != NULL){
		if (dato == actual->dato){
			if(actual->izq == NULL && actual->der == NULL){
				if(padre)
					if(padre->der == actual)
						padre->der = NULL;
					else if(padre->izq == actual)
						padre->izq = NULL;
					free(actual);
					actual = NULL;
					return;
			}else {
				padre = actual;
				if(actual->der){
					nodo = actual->der;
					while (nodo->izq){
						padre = nodo;
						nodo = nodo->izq;
					}
				}else if(actual->izq){
					nodo = actual->izq;
					while (nodo->der){
						padre = nodo;
						nodo = nodo->der;
					}
				}
				aux = actual->dato;
				actual->dato = nodo->dato;
				nodo->dato = aux;
				actual = nodo;

			}
		}else {
			padre = actual;
			if(dato > actual->dato)
				actual = actual->der;
			else if(dato < actual->dato)
				actual = actual->izq;
		}
	}
}




