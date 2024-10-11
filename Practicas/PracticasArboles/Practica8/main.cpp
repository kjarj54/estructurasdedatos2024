//Crear una función que de la altura de un nodo dado.

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

int alturaNode(NodeTree *arbol, int dato) {
    if (arbol == NULL) {
        return -1;
    }
    if (arbol->data == dato) {
        return 0;
    } else if (dato < arbol->data) {
        int alturaIzquierda = alturaNode(arbol->left, dato);
        return (alturaIzquierda == -1) ? -1 : 1 + alturaIzquierda;
    } else {
        int alturaDerecha = alturaNode(arbol->right, dato);
        return (alturaDerecha == -1) ? -1 : 1 + alturaDerecha;
    }
}
int main(int argc, char const *argv[])
{
    NodeTree *arbol = NULL;
    insertar(arbol, 10);
    insertar(arbol, 5);
    insertar(arbol, 15);
    insertar(arbol, 4);
    insertar(arbol, 6);
    insertar(arbol, 14);

    mostrarArbolHorizontal(arbol);

    cout << "La altura del nodo es: " << alturaNode(arbol, 10) << endl;   
    return 0;
}
