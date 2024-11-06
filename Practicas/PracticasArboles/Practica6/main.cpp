//Un árbol es similar a otro si tiene la misma estructura, verificar si dos árboles son similares.

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

bool isSimilar(NodeTree *arbol1, NodeTree *arbol2){//Similar es similar no sinonimo
    if (arbol1 == NULL && arbol2 == NULL){
        return true;
    }
    if (arbol1 == NULL || arbol2 == NULL){
        return false;
    }
    return isSimilar(arbol1->left, arbol2->left) && isSimilar(arbol1->right, arbol2->right);
}
int main(int argc, char const *argv[])
{
    
    NodeTree *arbol1 = NULL;
    NodeTree *arbol2 = NULL;

    insertar(arbol1, 10);
    insertar(arbol1, 5);
    insertar(arbol1, 15);
    insertar(arbol1, 3);
    insertar(arbol1, 7);
    insertar(arbol1, 12);
    

    insertar(arbol2, 10);
    insertar(arbol2, 4);
    insertar(arbol2, 14);
    insertar(arbol2, 2);
    insertar(arbol2, 6);
    insertar(arbol2, 11);

    mostrarArbolHorizontal(arbol1);
    cout << endl;
    mostrarArbolHorizontal(arbol2);

    cout << isSimilar(arbol1, arbol2) << endl;


    return 0;
}
