#include <iostream>
#include <vector>


using namespace std;    
// Implementación del algoritmo Shaker Sort
void shakerSort(vector<int>& numbers) {
    bool swapped = true;
    int start = 0;
    int end = numbers.size() - 1;

    while (swapped) {
        swapped = false;

        // Primera pasada, de izquierda a derecha
        for (int i = start; i < end; i++) {
            if (numbers[i] > numbers[i + 1]) {
                int temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;
                swapped = true;
            }
        }

        // Si no hubo intercambios, el array ya está ordenado
        if (!swapped) break;

        // Ajusta el final de la pasada y resetea el indicador de cambio
        end--;
        swapped = false;

        // Segunda pasada, de derecha a izquierda
        for (int j = end; j > start; j--) {
            if (numbers[j] < numbers[j - 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j - 1];
                numbers[j - 1] = temp;
                swapped = true;
            }
        }

        // Ajusta el inicio de la siguiente pasada
        start++;
    }
}

// Función para mostrar el contenido del vector
void mostrarVector(const vector<int>& array) {
    for (int num : array) {
        cout << num << " ";
    }
    cout << std::endl;
}

int main() {
    // Ejemplo de uso del método Shaker Sort
    vector<int> numbers = {29, 10, 14, 37, 13, 23, 25, 30};

    cout << "Array original:" << endl;
    mostrarVector(numbers);

    // Llamada al método Shaker Sort
    shakerSort(numbers);

    std::cout << "Array ordenado:" << endl;
    mostrarVector(numbers);

    return 0;
}