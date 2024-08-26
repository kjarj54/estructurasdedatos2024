#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo *sig;
};

class Lista
{
private:
    nodo *ini;

public:
    Lista();
    ~Lista();
    void insertarNodo(int n);
    void mostrarLista();
    void mostrarListaRecursiva(nodo *sig);
    void mostrarBinario(nodo *nod);
    void convertirBinario(int n);
    nodo *getIni();
    void BinarioDecimal();
};

Lista::Lista()
{
    ini = NULL;
}

Lista::~Lista()
{
}

nodo *Lista::getIni()
{
    return ini;
}

void Lista::insertarNodo(int n)
{
    nodo *nuevo = new nodo;
    nuevo->dato = n;
    nuevo->sig = NULL;

    if (ini == NULL)
    {
        ini = nuevo;
    }
    else
    {
        nodo *aux = ini;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void Lista::mostrarLista()
{
    nodo *aux = ini;
    while (aux != NULL)
    {
        cout << aux->dato << "->";
        aux = aux->sig;
    }
}

void Lista::mostrarListaRecursiva(nodo *sig)
{
    if (ini != NULL)
    {
        cout << ini->dato << "->";
        ini->sig;
        mostrarListaRecursiva(ini->sig);
    }
}

void Lista::mostrarBinario(nodo *nod)
{
    if (nod == NULL)
    {
        return;
    }

    convertirBinario(nod->dato);
    cout << "->" ;
    mostrarBinario(nod->sig);
}

void Lista::BinarioDecimal(){

}

void Lista::convertirBinario(int n)
{
    if (n > 1)
    {
        convertirBinario(n / 2);
    }
    cout << n % 2;
}



int main(int argc, char const *argv[])
{
    Lista *lista = new Lista();
    lista->insertarNodo(1);
    lista->insertarNodo(2);
    lista->insertarNodo(3);
    lista->insertarNodo(4);
    lista->insertarNodo(5);
    lista->insertarNodo(6);

    lista->mostrarLista();

    cout << endl;

    lista->mostrarBinario(lista->getIni());



    return 0;
}
