#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct datos {
    int peso;
    char ini;
    char fin;
};

int mat[8][8];
int lista[64] = {0};
int lista2[64] = {0};
datos *listal[8] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
int listamayor[8] = {0};
char letra[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int contp = 0;
int contp2 = 0;
int contl = 0;
int cont = 0;

void insertarL(datos *d) {
    listal[contl] = d;
    contl++;
}

datos* sacal() {
    datos *aux = listal[--contl];
    listal[contl] = nullptr;
    return aux;
}

void insertar(int x) {
    lista[contp++] = x;
}

int saca() {
    int aux = lista[--contp];
    lista[contp] = 0;
    return aux;
}

void insertar2(int x) {
    lista2[contp2++] = x;
}

int saca2() {
    int aux = lista2[--contp2];
    lista2[contp2] = 0;
    return aux;
}

void pesos() {
    int aux;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            aux = mat[i][j];
            if (aux > 0) {
                bool band = false;
                for (int w = 0; w < contp; w++) {
                    if (aux == lista[w]) {
                        band = true;
                        break;
                    }
                }
                if (!band) {
                    insertar(aux);
                }
            }
        }
    }
}

void ordenar() {
    for (int i = 0; i < contp - 1; i++) {
        for (int j = i + 1; j < contp; j++) {
            if (lista[i] > lista[j]) {
                swap(lista[i], lista[j]);
            }
        }
    }
}

bool revisar(char in, char d) {
    for (int i = 0; i < contp2; i++) {
        if (lista2[i] == d) {
            return false;
        }
    }
    return true;
}

bool rev(char in, char inic, char d) {
    if (in == d) return true;

    for (int i = 0; i < contl; i++) {
        if ((listal[i]->ini == inic || listal[i]->fin == inic) &&
            (listal[i]->ini == d || listal[i]->fin == d)) {
            return rev(in, listal[i]->ini, listal[i]->fin);
        }
    }
    return false;
}

void arbolMinimo() {
    for (int w = 0; w < contp; w++) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (lista[w] == mat[i][j]) {
                    if (!rev(letra[i], letra[i], letra[j])) {
                        datos *a = new datos;
                        a->peso = mat[i][j];
                        a->fin = letra[j];
                        a->ini = letra[i];
                        insertarL(a);
                        insertar2(letra[i]);
                        insertar2(letra[j]);
                    }
                }
            }
        }
    }
}

int main() {
    mat[0][2] = 3;  mat[0][4] = 16; mat[0][6] = 16;
    mat[1][4] = 5;  mat[1][6] = 5;
    mat[2][1] = 4;  mat[3][0] = 5;  mat[3][1] = 5;
    mat[3][2] = 3;  mat[3][5] = 2;  mat[4][5] = 5;
    mat[5][7] = 4;  mat[6][3] = 2;  mat[7][4] = 5;
    mat[7][6] = 5;

    mat[2][0] = 3;  mat[4][0] = 16; mat[6][0] = 16;
    mat[4][1] = 5;  mat[6][1] = 5;
    mat[1][2] = 4;  mat[0][3] = 5;  mat[1][3] = 5;
    mat[2][3] = 3;  mat[5][3] = 2;  mat[5][4] = 5;
    mat[7][5] = 4;  mat[3][6] = 2;  mat[4][7] = 5;
    mat[6][7] = 5;

    cout << "     ";
    for (char c : letra) {
        cout.width(4);
        cout << c;
    }
    cout << endl;
    
    for (int i = 0; i < 8; i++) {
        cout.width(4);
        cout << letra[i] << " ";
        for (int j = 0; j < 8; j++) {
            cout.width(4);
            cout << mat[i][j];
        }
        cout << endl;
    }

    cout << "Pesos" << endl;
    pesos();
    ordenar();
    for (int i = 0; i < contp; i++) {
        cout.width(4);
        cout << lista[i];
    }

    arbolMinimo();
    int suma = 0;
    cout << endl << "Arbol Minimo" << endl;
    for (int i = 0; i < contl; i++) {
        cout.width(4);
        cout << listal[i]->ini << "-" << listal[i]->fin << " = " << listal[i]->peso << endl;
        suma += listal[i]->peso;
    }
    cout << "Pesos Minimo = " << suma << endl;
    
    getch();
    return 0;
}
