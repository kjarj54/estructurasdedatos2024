<<<<<<< HEAD
//Una función que recibe dos árboles devuelve verdadero si son iguales.
=======
//Una función que recibe dos árboles devuelve verdadero si son iguales
>>>>>>> 6789a002fab6879855501532bb189d32c9e337b4

#include <iostream>

using namespace std;

struct nodeTree
{
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

bool isSame(nodeTree *arbol1, nodeTree *arbol2){//Sinonimo equivalente a isSame
    if (arbol1 == NULL && arbol2 == NULL)
    {
        return true;
    }
    if (arbol1 == NULL || arbol2 == NULL)
    {
        return false;
    }

    return (arbol1->data == arbol2->data) && isSame(arbol1->left, arbol2->left) && isSame(arbol1->right, arbol2->right);
    
    
}
int main(int argc, char const *argv[])
{
<<<<<<< HEAD

=======
    nodeTree *arbol1 = NULL;
    nodeTree *arbol2 = NULL;
    insertar(arbol1, 10);
    insertar(arbol1, 5);
    insertar(arbol2, 10);
    insertar(arbol2, 5);
    insertar(arbol1, 2);
    insertar(arbol2, 2);
    


    mostrarArbolHorizontal(arbol1);
    cout << endl;
    mostrarArbolHorizontal(arbol2);
    cout << endl;

    cout << isSame(arbol1, arbol2) << endl;
    
    
>>>>>>> 6789a002fab6879855501532bb189d32c9e337b4
    return 0;
}
