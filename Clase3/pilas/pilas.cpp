//---------------------------------------------------------------------------

// #include <vcl.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#pragma hdrstop

#include <tchar.h>
//---------------------------------------------------------------------------


//#pragma argsused
/*int *pila[20];
int tope=0;
int max=20;  */
struct nodo
{
	int n;
	nodo *sig;
	nodo *ant;
};
nodo *tope=NULL;
nodo *dato=NULL;
using namespace std;
void push(int x)
{
	if (tope==NULL) {
		dato=new struct nodo;
		dato->n=x;
		dato->ant=NULL;
		dato->sig=NULL;
		tope=dato;
	}
	else
	{
     	dato=new struct nodo;
		dato->n=x;
		dato->ant=tope;
		tope->sig=dato;
		dato->sig=NULL;
		tope=dato;
	}
	/**pila[tope]=x;
	 tope++; */
}
int pop()
{
	int num;
	num=tope->n;
	tope=tope->ant;
	tope->sig=NULL;
	return num;
	/*int num;
	tope--;
	num=(int)*pila[tope];
	*pila[tope]=NULL;
	return num;*/
}
int _tmain(int argc, _TCHAR* argv[])
{
	/*for (int i = 0; i < 20; i++) {
		pila[i]= new int;
		*pila[i]=NULL;
	}   */
	push(10);
	push(15);
	push(25);
	push(5);
	push(7);
	push(9);
	cout<<"Pop: "<<pop()<<endl;;
	cout<<"Pop: "<<pop()<<endl;;
	cout<<"Pop: "<<pop()<<endl;
	push(99);
	cout<<"Pop: "<<pop()<<endl;;
	getch();
	return 0;
}
//---------------------------------------------------------------------------
