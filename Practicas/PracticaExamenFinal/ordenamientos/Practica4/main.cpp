#include <iostream>
#include <vector>

using namespace std;

// Función para intercambiar dos elementos
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función para imprimir el vector
void printArray(const vector<int>& arr, int low, int high, int pivotIndex) {
    for (int i = 0; i < arr.size(); i++) {
        if (i == pivotIndex) {
            cout << "[" << arr[i] << "] ";
        } else if (i >= low && i <= high) {
            cout << arr[i] << " ";
        } else {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

// Función para particionar el vector
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Elegimos el último elemento como pivote
    int i = low - 1; // Índice del elemento más pequeño

    cout << "Particionando con pivote " << pivot << ":\n";
    printArray(arr, low, high, high);

    for (int j = low; j < high; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot) {
            i++; // Incrementamos el índice del elemento más pequeño
            swap(arr[i], arr[j]); // Intercambiamos los elementos
            printArray(arr, low, high, high);
        }
    }
    swap(arr[i + 1], arr[high]); // Colocamos el pivote en su posición correcta
    printArray(arr, low, high, i + 1);
    return i + 1; // Devolvemos el índice del pivote
}

// Función principal de QuickSort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Obtenemos el índice del pivote

        // Ordenamos los elementos antes y después del pivote
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char const *argv[]) {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
   
    cout << "Array original: ";
    printArray(arr, 0, n - 1, -1);

    quickSort(arr, 0, n - 1);

    cout << "Array ordenado: ";
    printArray(arr, 0, n - 1, -1);

    return 0;
}