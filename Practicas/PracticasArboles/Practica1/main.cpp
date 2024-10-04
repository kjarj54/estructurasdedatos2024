// Escribir una función recursiva que encuentre el número de nodos de un árbol binario
#include <iostream>

using namespace std;

struct nodeTree
{
    int data;
    nodeTree *left;
    nodeTree *right;
};

void insertarIterativo(nodeTree *&arbol, int dato)
{
    if (arbol == NULL)
    {
        arbol = new nodeTree;
        arbol->data = dato;
        arbol->left = NULL;
        arbol->right = NULL;
    }
    else
    {
        while (arbol != NULL)
        {
            if (dato < arbol->data)
            {
                arbol = arbol->left;
            }
            else
            {
                arbol = arbol->right;
            }
        }
        arbol = new nodeTree;
        arbol->data = dato;
        arbol->left = NULL;
        arbol->right = NULL;
    }
}

void insertarRecursivo(nodeTree *&arbol, int dato)
{
    if (arbol == NULL)
    {
        arbol = new nodeTree;
        arbol->data = dato;
        arbol->left = NULL;
        arbol->right = NULL;
    }
    else
    {
        if (dato < arbol->data)
        {
            insertarRecursivo(arbol->left, dato);
        }
        else
        {
            insertarRecursivo(arbol->right, dato);
        }
    }
}

void mostrarPreOrden(nodeTree *&arbol)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        cout << arbol->data << " ";
        mostrarPreOrden(arbol->left);
        mostrarPreOrden(arbol->right);
    }
}

void mostrarInOrden(nodeTree *&arbol)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        mostrarInOrden(arbol->left);
        cout << arbol->data << " ";
        mostrarInOrden(arbol->right);
    }
}

void mostrarPostOrden(nodeTree *&arbol)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        mostrarPostOrden(arbol->left);
        mostrarPostOrden(arbol->right);
        cout << arbol->data << " ";
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
    cout << arbol->data << endl;

    mostrarArbolHorizontal(arbol->left, espacio);
}

int contarNodos(nodeTree *arbol) {
    if (arbol == NULL) {
        return 0;
    } else {
        return 1 + contarNodos(arbol->left) + contarNodos(arbol->right);
    }
}

int contarNodos2(nodeTree *arbol, int contador) {
    if (arbol == NULL) {
        return contador;
    } else {
        contador++;
        contador = contarNodos2(arbol->left, contador);
        contador = contarNodos2(arbol->right, contador);
        return contador;
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
    insertarRecursivo(arbol, 12);
    insertarRecursivo(arbol, 20);

    mostrarArbolHorizontal(arbol);

    cout <<"Cantidad de nodos:"<< contarNodos(arbol)<<endl;
    return 0;
}
