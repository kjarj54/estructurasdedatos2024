#include <iostream>
#include <stdlib.h>  
using namespace std;
// Pila 

struct nodo{
	int num;
	nodo *sig;
};

nodo *nuevo=NULL;

void push(nodo *&tope, int n)
{
	nuevo=new nodo;
	nuevo->num=n;
	nuevo->sig= tope;
	tope=nuevo;
}	
int top(nodo *&tope)
{
	if (tope!=NULL)
		return tope->num;
	else
		return NULL;
}

int pop(nodo *&tope)
{
	int n;
	n=tope->num;
	tope=tope->sig;
	return n;
}


void mostrarPila(nodo *&tope)
{
	cout<< "\t LA PILA :   ";
	while(tope!=NULL){
		cout<<tope->num;
		tope= tope->sig;
	}
}

int suma(int n1, int n2){
	int s1;
	s1=n1+n2;
	return s1;
	
}




int main(int argc, char *argv[]) {
	
	
	int N, cont =0;
	int acarreo=0;
	int total=0;
	nodo *pila1=NULL;
	nodo *pila2=NULL;
	nodo *pila3=NULL;
	
	cout<< "\n...Digite los digitos del primer numero de 5 digitos ...";
	cout<<endl;
	
	while (cont < 5){
		cin>>N;
		push(pila1,N);
		cont=cont+1;
	}
	
	cout<< "\n...Digite los digitos del segudno numero de 5 digitos ...";;
	cout<<endl;
	cont=0;
	while (cont < 5){
		cin>>N;
		push(pila2,N);
		cont=cont+1;
	}
	
	
	for(int x=0;x < 5; x++){
		
		total = suma(pop(pila1),pop(pila2))+acarreo;
		if (total > 9){
			acarreo= total / 10;
			total =total % 10;
		}else{
			acarreo=0;
		}
		cout<<"total es.."<<total<<endl;
		push(pila3,total);	
	}
	
	
	
	cout<< "\n..EL TOP pila 1 "<<top(pila1)<<endl;
	cout<<endl;
	
	cout<< "\n..EL TOP  pila 2 "<<top(pila2)<<endl;
	cout<<endl;
	
	cout<< "\n..EL TOP  pila 3 "<<top(pila3)<<endl;
	cout<<endl;
	
	
	
	
	//mostrarPila(pila1);
	system("PAUSE");
	
	return 0;
}
