// Escribir una función recursiva que encuentre la altura de un árbol binario.

#include <iostream>
using namespace std;
struct nodeTree
{
    int dato;
    nodeTree *left;
    nodeTree *right;
};

void insertarRecursivo(nodeTree *&arbol, int dato)
{
    if (arbol == NULL)
    {
        arbol = new nodeTree;
        arbol->dato = dato;
        arbol->left = NULL;
        arbol->right = NULL;
    }
    else
    {
        if (dato < arbol->dato)
        {
            insertarRecursivo(arbol->left, dato);
        }
        else
        {
            insertarRecursivo(arbol->right, dato);
        }
    }
}

void mostrarArbolHorizontal(nodeTree *arbol, int espacio = 0, int incremento = 10)
{
    if (arbol == NULL)
    {
        return;
    }

    espacio += incremento;

    mostrarArbolHorizontal(arbol->right, espacio);

    cout << endl;
    for (int i = incremento; i < espacio; ++i)
    {
        cout << " ";
    }
    cout << arbol->dato << endl;

    mostrarArbolHorizontal(arbol->left, espacio);
}


int alturaArbol(nodeTree *&arbol)
{
    if (arbol == NULL)
    {
        return 0;
    }
    else
    {
        int alturaIzquierda = 1 + alturaArbol(arbol->left);
        int alturaDerecha = 1 + alturaArbol(arbol->right);
        if (alturaIzquierda > alturaDerecha)
        {
            return alturaIzquierda;
        }
        else
        {
            return alturaDerecha;
        }
    }
}

int main(int argc, char const *argv[])
{
    nodeTree *arbol = NULL;
    insertarRecursivo(arbol, 10);
    insertarRecursivo(arbol, 5);
    insertarRecursivo(arbol, 15);
    insertarRecursivo(arbol, 3);
    insertarRecursivo(arbol, 7);

    mostrarArbolHorizontal(arbol);

    cout << "La altura del arbol es: " << alturaArbol(arbol) << endl;
    return 0;
}
