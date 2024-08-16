// ClasesLista.cpp: define el punto de entrada de la aplicación de consola.
//

#include <iostream>
#include <conio.h>

using namespace std;

class nodo
{
private:
	int n;
	nodo *sig;
	nodo *ant;
public:
	nodo()
	{
		n = 0;
		sig = NULL;
		ant = NULL;
	}
	nodo(int n1, nodo *s, nodo *a)
	{
		n = n1;
		sig = s;
		ant = a;
	}
	void setN(int n1)
	{
		n = n1;
	}
	void setSig(nodo *s)
	{
		sig = s;
	}
	void setAnt(nodo *a)
	{
		ant = a;
	}
	int getN()
	{
		return n;
	}
	nodo* getSig()
	{
		return sig;
	}
	nodo* getAnt()
	{
		return ant;
	}
};
class lista
{
private:
	nodo *ini;
public:
	lista()
	{
		ini = NULL;
	}
	void verLista()
	{
		nodo *aux = ini;
		while (aux != NULL)
		{
			cout << aux->getN() << " <-> ";
			aux = aux->getSig();
		}
		cout <<"NULL"<< endl;
	}
	void insertarNodo(int n)
	{
		nodo *aux=NULL,*dato=NULL;
		if (ini == NULL)
		{
			ini = new nodo(n, NULL,NULL);
		}
		else
		{
			aux = ini;
			while (aux->getSig() != NULL)
			{
				aux = aux->getSig();
			}
			dato = new class nodo(n, NULL,NULL);
			dato->setAnt(aux);
			aux->setSig(dato);
		}
	}
	void insertarOrdenado(int n)
	{
		nodo *aux = NULL, *dato = NULL;
		if (ini == NULL)
		{
			ini = new class nodo(n, NULL, NULL);
		}
		else
		{
			aux = ini;
			if (/*ini*/aux->getN()>n)
			{
				dato = new class nodo(n, aux, NULL);
				aux->setAnt(dato);
				ini = dato;
			}
			else
			{
				bool insertar = false;
				while (aux->getSig() != NULL && !insertar)
				{
					if (aux->getN()<n && aux->getSig()->getN()>n)
					{
						insertar = true;
						dato = new nodo(n, aux->getSig(), aux);
						aux->getSig()->setAnt(dato);
						aux->setSig(dato);
					}
					else
					{
						aux = aux->getSig();
					}
				}
				if (!insertar)
				{
					dato = new nodo(n, NULL, aux);
					aux->setSig(dato);
				}
			}
		}
	}
	void eliminarNodo(int n)
	{
		nodo *aux = ini;
		bool encontro = false;
		while (aux != NULL && !encontro)
		{
			if (aux->getN() == n)
			{
				encontro = true;
			}
			else
			{
				aux = aux->getSig();
			}
		}
		if (encontro)
		{
			if (aux->getAnt() == NULL)
			{
				aux->getSig()->setAnt(aux->getAnt());
				ini = aux->getSig();
			}
			else
			{
				if (aux->getSig() == NULL)
				{
					aux->getAnt()->setSig(aux->getSig());
				}
				else
				{
					aux->getSig()->setAnt(aux->getAnt());
					aux->getAnt()->setSig(aux->getSig());
				}
			}
			
			
		}
	}
};
lista *list;
int main()
{
	list = new lista();
	list->insertarOrdenado(5);
	list->insertarOrdenado(55);
	list->insertarOrdenado(1);
	list->insertarOrdenado(15);
	list->insertarOrdenado(25);
	list->verLista();
	system("PAUSE");
	list->eliminarNodo(25);
	list->verLista();
	system("PAUSE");
	list->eliminarNodo(1);
	list->verLista();
	system("PAUSE");
	list->eliminarNodo(55);
	list->verLista();
	system("PAUSE");
    return 0;
}

