#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

struct Venta {
    int cantidad;
    Venta(int cantidad) : cantidad(cantidad) {}
};

struct Empleado {
    string nombre;
    int sumatoria;
    list<Venta> ventas;
    Empleado* siguiente;
    Empleado(string nombre) : nombre(nombre), sumatoria(0), siguiente(nullptr) {}
};

struct Piso {
    string nombre;
    int sumatoria;
    list<Empleado> empleados;
    Piso* anterior;
    Piso* siguiente;
    Piso(string nombre) : nombre(nombre), sumatoria(0), anterior(nullptr), siguiente(nullptr) {}
};

void insertarEmpleado(Piso* piso, string nombreEmpleado, list<int> cantidades) {
    Empleado nuevoEmpleado(nombreEmpleado);
    auto itCantidades = cantidades.begin();
    
    while (itCantidades != cantidades.end()) {
        nuevoEmpleado.ventas.push_back(Venta(*itCantidades));
        ++itCantidades;
    }

    nuevoEmpleado.ventas.sort([](const Venta& a, const Venta& b) {
        return a.cantidad > b.cantidad;
    });

    nuevoEmpleado.sumatoria = 0;
    auto itCantidad = cantidades.begin();
    while (itCantidad != cantidades.end()) {
        nuevoEmpleado.sumatoria += *itCantidad;
        ++itCantidad;
    }

    auto it = piso->empleados.begin();
    while (it != piso->empleados.end() && it->nombre < nuevoEmpleado.nombre) {
        ++it;
    }
    piso->empleados.insert(it, nuevoEmpleado);

    piso->sumatoria += nuevoEmpleado.sumatoria;
}

void mostrarDatos(Piso* inicio) {
    Piso* actual = inicio;
    while (actual != nullptr) {
        cout << "Piso: " << actual->nombre << " - Sumatoria: " << actual->sumatoria << endl;
        
        auto itEmpleado = actual->empleados.begin();
        while (itEmpleado != actual->empleados.end()) {
            cout << "  Empleado: " << itEmpleado->nombre << " - Sumatoria: " << itEmpleado->sumatoria << endl;

            auto itVenta = itEmpleado->ventas.begin();
            while (itVenta != itEmpleado->ventas.end()) {
                cout << "    Venta: " << itVenta->cantidad << endl;
                ++itVenta;
            }

            ++itEmpleado;
        }

        actual = actual->siguiente;
    }
}


void verificarSumatorias(Piso* inicio) {
    Piso* actual = inicio;
    while (actual != nullptr) {
        int sumatoriaPiso = 0;

        auto itEmpleado = actual->empleados.begin();
        while (itEmpleado != actual->empleados.end()) {
            int sumatoriaEmpleado = 0;

            auto itVenta = itEmpleado->ventas.begin();
            while (itVenta != itEmpleado->ventas.end()) {
                sumatoriaEmpleado += itVenta->cantidad;
                ++itVenta;
            }

            if (sumatoriaEmpleado != itEmpleado->sumatoria) {
                cout << "Error en sumatoria del empleado " << itEmpleado->nombre << " en el piso " << actual->nombre << endl;
            }

            sumatoriaPiso += sumatoriaEmpleado;
            ++itEmpleado;
        }

        if (sumatoriaPiso != actual->sumatoria) {
            cout << "Error en sumatoria del piso " << actual->nombre << endl;
        }

        actual = actual->siguiente;
    }
}

void eliminarPiso(Piso*& inicio, string nombrePiso) {
    Piso* actual = inicio;
    while (actual != nullptr && actual->nombre != nombrePiso) {
        actual = actual->siguiente;
    }

    if (actual != nullptr) {
        Piso* anterior = actual->anterior;
        if (anterior != nullptr) {
            auto itEmpleado = actual->empleados.begin();
            while (itEmpleado != actual->empleados.end()) {
                insertarEmpleado(anterior, itEmpleado->nombre, { itEmpleado->sumatoria });
                ++itEmpleado;
            }

            anterior->siguiente = actual->siguiente;
            if (actual->siguiente != nullptr) {
                actual->siguiente->anterior = anterior;
            }
            delete actual;
        } else {
            cout << "No se puede eliminar el primer piso" << endl;
        }
    }
}

void menu() {
    Piso* inicio = new Piso("Piso 1");
    int opcion;
    do {
        cout << "1. Insertar Empleado\n2. Mostrar Datos\n3. Verificar Sumatorias\n4. Eliminar Piso 3\n5. Salir\n";
        cin >> opcion;
        switch (opcion) {
            case 1:
                
                break;
            case 2:
                mostrarDatos(inicio);
                break;
            case 3:
                verificarSumatorias(inicio);
                break;
            case 4:
                eliminarPiso(inicio, "Piso 3");
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida" << endl;
        }
    } while (opcion != 5);
}


int main() {
    Piso* inicio = new Piso("Piso 1");
    insertarEmpleado(inicio, "Carlos", {200, 100});
    insertarEmpleado(inicio, "Mario", {0});

    Piso* piso2 = new Piso("Piso 2");
    inicio->siguiente = piso2;
    piso2->anterior = inicio;
    insertarEmpleado(piso2, "Ana", {300});

    Piso* piso3 = new Piso("Piso 3");
    piso2->siguiente = piso3;
    piso3->anterior = piso2;
    insertarEmpleado(piso3, "Pedro", {1000, 500});

    menu();
    return 0;
}