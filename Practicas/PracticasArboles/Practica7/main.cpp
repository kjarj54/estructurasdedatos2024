//Realice una función que reciba dos árboles y sume los nodos de las mismas posiciones.

#include <iostream>

using namespace std;
struct nodeTree{
    int data;
    nodeTree *left;
    nodeTree *right;
};

void insertar(nodeTree *&arbol, int data){
    if(arbol == NULL){
        arbol = new nodeTree;
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

void mostrarArbolHorizontal(nodeTree *arbol, int espacio = 0, int incremento = 10){
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

int sumNodes(nodeTree *arbol1, nodeTree *arbol2) {
    if (arbol1 == NULL && arbol2 == NULL) {
        return 0;
    }
    if (arbol1 == NULL) {
        return arbol2->data + sumNodes(NULL, arbol2->left) + sumNodes(NULL, arbol2->right);
    }
    if (arbol2 == NULL) {
        return arbol1->data + sumNodes(arbol1->left, NULL) + sumNodes(arbol1->right, NULL);
    }
    return arbol1->data + arbol2->data + sumNodes(arbol1->left, arbol2->left) + sumNodes(arbol1->right, arbol2->right);
}

void sumaNodos(nodeTree *arbol1, nodeTree *arbol2){
    if(arbol1 == NULL && arbol2 == NULL){
        return;
    }
    if(arbol1 == NULL){
        cout << arbol2->data << " ";
        sumaNodos(NULL, arbol2->left);
        sumaNodos(NULL, arbol2->right);
    }
    if(arbol2 == NULL){
        cout << arbol1->data << " ";
        sumaNodos(arbol1->left, NULL);
        sumaNodos(arbol1->right, NULL);
    }
    cout << arbol1->data + arbol2->data << " ";
    sumaNodos(arbol1->left, arbol2->left);
    sumaNodos(arbol1->right, arbol2->right);

}

int main(int argc, char const *argv[])
{
    nodeTree *arbol1 = NULL;
    nodeTree *arbol2 = NULL;

    insertar(arbol1, 10);
    insertar(arbol1, 5);
    

    insertar(arbol2, 10);
    insertar(arbol2, 5);
    

    mostrarArbolHorizontal(arbol1);
    cout << endl;
    mostrarArbolHorizontal(arbol2);

    cout << "Suma de los nodos de los arboles: " << sumNodes(arbol1, arbol2) << endl;

    cout << "Suma de los nodos de los arboles: ";
    sumaNodos(arbol1, arbol2);

    
    return 0;
}
