#include <iostream>

using namespace std;

struct nodo
{
    int n;
    nodo *sig;
};

void insertar(nodo *&p, int x)
{
    nodo* aux = p;
    while (aux != NULL)
    {
        aux= aux -> sig;
    }
    aux = new nodo;
    aux->n = x;
    aux->sig = NULL;
}

void insertarCorregido(nodo *&p, int x){
    nodo* aux = p;
    if (aux==NULL)
    {
        aux= new nodo;
        aux->n = x;
        aux->sig = NULL;
        p = aux;
    }
    else{
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = new nodo;
        aux->sig->n = x;
        aux->sig->sig = NULL;
        
    }
    
}
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

bool encontrar(nodo* l, int x){
    if(l == NULL){
        return false;
    }else{
        while(l != NULL){
            if(l->n == x){
                return true;
            }
            l = l->sig;
        }
    }
    return false;
}

void eliminar(nodo *&p, int x){
    nodo* aux = p;
    if(aux == NULL){
        cout << "Lista vacia" << endl;
    }else{
        if(aux->n == x){
            aux = aux->sig;
            p=aux;
        }else{
            while(aux->sig != NULL && aux->sig->n != x){
                aux=aux->sig;
            }
            if(aux->sig == NULL){
                cout << "No se encontro el elemento" << endl;
                return;
            }
            nodo* temp = aux->sig;
            aux->sig = temp->sig;
            p = temp;

        }
    }
}

void mostrar(nodo* l)
{
    if(l==NULL){
        cout << "Lista vacia" << endl;
    }
    else{
        while (l != NULL)
        {
            cout << l->n << " ->";
            l = l->sig;
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    nodo* lista = NULL;
    insertarCorregido(lista, 20);
    insertarCorregido(lista, 15);
    insertarCorregido(lista, 5);
    insertarCorregido(lista, 10);
    mostrar(lista);

    nodo* lista2= NULL;

    insertarOrdenado(lista2, 20);
    insertarOrdenado(lista2, 15);
    insertarOrdenado(lista2, 5);
    insertarOrdenado(lista2, 10);
    insertarOrdenado(lista2, 14);
    mostrar(lista2);

    cout << encontrar(lista2, 14) << endl;

    eliminar(lista2,14);

    return 0;
}
