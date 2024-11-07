#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define INF 99999
#define V 4 // Número de vértices

// Función para imprimir la matriz de adyacencia
void printMatrix(const vector<vector<int>>& matrix) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == INF)
                cout << setw(4) << "INF";
            else
                cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    cout << "---------------------" << endl;
}

int main() {
    // Inicializamos la matriz de adyacencia con INF para indicar que no hay conexiones
    vector<vector<int>> graph(V, vector<int>(V, INF));

    // Establecemos la diagonal principal en 0 (distancia a sí mismo)
    for (int i = 0; i < V; i++)
        graph[i][i] = 0;

    cout << "Matriz inicial:" << endl;
    printMatrix(graph);

    // Agregar aristas una a una y mostrar el proceso
    // (nodo origen, nodo destino, peso)
    vector<tuple<int, int, int>> edges = {
        {0, 1, 3}, {0, 3, 7}, {1, 2, 2}, {2, 0, 5}, {3, 0, 2}
    };

    // Agregamos cada arista al grafo y mostramos la matriz
    for (const auto& edge : edges) {
        int u, v, weight;
        tie(u, v, weight) = edge;

        // Agregar la arista en ambas direcciones si el grafo es no dirigido
        graph[u][v] = weight;

        // Mostrar la matriz de adyacencia después de agregar cada arista
        cout << "Después de agregar la arista " << u << " -> " << v << " con peso " << weight << ":" << endl;
        printMatrix(graph);
    }

    return 0;
}
