// Escribir un programa que invierta el contenido de una cola.  Puede utilizar estructuras de datos auxiliares para hacerlo.
#include <iostream>
using namespace std;

class nodo
{
public:
    int dato;
    nodo *siguiente;
    nodo(int dato);
};

nodo::nodo(int valor)
{
    this->dato = valor;
    this->siguiente = NULL;
}

class cola
{
private:
    nodo *frente;
    nodo *final;

public:
    cola();
    void push(int valor);
    int pop();
    void mostrar();
    bool vacia();
    void invertir();
};

void cola::push(int valor){
    nodo *nuevo = new nodo(valor);
    if(frente == NULL){
        frente = nuevo;
        final = nuevo;
    }
    else{
        final->siguiente = nuevo;
        final = nuevo;
    }
}

int cola::pop(){
    if(frente == NULL){
        cout << "La cola está vacía" << endl;
        return -1;
    }else{
        int valor = frente->dato;
        nodo *aux = frente;
        frente = frente->siguiente;
        if (frente == NULL)
        {
            final = NULL;
        }
        delete aux;
        return valor;
    }
}
cola::cola(){
    frente = NULL;
    final = NULL;
}



void cola::mostrar(){
    nodo *aux= frente;
    while (aux != NULL)
    {
        cout<<aux->dato<<"->"<<endl;
        aux = aux->siguiente;
    }
    
}

bool cola::vacia(){
    return frente == NULL;
}

void cola::invertir(){
    nodo *pila = NULL;
    while(!vacia()){
        nodo *nuevoNodo = new nodo(pop());
        nuevoNodo->siguiente = pila;
        pila = nuevoNodo;
    }
    while (pila != NULL)
    {
        push(pila->dato);
        nodo *aux = pila;
        pila = pila->siguiente;
        delete aux;
    }
    
}

int main(int argc, char const *argv[])
{
    cola *c = new cola();
    c->push(1);
    c->push(2);
    c->push(3);
    c->push(4);
    c->push(5);
    c->push(6);

    c->mostrar();
    cout << "Invertir" << endl;
    c->invertir();
    c->mostrar();
    return 0;
}
