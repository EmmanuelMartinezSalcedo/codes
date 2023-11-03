#include <vector>
#include <iostream>
#include <utility>
using namespace std;
int minRetrasoMaximo(vector<pair<int,int>> tareas) {
    int n = tareas.size();

    int tiempoActual = 0; // Tiempo actual de inicio
    int retrasoMaximo = 0; // Retraso máximo

    for (int i = 0; i < n; i++) {
        tiempoActual += tareas[i].first;
        retrasoMaximo = max(retrasoMaximo, tiempoActual - tareas[i].second);
    }

    return retrasoMaximo;
}
int main()
{
    vector<pair<int, int>> tareas = { {3,6},{4,7},{2,8},{5,9} };
    int retraso = minRetrasoMaximo(tareas);

    std::cout << "Retraso máximo: " << retraso << std::endl;
}
