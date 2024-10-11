/*
Escribir una función que a partir de un árbol binario de búsqueda de enteros 
y un numero entero devuelva el número de nodos del árbol que son estrictamente
 menores que el valor proporcionado.
*/

#include <iostream>

using namespace std;


struct NodeTree{
    int data;
    NodeTree *left;
    NodeTree *right;
};

void insertar(NodeTree *&arbol, int data){
    if(arbol == NULL){
        arbol = new NodeTree;
        arbol->data = data;
        arbol->left = NULL;
        arbol->right = NULL;
    }else{
        if(data < arbol->data){
            insertar(arbol->left, data);
        }else{
            insertar(arbol->right, data);
        }
    }
}

void mostrarArbolHorizontal(NodeTree *arbol, int espacio = 0, int incremento = 10){
    if(arbol == NULL){
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

int contarNodosMenores(NodeTree* arbol, int valor) {
    if (arbol == NULL) {
        return 0;
    }
    if (arbol->data < valor) {
        return 1 + contarNodosMenores(arbol->left, valor) + contarNodosMenores(arbol->right, valor);
    } else {
        return contarNodosMenores(arbol->left, valor);
    }
}

int main(int argc, char const *argv[])
{
    NodeTree *arbol = NULL;
    insertar(arbol, 50);
    insertar(arbol, 30);
    insertar(arbol, 70);
    insertar(arbol, 20);
    insertar(arbol, 40);
    insertar(arbol, 60);

    mostrarArbolHorizontal(arbol);

    cout << "Nodos menores a 50: " << contarNodosMenores(arbol, 50) << endl;
    
    return 0;
}
