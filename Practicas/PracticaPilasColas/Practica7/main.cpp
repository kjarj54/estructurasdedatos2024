/*
Usando pilas efectúe operaciones de suma y resta de dos números de más de 10 dígitos. Cada digito es un nodo.

*/

#include <iostream>

using namespace std;

class Nodo {
public:
    int digito;
    Nodo* siguiente;

    Nodo(int d) : digito(d), siguiente(nullptr) {}
};

class Pila {
private:
    Nodo* tope;

public:
    Pila() : tope(nullptr) {}

    void push(int d) {
        Nodo* nuevo = new Nodo(d);
        nuevo->siguiente = tope;
        tope = nuevo;
    }

    int pop() {
        if (tope == nullptr) {
            throw runtime_error("Pila vacía");
        }
        int digito = tope->digito;
        Nodo* temp = tope;
        tope = tope->siguiente;
        delete temp;
        return digito;
    }

    bool estaVacia() {
        return tope == nullptr;
    }
};

Pila sumar(Pila& pila1, Pila& pila2) {
    Pila resultado;
    int acarreo = 0;

    while (!pila1.estaVacia() || !pila2.estaVacia() || acarreo != 0) {
        int suma = acarreo;
        if (!pila1.estaVacia()) {
            suma += pila1.pop();
        }
        if (!pila2.estaVacia()) {
            suma += pila2.pop();
        }
        acarreo = suma / 10;
        resultado.push(suma % 10);
    }

    return resultado;
}

Pila restar(Pila& pila1, Pila& pila2) {
    Pila resultado;
    int prestamo = 0;

    while (!pila1.estaVacia() || !pila2.estaVacia()) {
        int resta = prestamo;
        if (!pila1.estaVacia()) {
            resta += pila1.pop();
        }
        if (!pila2.estaVacia()) {
            resta -= pila2.pop();
        }
        if (resta < 0) {
            resta += 10;
            prestamo = -1;
        } else {
            prestamo = 0;
        }
        resultado.push(resta);
    }

    return resultado;
}

void imprimirPila(Pila& pila) {
    while (!pila.estaVacia()) {
        cout << pila.pop();
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    Pila pila1, pila2;

    // Ejemplo de números de más de 10 dígitos
    string num1 = "123456789012";
    string num2 = "987654321098";

    for (char c : num1) {
        pila1.push(c - '0');
    }

    for (char c : num2) {
        pila2.push(c - '0');
    }

    Pila sumaResultado = sumar(pila1, pila2);
    Pila restaResultado = restar(pila1, pila2);

    cout << "Suma: ";
    imprimirPila(sumaResultado);

    cout << "Resta: ";
    imprimirPila(restaResultado);

    return 0;
}