/*1.	Se tienen dos pilas (stacks) que contienen números enteros; 
la primera ordenada ascendentemente desde el tope hacia el fondo,
 y la segunda ordenada descendentemente desde el tope hacia el fondo.
  Si se cuenta con la clase CPila que contiene las operaciones básicas definidas para pilas,
 elabore un programa que fusione ambas pilas en una tercera ordenada descendentemente desde el tope hacia el fondo.  
 NO debe utilizar pilas auxiliares*/

#include <iostream>

using namespace std;

class nodo
{
    public:
        int num;
        nodo *sig;
        nodo();
        nodo(int n)
        {
            num = n;
            sig = NULL;
        }
};

nodo::nodo(){
    num = NULL;
    sig = NULL;
}

class CPila
{
    private:
        nodo *tope;
    public:
        CPila();
        void push(int n);
        int top();
        int pop();
        void mostrarPila();
        void fusion(CPila *&pila1, CPila *&pila2);
};

CPila::CPila()
{
    tope = NULL;
}

void CPila::push(int n){
    nodo *nuevo = new nodo(n);
    nuevo->sig = tope;
    tope = nuevo;
}

void CPila::mostrarPila(){
    nodo *aux = tope;
    while(aux != NULL){
        cout << aux->num<<"->";
        aux = aux->sig;
    }
}

int CPila::top(){
    if (tope != NULL)
    {
        return tope->num;
    }else{
        return -1;
    }
    
}

int CPila::pop(){
    nodo *aux = new nodo();
    if(tope != NULL){ 
        int n = tope->num;
        aux = tope;
        tope=tope->sig;
        delete aux;
        return n;
    }else {
        return -1;
    }
}

void CPila::fusion(CPila *&pila1, CPila *&pila2 ){
    while (pila1->top() !=-1 || pila2->top() != -1)
    {
        if(pila1->top()==-1){
            push(pila2->pop());
        }else if(pila2->top()==-1){  
            push(pila1->pop());
        }else if(pila1->top() > pila2->top()){
            push(pila1->pop());
        }else{
            push(pila2->pop());
        }
    }
    
}

int main(int argc, char const *argv[])
{
    CPila *pila1 = new CPila();
    CPila *pila2 = new CPila();
    CPila *pilaFusionada = new CPila();

    pila1->push(1);
    pila1->push(3);
    pila1->push(5);

    pila1->mostrarPila();

    pila2->push(6);
    pila2->push(4);
    pila2->push(2);

    pila2->mostrarPila();

    pilaFusionada->fusion(pila1, pila2);

    pilaFusionada->mostrarPila();


    delete pila1;
    delete pila2;
    delete pilaFusionada;

    return 0;
}
