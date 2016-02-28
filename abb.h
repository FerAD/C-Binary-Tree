/* Archivo con las declaraciones necesarias para la implementación de Árboles
   Binarios de Búsqueda. Esta versión es para árboles que guardan números
   enteros.

   El tipo NodoAbb es una estructura que cotiene un número entero (dato) y
   apuntadores a los subárboles izquierdo (izq) y derecho (der).

   El tipo Arbol es un apuntador a NodoAbb.

   Autor: Alberto Oliart Ros
*/

typedef struct NodoAbb_tag NodoAbb;
typedef NodoAbb * Arbol; 
struct NodoAbb_tag {

  int dato;  // El dato que guarda el nodo.
  Arbol izq; // El hijo izquierdo
  Arbol der; // El hijo derecho
};

/* La función nuevo_nodo crea un nuevo nodo que tendrá como dato el número que
   recibe como argumento.
 */

Arbol nuevo_nodo(int);

/* La función inserta toma un dato (número entero) y un árbol y hace la
   inserción del dato en el árbol.

   Nota: Observe que el tipo del segundo parámetro no es un árbol sino un
   apuntador a un árbol.
*/

void inserta(int, Arbol *);

/* La función elimina toma un dato (número entero) y lo elimina del árbol en
   caso de que el dato esté en el árbol. Si el dato que se quiere eliminar no
   está en el árbol, la función debe dejar el árbol tal como está.

   Nota: Observe que el tipo del segundo parámetro es un apuntador a árbol.
*/

void elimina(int, Arbol *);

/* La función busca toma un dato y un árbol y busca el dato en el árbol. Si
   está regresa 1. Si no, regresa 0
*/

int busca(int, Arbol);

/* Las siguientes tres funciones son los recorridos para árboles binarios.
 */

void enorden(Arbol);

void preorden(Arbol);

void postorden(Arbol);
