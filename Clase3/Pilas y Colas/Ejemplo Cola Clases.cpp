#include<iostream>
#include<stdlib.h>
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
		n=0;
		sig=NULL;
		ant=NULL;
	}
	nodo (int n1, nodo *s, nodo *a)
	{
		n=n1;
		sig=s;
		ant=a;
	}
	void setN(int n1)
	{
		n=n1;
	}
	void setSig(nodo *s)
	{
		sig=s;
	}
	void setAnt(nodo *a)
	{
		ant=a;
	}
	int getN()
	{
		return n;
	}
	nodo*& getSig()
	{
		return sig;
	}
	nodo*& getAnt()
	{
		return ant;
	}
};
class Cola
{
private:
	nodo *ini;
	nodo *fin;
public:
	Cola()
	{
		ini=NULL;
		fin=NULL;
	}
	void push( int n)
	{
		nodo *dato=NULL;
		if (ini==NULL)
		{
			ini=new nodo(n,NULL,NULL);
			fin=ini;
		}
		else
		{
			dato=new nodo(n,NULL,fin);
			fin->setSig(dato);
			fin=dato;
		}
	}
	int pop()
	{
		int n=ini->getN();
		ini=ini->getSig();
		return n;
	}
	int top()
	{
		return ini->getN();
	}
	
};
int main (int argc, char *argv[]) {
	
	return 0;
}

