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
    Cliente* sig;
    Cliente();
    ~Cliente();
};




int main(int argc, char const *argv[])
{
    string nombre = "Juan";
    cout<<nombre<<endl;
    return 0;
}
