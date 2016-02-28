 /* Este archivo contiene un pequeño programa de prueba para árbol binario de
   búsqueda de acuerdo al archivo "abb.h".
*/

#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int main() {

  Arbol a = NULL; // Se crea un árbol vacío.

  // Ahora se insertan unos cuantos valores

  inserta(100, &a);
  inserta(200, &a);
  inserta(50, &a);
  inserta(150, &a);
  inserta(250, &a);
  inserta(20, &a);
  inserta(75, &a);
  inserta(60, &a);
  inserta(80, &a);
  inserta(170, &a);
  inserta(230, &a);
  inserta(300, &a);
  inserta(30, &a);
  inserta(120, &a);

  // Un recorrido para ver que todo está bien
  printf("\nBusqueda ENORDEN\n");
  enorden(a);

  // Ahora se hacen algunas búquedas

  if (busca(60, a)) printf("\nmuy bien\n");
  else printf("\nmuy mal\n");

  if (busca(85,a)) printf("\nmuy mal\n");
  else printf("\nmuy bien\n");

  // Ahora borramos un elemento del árbol

  elimina(60, &a);

  // Para ver que se haya hecho bien, se hace un recorrido
  printf("\nBusqueda ENORDEN\n");
  enorden(a);

  // Ahora borramos otro elemento.

  elimina(75, &a);

  // De nuevo, revisamos que todo esté bien
  printf("\nBusqueda ENORDEN\n");
  enorden(a);

  // Finalmente, borramos otro elemento

  elimina(200, &a);
  

  // Revisamos
  printf("\nBusqueda ENORDEN\n");
  enorden(a);

  // Ahora los otros recorridos, para que no hayan sido en balde
  printf("\nBusqueda PREORDEN\n");
  preorden(a);
  printf("\nBusqueda POSTORDEN\n");
  postorden(a);

}
