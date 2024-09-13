/*Una matriz de N-filas puede ser vista como N-colas consecutivas,
 donde la operación de introducir un elemento en la cola debería recibir el elemento a introducir y el identificador de la cola i donde se desea meter el elemento. 
 Elabore un método que permita implementar la operación inserta_cola en una sucesión de N-colas en un objeto matriz NxM.  M es la capacidad máxima de cada cola.*/

#include <iostream>

using namespace std;

class nodo{
public:
    int dato;
    nodo *siguente;
    nodo(int valor);
};

nodo::nodo(int valor){
    dato = valor;
    siguente = NULL;
}

class cola{
private:
    nodo *frente;
    nodo *final;
public:
    cola();
    void push(int valor);
    int pop();
    bool vacia();
    void mostrar();
};

void cola::push(int valor){
    nodo *nuevo = new nodo(valor);
    if(frente = NULL){
        frente = nuevo;
        final = nuevo;
    }else{
        final->siguente = nuevo;
        final = nuevo;
    }
}

bool cola::vacia(){
    return frente == NULL;
}

int cola::pop(){
    if(frente == NULL){
        return -1;
    }else{
        int valor = frente->dato;
        nodo *aux = frente;
        frente = frente->siguente;
        delete aux;
    }
}

cola::cola(){
    frente = NULL;
    final = NULL;
}

void cola::mostrar(){
    nodo *aux = frente;
    while(aux != NULL){
        cout<<aux->dato<<"->";
        aux = aux->siguente;
    }
}

class MatrizColas {
private:
    cola **matriz;
    int N;
    int M;

public:
    MatrizColas(int N, int M) : N(N), M(M) {
        matriz = new cola*[N];
        for (int i = 0; i < N; ++i) {
            matriz[i] = new cola();
        }
    }

    ~MatrizColas() {
        for (int i = 0; i < N; ++i) {
            delete matriz[i];
        }
        delete[] matriz;
    }

    void inserta_cola(int valor, int i) {
        if (i < 0 || i >= N) {
            cout << "Identificador de cola inválido" << endl;
            return;
        }
        matriz[i]->push(valor);
    }

    void mostrar() {
        for (int i = 0; i < N; ++i) {
            cout << "Cola " << i << ": ";
            matriz[i]->mostrar();
        }
    }
};

int main(int argc, char const *argv[])
{
    
     int N = 3; 
    int M = 5; 

    MatrizColas matrizColas(N, M);

    matrizColas.inserta_cola(10, 0);
    matrizColas.inserta_cola(20, 1);
    matrizColas.inserta_cola(30, 2);
    matrizColas.inserta_cola(40, 0);
    matrizColas.inserta_cola(50, 1);

    matrizColas.mostrar();

    return 0;
}
