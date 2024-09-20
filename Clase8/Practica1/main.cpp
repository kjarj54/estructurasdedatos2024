#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo *der;
    nodo *izq;
    int altura;
    int fe;
};

// II ID DD DI  Rotaciones
void II(nodo *&n)
{
    nodo *nod = NULL;
    nodo *nod1 = NULL;
    nodo *nod2 = NULL;
    nod = n;
    nod1 = nod->izq;
    nod->izq = nod1->der;
    nod1->der = nod;
    nod = nod1;
    nod->fe = 0;
    nod1->fe = 0;
    n = nod;
}
void DD(nodo *&n)
{
    nodo *nod = n;
    nodo *nod1 = nod->der;
    nodo *nod2 = NULL;
    nod->der = nod1->izq;
    nod1->izq = nod;
    nod = nod1;
    nod->fe = 0;
    nod1->fe = 0;
    n = nod;
}
void DI(nodo *&n)
{
    nodo *nod = NULL;
    nodo *nod1 = NULL;
    nodo *nod2 = NULL;
    nod = n;
    nod1 = nod->der;
    nod2 = nod1->izq;
    nod1->izq = nod2->der;
    nod2->der = nod1;
    nod->der = nod2->izq;
    nod2->izq = nod;
    nod = nod2;
    nod->fe = -1;
    nod1->fe = 0;
    nod2->fe = 0;
    n = nod;
}
void ID(nodo *&n)
{
    nodo *nod = NULL;
    nodo *nod1 = NULL;
    nodo *nod2 = NULL;
    nod = n;
    nod1 = nod->izq;
    nod2 = nod1->der;
    nod1->der = nod2->izq;
    nod2->izq = nod1;
    nod->izq = nod2->der;
    nod2->der = nod;
    nod = nod2;
    nod->fe = 0;
    nod1->fe = 0;
    nod2->fe = 0;
    n = nod;
}

void insertarArborl(nodo *&arbol, int dato)
{
    if (arbol == NULL)
    {
        arbol = new nodo();
        arbol->dato = dato;
        arbol->der = NULL;
        arbol->izq = NULL;
    }
    else
    {
        if (dato < arbol->dato)
        {
            insertarArborl(arbol->izq, dato);
        }
        else
        {
            insertarArborl(arbol->der, dato);
        }
    }
}

// Metodo que devuelve la altura

int altura(nodo *arbol)
{
    if (arbol == NULL)
    {
        return -1;
    }
    return arbol->altura;
}

// Modificar el insertar para balancear el arbol tomando en cuenta la altura y el factor de equilibrio y las rotaciones
void insertarBalanceadoRecursivo(nodo *&arbol, int dato)
{
    if (arbol == NULL)
    {
        arbol = new nodo();
        arbol->dato = dato;
        arbol->der = NULL;
        arbol->izq = NULL;
        arbol->altura = 0;
        arbol->fe = 0;
    }
    else
    {
        if (dato < arbol->dato)
        {
            insertarBalanceadoRecursivo(arbol->izq, dato);
        }
        else
        {
            insertarBalanceadoRecursivo(arbol->der, dato);
        }

        arbol->altura = 1 + max(altura(arbol->izq), altura(arbol->der));
        arbol->fe = altura(arbol->der) - altura(arbol->izq);

        if (arbol->fe > 1)
        {
            if (arbol->der->fe >= 0)
            {
                // Rotación DD
                DD(arbol);
            }
            else
            {
                // Rotación DI
                DI(arbol);
            }
        }
        else if (arbol->fe < -1)
        {
            if (arbol->izq->fe <= 0)
            {
                // Rotación II
                II(arbol);
            }
            else
            {
                // Rotación ID
                ID(arbol);
            }
        }
    }
}

void mostrarArbolHorizontal(nodo *arbol, int espacio = 0, int incremento = 10)
{
    if (arbol == NULL)
    {
        return;
    }

    espacio += incremento;

    mostrarArbolHorizontal(arbol->der, espacio);

    cout << endl;
    for (int i = incremento; i < espacio; ++i)
    {
        cout << " ";
    }
    cout << arbol->dato << endl;

    mostrarArbolHorizontal(arbol->izq, espacio);
}

int main(int argc, char const *argv[])
{
    // Árbol AVL balanceado
cout << "Árbol AVL balanceado:" << endl;
nodo *arbolAVL = NULL;
insertarBalanceadoRecursivo(arbolAVL, 10);
insertarBalanceadoRecursivo(arbolAVL, 5);
insertarBalanceadoRecursivo(arbolAVL, 15);
insertarBalanceadoRecursivo(arbolAVL, 3);
insertarBalanceadoRecursivo(arbolAVL, 7);
insertarBalanceadoRecursivo(arbolAVL, 12);
insertarBalanceadoRecursivo(arbolAVL, 18);
mostrarArbolHorizontal(arbolAVL);

// Árbol no balanceado
cout << "\nÁrbol binario de búsqueda simple (no balanceado):" << endl;
nodo *arbolNoBalanceado = NULL;
insertarArborl(arbolNoBalanceado, 10);
insertarArborl(arbolNoBalanceado, 5);
insertarArborl(arbolNoBalanceado, 15);
insertarArborl(arbolNoBalanceado, 3);
insertarArborl(arbolNoBalanceado, 7);
insertarArborl(arbolNoBalanceado, 12);
insertarArborl(arbolNoBalanceado, 18);
mostrarArbolHorizontal(arbolNoBalanceado);


    return 0;
}
