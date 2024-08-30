/*
Implementar una función que recibe una lista de enteros L y
 un número entero n de forma que modifique la lista mediante el borrado de todos los elementos de la lista que tengan este valor.
*/

#include <iostream>

using namespace std;
struct Nodo {
    int dato;
    Nodo* siguiente;
};

void insertar(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

void eliminar(Nodo*& cabeza, int valor) {
    while (cabeza != nullptr && cabeza->dato == valor) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    Nodo* actual = cabeza;
    while (actual != nullptr && actual->siguiente != nullptr) {
        if (actual->siguiente->dato == valor) {
            Nodo* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
        } else {
            actual = actual->siguiente;
        }
    }
}

void mostrar(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}


int main(int argc, char const *argv[])
{
    
    Nodo* lista = nullptr;
    insertar(lista, 1);
    insertar(lista, 2);
    insertar(lista, 3);
    insertar(lista, 2);
    insertar(lista, 4);

    cout << "Lista original: ";
    mostrar(lista);

    eliminar(lista, 2);

    cout << "Lista después de eliminar 2: ";
    mostrar(lista);

    return 0;
}
