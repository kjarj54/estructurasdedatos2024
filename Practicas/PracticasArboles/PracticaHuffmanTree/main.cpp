/*Suponga que cuenta con los caracteres a,b,c,d,e,f tienen probabilidades según la siguiente matriz. Encuentre el árbol de huffman correspondiente, calculando la probabilidad de cada letra que se encuentra en la matriz (15 pts)

+---+---+---+---+---+---+
| a | b | c | d | e | f |
+---+---+---+---+---+---+
| f | e | d | a | b | c |
+---+---+---+---+---+---+

Nota: Probabilidad de “a” se calcula contando la cantidad de “a” y la cantidad total

Probabilidad=CA/TL -> probabilidad=22/100 ->0.22. La probabilidad de “a” seria 0.22.



Algoritmo de Huffman

El algoritmo de Huffman es un algoritmo para la construcción de códigos de Huffmann, desarrollado por David A. Huffmann en 1952 y descrito en “A Method for the Construction of Minimum-Redundancy Codes”.

Este algoritmo toma un alfabeto de n símbolos, junto con sus frecuencias de aparición asociadas, y produce un código de Huffman para ese alfabeto y esas frecuencias.

Descripción

El algoritmo consiste en la creación de un árbol binario que tiene cada uno de los símbolos por hoja, y construido de tal forma que siguiéndolo desde la raíz a cada una de sus hojas se obtiene el código Huffman asociado.

Se crean varios árboles, uno por cada uno de los símbolos del alfabeto, consistiendo cada uno de los árboles en un nodo sin hijos, y etiquetado cada uno con su símbolo asociado y su frecuencia de aparición.

Se toman los dos árboles de menor frecuencia, y se unen creando un nuevo árbol. La etiqueta de la raíz será la suma de las frecuencias de las raíces de los dos árboles que se unen, y cada uno de estos árboles será un hijo del nuevo árbol. También se etiquetan las dos ramas del nuevo árbol: con un 0 la de la izquierda, y con un 1 la de la derecha.

Se repite el paso 2 hasta que sólo quede un árbol.

Con este árbol se puede conocer el código asociado a un símbolo, así como obtener el símbolo asociado a un determinado código.

Para obtener el código asociado a un símbolo se debe proceder del siguiente modo:

Comenzar con un código vacío

Iniciar el recorrido del árbol en la hoja asociada al símbolo

Comenzar un recorrido del árbol hacia arriba

Cada vez que se suba un nivel, añadir al código la etiqueta de la rama que se ha recorrido

Tras llegar a la raíz, invertir el código

El resultado es el código Huffman deseado

Para obtener un símbolo a partir de un código se debe hacer así:

Comenzar el recorrido del árbol en la raíz de éste

Extraer el primer símbolo del código a descodificar

Descender por la rama etiquetada con ese símbolo

Volver al paso 2 hasta que se llegue a una hoja, que será el símbolo asociado al código

En la práctica, casi siempre se utiliza el árbol para obtener todos los códigos de una sola vez; luego se guardan en tablas y se descarta el árbol.

1. Ejemplo de uso

La tabla describe el alfabeto a codificar, junto con las frecuencias de sus símbolos. En el gráfico se muestra el árbol construido a partir de este alfabeto siguiendo el algoritmo descrito.



Árbol para construir el código Huffman del ejemplo SímboloFrecuencia A0,15 B0,30 C0,20 D0,05 E0,15 F0,05 G0,10

Se puede ver con facilidad cuál es el código del símbolo E: subiendo por el árbol se recorren ramas etiquetadas con 1, 1 y 0; por lo tanto, el código es 011. Para obtener el código de D se recorren las ramas 0, 1, 1 y 1, por lo que el código es 1110.

La operación inversa también es fácil de realizar: dado el código 10 se recorren desde la raíz las ramas 1 y 0, obteniéndose el símbolo C. Para descodificar 010 se recorren las ramas 0, 1 y 0, obteniéndose el símbolo A.

*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>
using namespace std;

struct NodeTree
{
    char data;
    int frecuencia;
    NodeTree *left;
    NodeTree *right;

    NodeTree(char data, float frecuencia)
    {
        this->data = data;
        this->frecuencia = frecuencia;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void insertar(NodeTree *&arbol, NodeTree *nuevo)
{
    if (arbol == nullptr)
    {
        arbol = nuevo;
    }
    else if (nuevo->frecuencia < arbol->frecuencia)
    {
        insertar(arbol->left, nuevo); // Insertar en el subárbol izquierdo
    }
    else
    {
        insertar(arbol->right, nuevo); // Insertar en el subárbol derecho
    }
}
void mostrarArbol(NodeTree *root, string codigo)
{
    if (root == nullptr)
        return;

    // Si es una hoja (tiene un carácter asociado)
    if (root->data != '\0')
    {
        cout << root->data << " (" << root->frecuencia << "): " << codigo << endl;
    }

    // Recorremos los hijos izquierdo y derecho
    mostrarArbol(root->left, codigo + "0");
    mostrarArbol(root->right, codigo + "1");
}

int main(int argc, char const *argv[])
{
    int n;
    int cantA = 0, cantB = 0, cantC = 0, cantD = 0, cantE = 0, cantF = 0;
    float probA, probB, probC, probD, probE, probF;

    cout << "Ingrese el tamanyo de la matriz: ";
    cin >> n;

    srand(time(0));

    // Crear la matriz dinámica de tamaño n x n
    char **matriz = new char *[n];
    for (int i = 0; i < n; ++i)
    {
        matriz[i] = new char[n]; // Crear cada fila de la matriz
    }

    // Llenar la matriz con caracteres aleatorios entre 'a' y 'f'
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matriz[i][j] = 'a' + (rand() % 6); // Genera un número aleatorio entre 0 y 5 y le suma 'a'
            if (matriz[i][j] == 'a')
            {
                cantA++;
            }
            else if (matriz[i][j] == 'b')
            {
                cantB++;
            }
            else if (matriz[i][j] == 'c')
            {
                cantC++;
            }
            else if (matriz[i][j] == 'd')
            {
                cantD++;
            }
            else if (matriz[i][j] == 'e')
            {
                cantE++;
            }
            else if (matriz[i][j] == 'f')
            {
                cantF++;
            }
        }
    }

    int total = n * n;
    probA = (float)cantA / total;
    probB = (float)cantB / total;
    probC = (float)cantC / total;
    probD = (float)cantD / total;
    probE = (float)cantE / total;
    probF = (float)cantF / total;

    // Mostrar la matriz
    cout << "Matriz generada:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    queue<NodeTree *> probabilidades;
    if (cantA > 0)
        probabilidades.push(new NodeTree('A', probA));
    if (cantB > 0)
        probabilidades.push(new NodeTree('B', probB));
    if (cantC > 0)
        probabilidades.push(new NodeTree('C', probC));
    if (cantD > 0)
        probabilidades.push(new NodeTree('D', probD));
    if (cantE > 0)
        probabilidades.push(new NodeTree('E', probE));
    if (cantF > 0)
        probabilidades.push(new NodeTree('F', probF));

    cout << "Probabilidades:" << endl;
    cout << "A: " << probA << endl;
    cout << "B: " << probB << endl;
    cout << "C: " << probC << endl;
    cout << "D: " << probD << endl;
    cout << "E: " << probE << endl;
    cout << "F: " << probF << endl;

    NodeTree *arbolHuffman = NULL;
    while (!probabilidades.empty())
    {
        NodeTree *nodo = probabilidades.front();
        probabilidades.pop();
        insertar(arbolHuffman, nodo);
    }

    cout << "Árbol de Huffman:" << endl;
    mostrarArbol(arbolHuffman, "");

    // Liberar la memoria de la matriz
    for (int i = 0; i < n; ++i)
    {
        delete[] matriz[i]; // Liberar cada fila
    }
    delete[] matriz; // Liberar la matriz

    return 0;
}
