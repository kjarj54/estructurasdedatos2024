#include <iostream>

#include <vector>

using namespace std;



// Insertion Sort

void insertionSort(vector<int> &vector) {

	int cont = 1;

	while (cont < vector.size()) {

		int aux = vector[cont];

		int tempCont = cont - 1;

		while (tempCont >= 0 && vector[tempCont] > aux) {

			vector[tempCont + 1] = vector[tempCont];

			tempCont--;

		}

		vector[tempCont + 1] = aux;

		cont++;

	}

}



// Búsqueda Binaria Iterativa

bool busquedaBinaria(vector<int> &vector, int valor) {

	int inicio = 0;

	int fin = vector.size() - 1;


	while (inicio <= fin) {

		int mitad = inicio + (fin - inicio) / 2;

		if (vector[mitad] == valor) {

			return true;

		}

		if (valor < vector[mitad]) {

			fin = mitad - 1;

		} else {

			inicio = mitad + 1;

		}

	}

	return false;

}



// Búsqueda Binaria Recursiva

bool busquedaBinariaRecursiva(vector<int> &vector, int valor, int inicio, int fin) {

	if (inicio > fin) {

		return false;

	}

	int mitad = inicio + (fin - inicio) / 2;

	if (vector[mitad] == valor) {

		return true;

	}

	if (valor < vector[mitad]) {

		return busquedaBinariaRecursiva(vector, valor, inicio, mitad - 1);

	} else {

		return busquedaBinariaRecursiva(vector, valor, mitad + 1, fin);

	}

}



// Ordenamiento Burbuja

void OrdenamientoBurbuja(int vector[], int n) {

	for (int i = 0; i < n-1; i++) {

		for (int j = 0; j < n-i-1; j++) {

			if (vector[j] > vector[j+1]) {

				int temp = vector[j];

				vector[j] = vector[j+1];

				vector[j+1] = temp;

			}

		}

	}

}



// Ordenamiento Burbuja con Señal

void burbujaConSenal(int num[], int n) {

	bool ready = true;

	for (int i = 0; i < n; i++) {

		ready = true;

		for (int j = 0; j < n-1-i; j++) {

			if (num[j] > num[j+1]) {

				int aux = num[j];

				num[j] = num[j+1];

				num[j+1] = aux;

				ready = false;

			}

		}

		if (ready) {

			return;

		}

	}

}



// Función principal para probar todos los métodos

int main() {

	vector<int> vec = {29, 10, 14, 37, 13, 25, 19, 7, 8, 2};


	// Prueba del Insertion Sort

	cout << "Vector antes del Insertion Sort: ";

	for (int i = 0; i < vec.size(); ++i) {

		cout << vec[i] << " ";

	}

	cout << endl;


	insertionSort(vec);


	cout << "Vector después del Insertion Sort: ";

	for (int i = 0; i < vec.size(); ++i) {

		cout << vec[i] << " ";

	}

	cout << endl;


	// Prueba de la búsqueda binaria iterativa

	int valor = 13;

	bool encontrado = busquedaBinaria(vec, valor);

	if (encontrado) {

		cout << "El valor " << valor << " se encuentra en el vector." << endl;

	} else {

		cout << "El valor " << valor << " no se encuentra en el vector." << endl;

	}


	// Prueba de la búsqueda binaria recursiva

	int inicio = 0;

	int fin = vec.size() - 1;

	int valor1 = 8;

	bool encontradoRecursivo = busquedaBinariaRecursiva(vec, valor1, inicio, fin);

	if (encontradoRecursivo) {

		cout << "El valor " << valor1 << " se encuentra en el vector." << endl;

	} else {

		cout << "El valor " << valor1 << " no se encuentra en el vector." << endl;

	}


	// Prueba del Ordenamiento Burbuja

	int arregloBurbuja[] = {29, 10, 14, 37, 13, 25, 19, 7, 8, 2};

	int tamano = sizeof(arregloBurbuja) / sizeof(arregloBurbuja[0]);

	OrdenamientoBurbuja(arregloBurbuja, tamano);


	cout << "Arreglo después del Ordenamiento Burbuja: ";

	for (int i = 0; i < tamano; ++i) {

		cout << arregloBurbuja[i] << " ";

	}

	cout << endl;


	// Prueba del Ordenamiento Burbuja con Señal

	int arregloBurbujaSenal[] = {29, 10, 14, 37, 13, 25, 19, 7, 8, 2};

	burbujaConSenal(arregloBurbujaSenal, tamano);


	cout << "Arreglo después del Ordenamiento Burbuja con Señal: ";

	for (int i = 0; i < tamano; ++i) {

		cout << arregloBurbujaSenal[i] << " ";

	}

	cout << endl;


	return 0;

}