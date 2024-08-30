/*Unos vehículos blindados intentan pasar un puente defectuoso. Para ello forman una cola para atravesarlo y
 la probabilidad de éxito al momento de cruzar el puente es de 0.9 al inicio.
  Cada vez que un vehículo entra al puente, éste se deteriora más y la probabilidad de éxito se reduce en 0.06.
  ¿Para un total de n vehículos blindados, cuantos lograron atravesar el puente? ¿Cuántos cayeron en el intento?
*/
#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(int argc, char const *argv[])
{
    int n;
    cout << "Ingrese el numero de vehiculos blindados: ";
    cin >> n;

    queue<int> vehiculos;
    for (int i = 0; i < n; i++)
    {
        vehiculos.push(i+1);
    }
    
    double probabilidad = 0.9;
    int exitos = 0;
    int fracasos = 0;

    srand(time(0));

    while (!vehiculos.empty()) {
        int vehiculo = vehiculos.front();
        vehiculos.pop();

        double randomValue = (double)rand() / RAND_MAX;
        if (randomValue <= probabilidad) {
            exitos++;
        } else {
            fracasos++;
        }

        probabilidad -= 0.06;
        if (probabilidad < 0) {
            probabilidad = 0;
        }
    }

    cout << "Vehículos que lograron atravesar el puente: " << exitos << endl;
    cout << "Vehículos que cayeron en el intento: " << fracasos << endl;

    return 0;
}
