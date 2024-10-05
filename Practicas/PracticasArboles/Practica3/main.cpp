//Las hojas de un árbol son números, los nodos interiores tiene los valores de /,*,-,+, realizar una función que del resultado.

#include <iostream>
using namespace std;


struct nodeTree
{
    char data;
    nodeTree *left;
    nodeTree *right;
};

void insertarRecursivo(nodeTree *&arbol, char dato)
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
        if (dato > arbol->data)
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
    cout << arbol->data << endl;

    mostrarArbolHorizontal(arbol->left, espacio);
}

int operacionNodos(nodeTree *&arbol){
    if (arbol == NULL)
    {
        return 0;
    }
    else
    {
        if (arbol->data == '+')
        {
            return operacionNodos(arbol->left) + operacionNodos(arbol->right);
        }
        else if (arbol->data == '-')
        {
            return operacionNodos(arbol->left) - operacionNodos(arbol->right);
        }
        else if (arbol->data == '*')
        {
            return operacionNodos(arbol->left) * operacionNodos(arbol->right);
        }
        else if (arbol->data == '/')
        {
            return operacionNodos(arbol->left) / operacionNodos(arbol->right);
        }
        else
        {
            return arbol->data - '0';
        }
    }
}

int main(int argc, char const *argv[])
{
    nodeTree *arbol = NULL;

    insertarRecursivo(arbol, '+');
    insertarRecursivo(arbol, '5');
    insertarRecursivo(arbol, '2');
    mostrarArbolHorizontal(arbol);

    cout << "El resultado de la operacion es: " << operacionNodos(arbol) << endl;

    return 0;
}
