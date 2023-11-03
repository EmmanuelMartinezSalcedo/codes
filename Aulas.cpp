#include <vector>
#include <iostream>
#include <utility>

using namespace std;

vector<vector<pair<int, int>>> aulass(vector<pair<int, int>> clases, int aulas)
{
    // Matriz de aulas para representar las aulas disponibles
    vector<vector<pair<int, int>>>
        aulas_disponibles(aulas);

    // Iterar a través de las clases y asignarlas a las aulas disponibles
    for (const auto& clase : clases)
    {
        bool asignada = false;

        // Recorrer las aulas disponibles para buscar una aula libre
        for (int i = 0; i < aulas; i++)
        {
            // Verificar si el aula está libre (no se superpone con clases existentes)
            bool aula_libre = true;
            for (const auto& otra_clase : aulas_disponibles[i])
            {
                if (clase.first < otra_clase.second && clase.second > otra_clase.first)
                {
                    aula_libre = false;
                    break;
                }
            }

            // Si el aula está libre, asignar la clase y romper el bucle
            if (aula_libre)
            {
                aulas_disponibles[i].push_back(clase);
                asignada = true;
                break;
            }
        }

        // Si no se pudo asignar la clase en ninguna aula, crear una nueva aula
        if (!asignada)
        {
            aulas_disponibles.push_back({ clase });
        }
    }

    return aulas_disponibles;
}

int main()
{
    vector<pair<int, int>> clases = { {7, 8}, {8, 12}, {9, 10}, {16, 17}, {1, 2} };
    int aulas = 3;

    vector<vector<pair<int, int>>> resultado = aulass(clases, aulas);

    // Imprimir las clases asignadas a cada aula
    for (int i = 0; i < resultado.size(); i++)
    {
        cout << "Aula " << i + 1 << ": ";
        for (const auto& clase : resultado[i])
        {
            cout << "(" << clase.first << "-" << clase.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
