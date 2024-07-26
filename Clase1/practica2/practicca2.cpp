#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void imprimirTabla(int** resultados, string* candidatos, int distritos, int numCandidatos) {
    cout << setw(10) << "Distrito";
    for (int j = 0; j < numCandidatos; ++j) {
        cout << setw(10) << candidatos[j];
    }
    cout << endl;

    for (int i = 0; i < distritos; ++i) {
        cout << setw(10) << i + 1;
        for (int j = 0; j < numCandidatos; ++j) {
            cout << setw(10) << resultados[i][j];
        }
        cout << endl;
    }
}

void calcularTotales(int** resultados, int* totales, int distritos, int numCandidatos) {
    for (int j = 0; j < numCandidatos; ++j) {
        totales[j] = 0;
        for (int i = 0; i < distritos; ++i) {
            totales[j] += resultados[i][j];
        }
    }
}

void imprimirResultados(int* totales, string* candidatos, int totalVotos, int numCandidatos) {
    cout << "\nTotal de votos por candidato:\n";
    for (int j = 0; j < numCandidatos; ++j) {
        cout << "Candidato " << candidatos[j] << ": " << totales[j]
             << " (" << fixed << setprecision(2) << (totales[j] / (double)totalVotos) * 100 << "%)" << endl;
    }
}

int main() {
    int distritos, numCandidatos;

    cout << "Ingrese el número de distritos: ";
    cin >> distritos;

    cout << "Ingrese el número de candidatos: ";
    cin >> numCandidatos;

    string* candidatos = new string[numCandidatos];
    for (int i = 0; i < numCandidatos; ++i) {
        cout << "Ingrese el nombre del candidato " << char('A' + i) << ": ";
        cin >> candidatos[i];
    }

    int** resultados = new int*[distritos];
    for (int i = 0; i < distritos; ++i) {
        resultados[i] = new int[numCandidatos];
        for (int j = 0; j < numCandidatos; ++j) {
            cout << "Ingrese los votos para " << candidatos[j] << " en el distrito " << i + 1 << ": ";
            cin >> resultados[i][j];
        }
    }

    int* totales = new int[numCandidatos];
    int totalVotos = 0;

    // a) Imprimir la tabla con encabezados incluidos
    imprimirTabla(resultados, candidatos, distritos, numCandidatos);

    // b) Calcular e imprimir el número total de votos recibidos por cada candidato y el porcentaje del total de votos emitidos.
    calcularTotales(resultados, totales, distritos, numCandidatos);
    for (int i = 0; i < numCandidatos; ++i) {
        totalVotos += totales[i];
    }
    imprimirResultados(totales, candidatos, totalVotos, numCandidatos);

    // c) Verificar si algún candidato recibió más del 50% de los votos
    bool ganador = false;
    for (int i = 0; i < numCandidatos; ++i) {
        if (totales[i] > totalVotos / 2) {
            cout << "\nEl candidato " << candidatos[i] << " es el ganador con más del 50% de los votos." << endl;
            ganador = true;
            break;
        }
    }

    // d) Si ningún candidato recibe más del 50% de los votos, imprimir los dos más votados
    if (!ganador) {
        int primero = -1, segundo = -1;
        for (int i = 0; i < numCandidatos; ++i) {
            if (primero == -1 || totales[i] > totales[primero]) {
                segundo = primero;
                primero = i;
            } else if (segundo == -1 || totales[i] > totales[segundo]) {
                segundo = i;
            }
        }
        cout << "\nLos dos candidatos más votados son:\n";
        cout << "Candidato " << candidatos[primero] << " con " << totales[primero] << " votos.\n";
        cout << "Candidato " << candidatos[segundo] << " con " << totales[segundo] << " votos.\n";
    }

    // Liberar memoria
    for (int i = 0; i < distritos; ++i) {
        delete[] resultados[i];
    }
    delete[] resultados;
    delete[] totales;
    delete[] candidatos;

    return 0;
}
