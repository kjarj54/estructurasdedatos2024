#include <iostream>

using namespace std;

struct nodo
{
    int n;
    nodo *sig;
    nodo *ant;
};

void insertarOrdenado(nodo *&p, int x) {
    nodo *nuevo = new nodo;
    nuevo->n = x;
    nuevo->sig = NULL;
    nuevo->ant = NULL;

    if (p == NULL) {
        p = nuevo;  
    } else if (p->n >= x) {
        nuevo->sig = p;
        p->ant = nuevo;
        p = nuevo;
    } else {
        nodo *aux = p;
        while (aux->sig != NULL && aux->sig->n < x) {
            aux = aux->sig;
        }
        
        nuevo->sig = aux->sig;
        nuevo->ant = aux;
        
        if (aux->sig != NULL) {
            aux->sig->ant = nuevo;
        }
        
        aux->sig = nuevo;
    }
}

void imprimirLista(nodo *p)
{
    if (p == NULL)
    {
        cout << "Lista vacia" << endl;
    }
    else
    {
        while (p != NULL)
        {
            cout << p->n << "-> ";
            p = p->sig;
        }
    }
}

int main(int argc, char const *argv[])
{
    nodo *lista = NULL;

    insertarOrdenado(lista, 5);
    insertarOrdenado(lista, 3);
    insertarOrdenado(lista, 8);
    insertarOrdenado(lista, 1);
    insertarOrdenado(lista, 7);

    imprimirLista(lista);

    return 0;
}