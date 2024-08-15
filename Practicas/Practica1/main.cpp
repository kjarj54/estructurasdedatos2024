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

    return 0;
}
