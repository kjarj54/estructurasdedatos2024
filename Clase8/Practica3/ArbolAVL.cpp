// ArbolAVL.cpp: define el punto de entrada de la aplicaci�n de consola.
//

#include "iostream"
#include "stdio.h"
using namespace std;

struct nodo
{
	int dato;
	nodo *izq;
	nodo *der;
	int altura;
	int fe;
};
///////////////////////////////////////////////////
nodo *raiz = NULL; //nodo raiz
				   ///////////////////////////////////////////////////
nodo *nod = NULL;   //Nodo auxiliares para insertar
nodo *nod1 = NULL;  //Nodo auxiliares para insertar
nodo *nod2 = NULL;  //Nodo auxiliares para insertar
					//////////////////////////////////////////////////
nodo *otro = NULL; //nodo auxiliar para eliminar
nodo *aux = NULL;  //nodo auxiliar para eliminar
nodo *aux1 = NULL; //nodo auxiliar para eliminar
				   //////////////////////////////////////////////////
int max(int x, int y)
{
	if (x>y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
void actualizarAltura(nodo *&n)
{
	int i, d;
	if (n->izq == NULL)
		i = 0;
	else
	{
		actualizarAltura(n->izq);
		i = n->izq->altura;
	}
	if (n->der == NULL)
		d = 0;
	else
	{
		actualizarAltura(n->der);
		d = n->der->altura;
	}
	n->altura = max(i, d) + 1;
}
void actualizarFE(nodo *&n)
{
	int i, d;
	if (n->izq == NULL)
		i = 0;
	else
	{
		actualizarFE(n->izq);
		i = n->izq->altura;
	}
	if (n->der == NULL)
		d = 0;
	else
	{
		actualizarFE(n->der);
		d = n->der->altura;
	}
	n->fe = d - i;
}
void II(nodo *&n)
{
	nod = NULL;
	nod1 = NULL;
	nod2 = NULL;
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
	nod = n;
	nod1 = nod->der;
	nod2 = NULL;
	nod->der = nod1->izq;
	nod1->izq = nod;
	nod = nod1;
	nod->fe = 0;
	nod1->fe = 0;
	n = nod;
}
void DI(nodo *&n)
{
	nod = NULL;
	nod1 = NULL;
	nod2 = NULL;
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
	nod = NULL;
	nod1 = NULL;
	nod2 = NULL;
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
void insertar(nodo *&n, int d)
{
	if (n == NULL)
	{
		n = new struct nodo;
		n->dato = d;
		n->altura = 1;
		n->izq = NULL;
		n->der = NULL;
		n->fe = 0;
	}
	else
	{
		if (d>n->dato)
		{
			insertar(n->der, d);
		}
		else
		{
			if (d<n->dato)
			{
				insertar(n->izq, d);
			}
		}
	}
	actualizarAltura(n);
	actualizarFE(n);
	if (n->fe<-1)
	{
		if (n->izq->fe<0)
		{
			II(n);
		}
		if (n->izq->fe>0)
		{
			ID(n);
		}
	}
	if (n->fe>1)
	{
		if (n->der->fe>0)
		{
			DD(n);
		}
		if (n->der->fe<0)
		{
			DI(n);
		}
	}
	actualizarAltura(n);
	actualizarFE(n);

}
void eliminar(nodo *&n, int x)
{
	bool bo;
	if (n != NULL)
	{
		if (n->dato<x)
		{
			eliminar(n->der, x);
		}
		if (n->dato>x)
		{
			eliminar(n->izq, x);
		}
		if (n->dato == x)
		{
			otro = n;
			if (otro->der == NULL)
			{
				n = otro->izq;
			}
			else
			{
				if (otro->izq == NULL)
				{
					n = otro->der;
				}
				else
				{
					aux = n->izq;
					bo = false;
					while (aux->der != NULL)
					{
						aux1 = aux;
						aux = aux->der;
						bo = true;
					}
					n->dato = aux->dato;
					otro = aux;
					if (bo == true)
					{
						aux1->der = aux->izq;
					}
					else
					{
						n->izq = aux->izq;
					}
				}

			}
		}
		if (n != NULL)
		{
			actualizarAltura(n);
			actualizarFE(n);
			if (n->fe<-1)
			{
				if (n->izq->fe<0)
				{
					II(n);
				}
				else
					//if(n->izq->fe>0)
				{
					ID(n);
				}
			}
			if (n->fe>1)
			{
				if (n->der->fe>0)
				{
					DD(n);
				}
				else
					//if(n->der->fe<0)
				{
					DI(n);
				}
			}
			actualizarAltura(n);
			actualizarFE(n);
		}
	}
	else
	{
		cout << "Nodo no encontrado" << endl;
	}
}
void mostrar(nodo *&n, int x)
{
	if (n == NULL)
	{
		return;
	}

	mostrar(n->der, x + 1);
	for (int i = 0; i<x; i++)
		cout << "     ";
	cout << n->dato << "-" << n->altura << "-" << n->fe << endl;
	mostrar(n->izq, x + 1);
}
int main(int argc, char* argv[])
{
	int r;
	char s;
	int x;
	insertar(raiz, 65);
	insertar(raiz, 50);
	insertar(raiz, 23);
	insertar(raiz, 70);
	insertar(raiz, 82);
	insertar(raiz, 68);
	insertar(raiz, 39);
	do
	{
		cout << "1-Ingresar" << endl;
		cout << "2-Ver arbol" << endl;
		cout << "3-Eliminar" << endl;
		cin >> r;
		switch (r)
		{
		case 1:
			cout << "Digite el nodo que desea ingresar" << endl;
			cin >> x;
			insertar(raiz, x);
			break;
		case 2:
			mostrar(raiz, 0);
			break;
		case 3:
			cout << "Digite el nodo que desea buscar" << endl;
			cin >> x;
			eliminar(raiz, x);
			break;
		default:
			cout << "Tecla invalidad" << endl;
			break;
		}
		/*cout<<"Desea realizar alguna otra opcion"<<endl;
		cout<<"s/S para continuar"<<endl;
		cin>>s;*/
	} while (true);
	//}while(s!='s' || s!= 'S');
	return 0;
}
//---------------------------------------------------------------------------