// ArbolBinarioNormal.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "conio.h"

using namespace std;
struct nodo {
	int dato;
	nodo *izq;
	nodo *der;
};
nodo *raiz = NULL;
void inOrden(nodo * t) {
	if (t != NULL) {
		inOrden(t->izq);
		printf("%3d", t->dato);
		inOrden(t->der);
	}
}

void preOrden(nodo * t) {
	if (t != NULL) {
		printf("%3d", t->dato);
		preOrden(t->izq);
		preOrden(t->der);
	}
}

void postOrden(nodo * t) {
	if (t != NULL) {
		postOrden(t->izq);
		postOrden(t->der);
		printf("%3d", t->dato);
	}
}
void Insertar(nodo *& t, int x)
{
	if (t == NULL)
	{
		t = new struct nodo;
		t->dato = x;
		t->izq = NULL;
		t->der = NULL;
	}
	else
	{
		nodo *aux = t;

		while (aux!=NULL)
		{
			if (x < aux->dato)
			{
				if (aux->izq != NULL)
				{
					aux = aux->izq;
				}
				else
				{
					aux->izq = new nodo;
					aux->izq->dato = x;
					aux->izq->izq = NULL;
					aux->izq->der = NULL;
					aux = NULL;
				}
			}
			else
			{
				if (x > aux->dato)
				{
					if (aux->der != NULL)
					{
						aux = aux->der;
					}
					else
					{
						aux->der = new nodo;
						aux->der->dato = x;
						aux->der->izq = NULL;
						aux->der->der = NULL;
						aux = NULL;
					}
				}
			}
		}
		
	}
}
void invertir(nodo *t)
{
	if (t != NULL)
	{
		invertir(t->izq);
		invertir(t->der);
		nodo *aux=NULL;
		aux = t->der;
		t->der = t->izq;
		t->izq = aux;
	}
}
void verArbol(nodo* arbol, int n)
{
	if (arbol == NULL)
		return;
	verArbol(arbol->der, n + 1);

	for (int i = 0; i<n; i++)
		cout << "   ";

	cout << arbol->dato << endl;

	verArbol(arbol->izq, n + 1);
}
int main()
{
	Insertar(raiz, 50);
	Insertar(raiz, 25);
	Insertar(raiz, 75);
	Insertar(raiz, 10);
	Insertar(raiz, 30);
	Insertar(raiz, 5);
	Insertar(raiz, 15);
	Insertar(raiz, 28);
	Insertar(raiz, 35);
	Insertar(raiz, 60);
	Insertar(raiz, 80);
	Insertar(raiz, 55);
	Insertar(raiz, 73);
	Insertar(raiz, 78);
	Insertar(raiz, 87);
	printf("Arbol\n");
	verArbol(raiz, 1);
	printf("\nInorden\n");
	inOrden(raiz);
	printf("\nPreorden\n");
	preOrden(raiz);
	printf("\nPostOrden\n");
	postOrden(raiz);
	cout << endl;
	system("PAUSE");
	invertir(raiz);
	printf("Arbol\n");
	verArbol(raiz, 1);
	printf("\nInorden\n");
	inOrden(raiz);
	printf("\nPreorden\n");
	preOrden(raiz);
	printf("\nPostOrden\n");
	postOrden(raiz);
	system("PAUSE");
    return 0;
}

