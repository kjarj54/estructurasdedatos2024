//Cuente la cantidad de hojas de un árbol

#include <iostream>

using namespace std;

struct nodeTree
{
    int data;
    nodeTree *left;
    nodeTree *right;
};

void insertar(nodeTree *&arbol, int dato)
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
            insertar(arbol->left, dato);
        }
        else
        {
            insertar(arbol->right, dato);
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

int contHijos(nodeTree *&arbol){
    if(arbol == NULL){
        return 0;
    }else{
        if(arbol->left == NULL && arbol->right == NULL){
            return 1;
        }else{
            return contHijos(arbol->left) + contHijos(arbol->right);
        }
    }
}

int main(int argc, char const *argv[])
{
    nodeTree *arbol = NULL;

    insertar(arbol, 10);
    insertar(arbol, 5);
    insertar(arbol, 15);
    insertar(arbol, 3);
    insertar(arbol, 7);
    insertar(arbol, 13);
    insertar(arbol, 18);

    mostrarArbolHorizontal(arbol);

    cout << "Cantidad de hojas: " << contHijos(arbol) << endl;   
    return 0;
}
