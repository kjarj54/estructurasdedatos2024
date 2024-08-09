#include <iostream>

using namespace std;

struct nodo
{
    int n;
    nodo *sig;
    nodo *ant;
};

void insertarOrdenado(nodo *&p, int x){
    nodo* aux = p;
    if(aux == NULL){
        aux = new nodo;
        aux->n = x;
        aux->sig = NULL;
        p = aux;
    }else{
        if(aux->n > x){
            nodo* nuevo = new nodo;
            nuevo->n = x;
            nuevo->sig = aux;
            p = nuevo;
        }else{
            while (aux->sig != NULL && aux->sig->n < x)
            {
                aux = aux->sig;
            }
            nodo* nuevo = new nodo;
            nuevo->n = x;
            nuevo->sig = aux->sig;
            aux->sig = nuevo;
        }
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
