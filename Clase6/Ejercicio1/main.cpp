#include <iostream>
using namespace std;

struct nodo
{
    int dato;
    nodo *izq;
    nodo *der;
};

void insertar(nodo *&t, int x)
{
    if (t == NULL)
    {
        t = new nodo;
        t->dato = x;
        t->izq = NULL;
        t->der = NULL;
    }
    else
    {
        nodo *aux = t;
        while (aux != NULL)
        {
            if (x < aux->dato)
            {
                if (aux->izq == NULL)
                {
                    aux = aux->izq;
                }
                else
                {
                    aux->izq = new nodo;
                    aux->izq->dato = x;
                    aux->izq->izq = NULL;
                    aux->izq->der = NULL;
                }
            }
            else
            {
                if (aux->der == NULL)
                {
                    aux = aux->der;
                }
                else
                {
                    aux->der = new nodo;
                    aux->der->dato = x;
                    aux->der->izq = NULL;
                    aux->der->der = NULL;
                }
            }
        }
    }
}

void insertarRecursivo(nodo *&arbol, int valor)
{
    if (arbol == NULL)
    {
        arbol = new nodo();
        arbol->dato = valor;
        arbol->izq = NULL;
        arbol->der = NULL;
    }
    else
    {
        if (valor < arbol->dato)
        {
            insertarRecursivo(arbol->izq, valor);
        }
        else
        {
            insertarRecursivo(arbol->der, valor);
        }
    }
}

void preOrden(nodo *t)
{
    if (t != NULL)
    {
        cout << t->dato << " ";
        preOrden(t->izq);
        preOrden(t->der);
    }
}

void inOrden(nodo *t)
{
    if (t != NULL)
    {
        inOrden(t->izq);
        cout << t->dato << " ";
        inOrden(t->der);
    }
}

void postOrden(nodo *t)
{
    if (t != NULL)
    {
        postOrden(t->izq);
        postOrden(t->der);
        cout << t->dato << " ";
    }
}

int main(int argc, char const *argv[])
{

    nodo *arbol = NULL;

    insertarRecursivo(arbol, 10);
    insertarRecursivo(arbol, 5);
    insertarRecursivo(arbol, 15);
    insertarRecursivo(arbol, 3);
    
    cout << "Preorden: ";
    preOrden(arbol);
    cout << endl;

    cout << "Inorden: ";
    inOrden(arbol);
    cout << endl;

    cout << "Postorden: ";
    postOrden(arbol);
    return 0;
}
