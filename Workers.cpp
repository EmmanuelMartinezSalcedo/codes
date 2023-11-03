#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<int> encontrarMinimos(vector<vector<int>> matriz) {
    int n = matriz.size();
    vector<int> minimos;

    for (int i = 0; i < n; ++i) {
        // Encontrar el m�nimo en la primera fila.
        int minimo = numeric_limits<int>::max();
        int columna = -1;
        for (int j = 0; j < n; ++j) {
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
                columna = j;
            }
        }

        // A�adir el m�nimo a la soluci�n.
        minimos.push_back(minimo);

        // Eliminar la fila y la columna del m�nimo encontrado.
        matriz.erase(matriz.begin() + i);
        for (int j = 0; j < n - 1; ++j) {
            matriz[j].erase(matriz[j].begin() + columna);
        }
    }

    return minimos;
}
int main()
{
	vector<vector<int>> matrix =
	{ {9,2,7,8},
		{6,4,3,7},
		{5,8,1,8},
		{7,6,9,4} };
    vector<int> solution = encontrarMinimos(matrix);
    for (int i = 0; i < solution.size(); i++)
    {
        cout << solution[0] << ' ';
    }
}