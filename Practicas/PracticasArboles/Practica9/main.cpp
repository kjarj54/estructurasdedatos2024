//Definir una función para definir si es un árbol perfecto, 
//es un árbol perfecto si todas sus hojas tienen la misma profundidad.
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

bool esPerfectoRec(NodeTree *arbol, int profundidad, int nivel) {
    if (arbol == NULL) {
        return true;
    }
    if (arbol->left == NULL && arbol->right == NULL) {
        return (profundidad == nivel + 1);
    }
    if (arbol->left == NULL || arbol->right == NULL) {
        return false;
    }
    return esPerfectoRec(arbol->left, profundidad, nivel + 1) &&
           esPerfectoRec(arbol->right, profundidad, nivel + 1);
}

int encontrarProfundidad(NodeTree *arbol) {
    int profundidad = 0;
    while (arbol != NULL) {
        profundidad++;
        arbol = arbol->left;
    }
    return profundidad;
}

bool esPerfecto(NodeTree *arbol) {
    int profundidad = encontrarProfundidad(arbol);
    return esPerfectoRec(arbol, profundidad, 0);
}

int main(int argc, char const *argv[])
{
    NodeTree *arbol = NULL;
    insertar(arbol, 10);
    insertar(arbol, 5);
    insertar(arbol, 15);
    insertar(arbol, 3);
    insertar(arbol, 7);
    insertar(arbol, 12);
    insertar(arbol, 17);

    mostrarArbolHorizontal(arbol);

    cout << "El arbol es perfecto: " << (esPerfecto(arbol) ? "Si" : "No") << endl;
    
    return 0;
}
