//TAREA SEMANA IV

#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;
struct Nodo {
    int valor;
    Nodo* siguiente;
};

struct NodoDoble {
    int valor;
    NodoDoble* siguiente;
    NodoDoble* anterior;
};

void insertarAlInicio(Nodo*& lista, int valor) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->valor = valor;
    nuevo_nodo->siguiente = lista;
    lista = nuevo_nodo;
}

void mostrarLista(Nodo* lista) {
    Nodo* actual = lista;
    while (actual != nullptr) {
        cout << actual->valor << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}
void eliminarNodos(Nodo*& lista, int valorMaximo) {
    Nodo* actual = lista;
    Nodo* anterior = nullptr;
    while (actual != nullptr) {
        if (actual->valor > valorMaximo) {
            if (anterior == nullptr) {
                lista = actual->siguiente;
                delete actual;
                actual = lista;
            } else {
                anterior->siguiente = actual->siguiente;
                delete actual;
                actual = anterior->siguiente;
            }
        } else {
            anterior = actual;
            actual = actual->siguiente;
        }
    }
}

void insertarEnListaDoble(NodoDoble*& lista, int valor) {
    NodoDoble* nuevo_nodo = new NodoDoble();
    nuevo_nodo->valor = valor;
    nuevo_nodo->siguiente = nullptr;
    nuevo_nodo->anterior = nullptr;

    if (lista == nullptr) {
        lista = nuevo_nodo;
    } else {
        NodoDoble* actual = lista;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = actual;
    }
}
void mostrarListaDoble(NodoDoble* lista) {
    NodoDoble* actual = lista;
    cout << "Lista doblemente enlazada(numeros pares):" << endl;
    while (actual != nullptr) {
        cout << actual->valor << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}
int main() {
    Nodo* lista = nullptr;
    NodoDoble* listaDoble = nullptr;
    srand(time(0)); 
   
    for (int i = 0; i < 10; i++) {
        insertarAlInicio(lista, rand() % 100);
    }

    cout << "Lista enlazada simple:" << endl;
    mostrarLista(lista);

    eliminarNodos(lista, 50);
    cout << "Lista después de eliminar nodos con valor mayor a 50:" << endl;
    mostrarLista(lista);

    Nodo* actual = lista;
    while (actual != nullptr) {
        if (actual->valor % 2 == 0) {
            insertarEnListaDoble(listaDoble, actual->valor);
        }
        actual = actual->siguiente;
    }

    mostrarListaDoble(listaDoble);

    return 0;
}
