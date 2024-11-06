#include <iostream>

#include <vector>

using namespace std;



void heapify(vector<int>& vector, int tam, int i) {

	//se guarda la posicion del mayor

	int largest = i;

	//se obtiene la posicion del hijo izquierdo

	int left = 2 * i + 1;

	//se obtiene la posicion del hijo derecho

	int right = 2 * i + 2;



	//Si el hijo izquierdo es mayor que el actual, el mas grande ahora es la posicion de la izquierda

	if (left<tam && vector[left]> vector[largest])

		largest = left;

	//Si el hijo derecho es mayor que el actual, el mas grande ahora es la posicion de la derecha

	if (right<tam && vector[right] > vector[largest])

		largest = right;

	//Si hubo un cambio(existe un mayor que el actual) se cambia y se sigue ordenando en el hijo ordenado

	if (largest != i) {

		swap(vector[largest], vector[i]);

		heapify(vector, tam, largest);

	}



}



void heapSort(vector<int>& vector) {

	int n = vector.size();

	//Cambiamos los padres con su hijo mayor que su hermano y padre

	for (int i = n / 2 - 1; i >= 0; i--) {

		heapify(vector, n, i);

	}



	//Cambiar el primero(maximo actual) por el ultimo no ordenado, luego ordenar

	for (int i = n - 1; i > 0; i--) {

		swap(vector[0], vector[i]);

		heapify(vector, i, 0);

	}





}



void printArray(vector<int>& arr) {

	for (int i = 0; i < arr.size(); ++i)

		cout << arr[i] << " ";

	cout << "\n";

}



int main()

{

	vector<int> vector = { 9, 4, 3, 8, 10, 2, 5 };

	cout << "Array antes de ordenar:\n";

	printArray(vector);

	heapSort(vector);

	cout << "\nArray ordenado mediante moticulo (HeapSort):\n";

	printArray(vector);



}