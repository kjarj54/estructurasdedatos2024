#include "list.h"

list::list()
{
    ini = NULL;
}

list::list(nodo *i)
{
    ini = i;
}

void list::verlist()
{
    nodo *aux = ini;
    while (aux != NULL)
    {
        cout << aux->getN() << "<->";
        aux = aux->getSig();
    }
    cout << endl;
}

void list::insertar(int n)
{
    if (ini == NULL)
    {
        ini = new nodo(n, NULL, NULL);
    }
    else
    {
        nodo *aux = ini;
        while (aux->getSig() != NULL)
        {
            aux = aux->getSig();
        }
        aux->setSig(new nodo(n, NULL, aux));
    }
}

bool list::buscar(int n)
{
    nodo *aux = ini;
    while (aux != NULL)
    {
        if (aux->getN() == n)
        {
            cout << "Encontrado" << endl;
            return true;
        }
        aux = aux->getSig();
    }
}

void list::borrar(int n)
{
    nodo *aux = ini;
    while (aux != NULL)
    {
        if (aux->getN() == n)
        {
            if (aux->getAnt() == NULL)
            {
                ini = aux->getSig();
                delete aux;
				return;
            }
            else
            {
                aux->getAnt()->setSig(aux->getSig());
                delete aux;
				return;
            }
        }
        aux = aux->getSig();
    }
}
