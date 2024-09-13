/*2.	Se tiene una lista con los datos de los clientes de una compañía de telefonía celular,
 los cuales pueden aparecer repetidos en la lista, si tienen registrado más de un número telefónico.
  La compañía para su próximo aniversario desea enviar un regalo a sus clientes, sin repetir regalos a un mismo cliente.
 Los regalos se encuentran almacenados en una pila de regalos y son la cantidad exacta de clientes,
  por lo cual no fueron suficientes regalos. Se desea elaborar un programa que permita generar una nueva estructura donde los clientes aparezcan sólo una vez con sus regalos asignados.*/

#include <iostream>

using namespace std;

class Cliente
{

public:
    string nombre;
    Cliente *sig;
    Cliente();
    ~Cliente();
};

Cliente::Cliente()
{
    nombre = "";
    sig = NULL;
}

Cliente::~Cliente()
{
    delete sig;
}

class ListaCliente
{
private:
    Cliente *cabeza;

public:
    ListaCliente();
    void agregarCliente(string nombre);
    void mostrarCliente();
    void eliminarCliente(string nombre);
};

ListaCliente::ListaCliente()
{
    cabeza = NULL;
}

void ListaCliente::agregarCliente(string nombre)
{
    Cliente *nuevo = new Cliente();
    nuevo->nombre = nombre;
    nuevo->sig = cabeza;
    cabeza = nuevo;
}

void ListaCliente::mostrarCliente()
{
    Cliente *aux = cabeza;
    while (aux != NULL)
    {
        cout << aux->nombre << "->";
        aux = aux->sig;
    }
}

class NodoRegalo
{
public:
    string regalo;
    NodoRegalo *sig;

    NodoRegalo();
};

NodoRegalo::NodoRegalo()
{
    regalo = "";
    sig = NULL;
}

class PilaRegalo
{
private:
    NodoRegalo *tope;
public:
    PilaRegalo();
    void push(string regalo);
    string pop();

};

void PilaRegalo::push(string regalo){
    NodoRegalo *nuevo = new NodoRegalo();
    nuevo->regalo= regalo;
    nuevo->sig = tope;
    tope= nuevo;
}

PilaRegalo::PilaRegalo(){
    tope = NULL;
}

string PilaRegalo::pop(){
    
}

int main(int argc, char const *argv[])
{

    return 0;
}
