#include <iostream>
#include <vector>

using namespace std;

// Declaración del método de ordenamiento de Shell
void Shell_Method(vector<int>& array) {
    int salto, aux, i;
    bool cambios;

    // Inicia el bucle con 'salto' igual a la mitad de la longitud del arreglo y continúa hasta que 'salto' sea 0.
    for (salto = array.size() / 2; salto != 0; salto /= 2) {
        cambios = true; // Inicializa 'cambios' como verdadero para entrar en el bucle mientras haya cambios.

        // Mientras se realicen cambios, continúa el bucle.
        while (cambios) {
            cambios = false; // Asume que no habrá cambios en esta pasada.

            // Itera a través del array desde 'salto' hasta el final del array.
            for (i = salto; i < array.size(); i++) {
                // Compara el elemento en la posición actual 'i' con el elemento 'salto' posiciones atrás.
                if (array[i - salto] > array[i]) {
                    aux = array[i];                 // Almacena temporalmente el valor en 'aux'.
                    array[i] = array[i - salto];    // Intercambia los elementos.
                    array[i - salto] = aux;         // Coloca el valor almacenado en la posición 'i - salto'.
                    cambios = true;                 // Se realizó un cambio, se establece 'cambios' en verdadero.
                }
            }
        }
    }
}

// Función para mostrar el contenido del vector
void mostrarVector(const vector<int>& array) {
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Ejemplo de uso del método Shell
    vector<int> array = {23, 12, 1, 8, 34, 54, 2, 3};

    cout << "Array original:" << endl;
    mostrarVector(array);

    // Llamada al método de ordenamiento de Shell
    Shell_Method(array);

    cout << "Array ordenado:" << endl;
    mostrarVector(array);

    return 0;
}
