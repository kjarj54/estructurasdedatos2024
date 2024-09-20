#include <iostream>
using namespace std;

struct nodo {
    int n;
    int suma;
    nodo *izq;
    nodo *der;
};

void insertar(nodo *&t, int x) {
    if (t == NULL) {
        t = new nodo;
        t->n = x;
        t->suma = 0;
        t->izq = NULL;
        t->der = NULL;
    } else {
        if (x < t->n) {
            insertar(t->izq, x);
        } else {
            insertar(t->der, x);
        }
    }
}

void sumarNodos(nodo *&ini) {
    if (ini != NULL) {
        sumarNodos(ini->izq);
        sumarNodos(ini->der);
        if (ini->izq != NULL) {
            ini->suma += ini->izq->suma + ini->izq->n;
        }
        if (ini->der != NULL) {
            ini->suma += ini->der->suma + ini->der->n;
        }
    }
}

void imprimirArbol(nodo *t) {
    if (t != NULL) {
        imprimirArbol(t->izq);
        cout << "Nodo: " << t->n << ", Suma: " << t->suma << endl;
        imprimirArbol(t->der);
    }
}

int main() {
    nodo *arbol = NULL;
    insertar(arbol, 10);
    insertar(arbol, 5);
    insertar(arbol, 15);
    insertar(arbol, 3);
    insertar(arbol, 7);
    insertar(arbol, 12);
    insertar(arbol, 18);

    sumarNodos(arbol);

    cout << "Arbol con sumas de nodos:" << endl;
    imprimirArbol(arbol);

    return 0;
}