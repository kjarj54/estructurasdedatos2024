#include<iostream>
#include<stdlib.h>
using namespace std;
struct Nodo
{
	int n;
	Nodo *sig;
	Nodo *ant;
};
Nodo *dato = NULL, *ini = NULL, *aux = NULL;
void insertar(Nodo *&p, int n) // insertar recursivo
{
	if (p == NULL) {
		dato = new struct Nodo;
		dato->n = n;
		dato->sig = NULL;
		dato->ant=NULL;
		p = dato;
	}
	else
	{
		if (p->n>n && p==ini) {
			dato = new struct Nodo;
			dato->n = n;
			dato->sig = p;
			dato->ant=NULL;
			p->ant=dato;
			p = dato;
		}
		else
		{
			if (p->n<n&&p->sig == NULL) {
				dato = new struct Nodo;
				dato->n = n;
				dato->sig = NULL;
				dato->ant=p;
				p->sig = dato;
			}
			else
			{ 
				if (p->n<n && p->sig->n>n) {
					dato = new struct Nodo;
					dato->n = n;
					dato->sig = p->sig;
					p->sig->ant=dato;
					dato->ant=p;
					p->sig = dato;
				}
				else
				{
					insertar(p->sig, n);
				}
			}
		}
	}
}
void mostrar(struct Nodo *l) {
	//clrscr();
	while (l != NULL) {
		if (l->ant==NULL)
		{
			if (l->sig==NULL)
			{
				cout<< l->n<<"(NULL,NULL)"<<endl;
			}
			else
			{
				cout<< l->n<<"(NULL,"<<l->sig->n<<")"<<endl;
			}
		}
		else
		{
			if (l->sig==NULL)
			{
				cout<< l->n<<"("<<l->ant->n<<",NULL)"<<endl;
			}
			else
			{
				cout<< l->n<<"("<<l->ant->n<<","<<l->sig->n<<")"<<endl;
			}
		}
		l = l->sig;
	}
	system("PAUSE");
	cout<<endl;
}
void eliminarNodo(int n)
{
	Nodo *aux = ini;
	bool encontro = false;
	while (aux != NULL && !encontro)
	{
		if (aux->n == n)
		{
			encontro = true;
		}
		else
		{
			aux = aux->sig;
		}
	}
	if (encontro)
	{
		if (aux->ant == NULL)
		{
			aux->sig->ant=aux->ant;
			ini = aux->sig;
		}
		else
		{
			if (aux->sig == NULL)
			{
				aux->ant->sig=aux->sig;
			}
			else
			{
				aux->sig->ant=aux->ant;
				aux->ant->sig=aux->sig;
			}
		}
		
		
	}
}
int main()
{
	cout<<"UNO"<<endl;
	insertar(ini, 50);
	mostrar(ini);
	cout<<"DOS"<<endl;
	insertar(ini, 20);
	mostrar(ini);
	cout<<"tres"<<endl;
	insertar(ini, 30);
	mostrar(ini);
	cout<<"cuatro"<<endl;
	insertar(ini, 10);
	mostrar(ini);
	cout<<"cinco"<<endl;
	insertar(ini, 35);
	mostrar(ini);
	cout<<"seis"<<endl;
	insertar(ini, 60);
	mostrar(ini);
	cout<<"siete"<<endl;
	insertar(ini, 40);
	mostrar(ini);
	cout<<"Ocho"<<endl;
	eliminarNodo( 40);
	mostrar(ini);
	return 0;
}
