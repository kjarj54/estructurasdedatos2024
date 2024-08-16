#include <iostream>

using namespace std;

struct NodeSimple
{
    int n;
    NodeSimple *sig;

};

struct NodeDouble
{
    int n;
    NodeDouble *sig;
    NodeDouble *ant;
};

void insertarNodoSimple(NodeSimple *&nodeSimple, int numero){
    NodeSimple *nuevo = nodeSimple;
    if(nuevo == NULL){
        nuevo = new NodeSimple();
        nuevo->n = numero;
        nuevo->sig = NULL;
        nodeSimple = nuevo;

    }else{
        while (nuevo->sig != NULL)
        {
            nuevo = nuevo->sig;
        }
        nuevo->sig = new NodeSimple();
        nuevo->sig->n = numero;
        nuevo->sig->sig = NULL;
        
    }
}

void imprimirNodoSimple(NodeSimple  *nodeSimple){
    while (nodeSimple != NULL)
    {
        cout << nodeSimple->n << " ->";
        if(nodeSimple-> sig == NULL){
            cout << "NULL";

        }
        nodeSimple = nodeSimple->sig;
    }
    
}
    

void insertarNodoDouble(NodeDouble *&nodeDouble, int numero){
    NodeDouble *nuevo = nodeDouble;
    if(nuevo == NULL){
        nuevo = new NodeDouble();
        nuevo-> n = numero;
        nuevo->sig = NULL;
        nuevo->ant = NULL;
        nodeDouble = nuevo;
    }else{
        while (nuevo->sig != NULL)
        {
            nuevo = nuevo->sig;
        }
        
    }

}

void eliminar(NodeSimple *&nodeSimple, int numero){
    NodeSimple *aux_borrar;
    NodeSimple *anterior = NULL;
    aux_borrar = nodeSimple;
    while ((aux_borrar != NULL) && (aux_borrar->n != numero))
    {
        anterior = aux_borrar;
        aux_borrar = aux_borrar->sig;
    }
    if(aux_borrar == NULL){
        cout << "El elemento no existe";
    }else if(anterior == NULL){
        nodeSimple = nodeSimple->sig;
        delete aux_borrar;
    }else{
        anterior->sig = aux_borrar->sig;
        delete aux_borrar;
    }

}

void eliminarDouble(NodeDouble *&nodeDouble, int numero){
    NodeDouble *aux_borrar;
    NodeDouble *anterior = NULL;
    aux_borrar = nodeDouble;
    while ((aux_borrar != NULL) && (aux_borrar->n != numero))
    {
        anterior = aux_borrar;
        aux_borrar = aux_borrar->sig;
    }
    if(aux_borrar == NULL){
        cout << "El elemento no existe";
    }else if(anterior == NULL){
        nodeDouble = nodeDouble->sig;
        delete aux_borrar;
    }else{
        anterior->sig = aux_borrar->sig;
        delete aux_borrar;
    }

}

int main(int argc, char const *argv[])
{
    NodeSimple *nodeSimple = NULL;
    NodeDouble *nodeDouble = NULL;
    insertarNodoSimple(nodeSimple, 1);
    insertarNodoSimple(nodeSimple, 2);
    insertarNodoSimple(nodeSimple, 3);
    insertarNodoSimple(nodeSimple, 4);
    insertarNodoSimple(nodeSimple, 5);
    insertarNodoSimple(nodeSimple, 6);
    insertarNodoSimple(nodeSimple, 7);
    insertarNodoSimple(nodeSimple, 8);
    insertarNodoSimple(nodeSimple, 9);
    insertarNodoSimple(nodeSimple, 10);
    imprimirNodoSimple(nodeSimple);
    return 0;
}
