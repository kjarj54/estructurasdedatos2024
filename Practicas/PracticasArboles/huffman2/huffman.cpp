#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Nodo
{
	float frecuencia;
	Nodo *izq;
	Nodo *der;
	string etiqueta;

	// Constructor para inicializar los miembros del nodo
};

stack<Nodo *> generarPila(string matriz[6][6])
{

	string vector[] = {"a", "b", "c", "d", "e", "f"};
	stack<Nodo *> aux;
	int cont;
	Nodo *nodo;
	for (int v = 0; v < 6; v++)
	{
		cont = 0;
		for (int i = 0; i < 6; i++)
		{

			for (int j = 0; j < 6; j++)
			{

				if (matriz[i][j] == vector[v])
				{

					cont++;
				}
			}
		}

		nodo = new Nodo;
		nodo->frecuencia = static_cast<float>(cont) / 36.0;
		nodo->etiqueta = vector[v];
		nodo->izq = nullptr;
		nodo->der = nullptr;

		aux.push(nodo);
	}

	return aux;
}

void imprimirPila(stack<Nodo *> &pila)
{
	stack<Nodo *> aux; // Pila auxiliar para poder imprimir

	// Transferir los elementos de la pila original a la pila auxiliar
	while (!pila.empty())
	{
		Nodo *temp = pila.top();																// Obtener el elemento superior
		cout << "Etiqueta: " << temp->etiqueta << ", Frecuencia: " << temp->frecuencia << endl; // Imprimir
		aux.push(temp);																			// Pasar el nodo a la pila auxiliar
		pila.pop();																				// Sacar el elemento de la pila original
	}

	// Transferir de vuelta a la pila original
	while (!aux.empty())
	{
		pila.push(aux.top());
		aux.pop();
	}
}

void ordenarPilaAscendente(stack<Nodo *> &pila)
{
	stack<Nodo *> pilaAux; // Pila auxiliar para realizar la ordenaci�n

	// Mientras la pila principal no est� vac�a
	while (!pila.empty())
	{
		// Extraemos el nodo superior de la pila original
		Nodo *temp = pila.top();
		pila.pop();

		// Reorganizamos los elementos en la pila auxiliar
		// Los nodos con menor frecuencia ir�n m�s arriba
		while (!pilaAux.empty() && pilaAux.top()->frecuencia > temp->frecuencia)
		{
			pila.push(pilaAux.top());
			pilaAux.pop();
		}

		// Insertamos el nodo actual en su posici�n correcta en la pila auxiliar
		pilaAux.push(temp);
	}

	// Transferimos los nodos de la pila auxiliar a la pila original tal cual
	// para que el nodo con menor frecuencia quede al tope
	while (!pilaAux.empty())
	{
		pila.push(pilaAux.top());
		pilaAux.pop();
	}
}

Nodo *generarArbol(stack<Nodo *> pila)
{
	Nodo *temp1;
	Nodo *temp2;
	Nodo *nodo;

	imprimirPila(pila);
	cout << endl;

	while (pila.size() > 1)
	{
		// Extraemos los dos nodos con menor frecuencia
		temp1 = pila.top();
		pila.pop();
		temp2 = pila.top();
		pila.pop();

		// Creamos un nuevo nodo que combinar� estos dos nodos
		nodo = new Nodo;
		nodo->frecuencia = temp1->frecuencia + temp2->frecuencia;
		nodo->etiqueta = temp1->etiqueta + temp2->etiqueta; // El nodo padre no tiene etiqueta
		nodo->der = temp1;									// temp1 es el hijo izquierdo
		nodo->izq = temp2;									// temp2 es el hijo derecho

		// Insertamos el nuevo nodo en la pila
		pila.push(nodo);

		// Ordenamos la pila despu�s de insertar el nuevo nodo
		ordenarPilaAscendente(pila);

		imprimirPila(pila);
		cout << endl;
	}

	// Cuando quede un solo nodo, ese es la ra�z del �rbol
	nodo = pila.top();
	pila.pop();

	return nodo;
}

void mostrarMensaje(string codigo, Nodo *raiz)
{
	cout << endl;
	Nodo *aux = raiz;
	string mensaje = "";
	for (int i = 0; i < codigo.size(); i++)
	{
		cout << aux->etiqueta << " ";

		if (codigo[i] == '1')
		{

			aux = aux->der;
		}
		else if (codigo[i] == '0')
		{

			aux = aux->izq;
		}

		if (aux->der == nullptr && aux->izq == nullptr)
		{

			cout << aux->etiqueta << " ";
			mensaje = mensaje + aux->etiqueta;
			aux = raiz;
		}
	}
	cout << endl;
	cout << mensaje;
}

int main(int argc, char *argv[])
{

	string matriz[6][6] = {
		{"a", "a", "f", "b", "c", "d"},
		{"e", "b", "b", "c", "a", "a"},
		{"e", "b", "e", "c", "c", "a"},
		{"d", "b", "e", "c", "a", "a"},
		{"c", "b", "b", "e", "a", "d"},
		{"a", "f", "f", "d", "c", "d"},
	};

	Nodo *raiz = generarArbol(generarPila(matriz));
	mostrarMensaje("000010000100001101100", raiz);

	return 0;
}
