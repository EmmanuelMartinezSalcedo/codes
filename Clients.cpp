#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

// Estructura para representar un cliente
struct Cliente {
    std::vector<double> caracteristicas;
};

// Función para calcular la distancia entre dos clientes
double calcularDistancia(const Cliente& c1, const Cliente& c2) {
    double distancia = 0.0;
    for (size_t i = 0; i < c1.caracteristicas.size(); i++) {
        distancia += pow(c1.caracteristicas[i] - c2.caracteristicas[i], 2);
    }
    return sqrt(distancia);
}

// Función para encontrar el índice del grupo más cercano para un cliente
int encontrarGrupoMasCercano(const Cliente& cliente, const std::vector<Cliente>& centroides) {
    double distanciaMinima = std::numeric_limits<double>::max();
    int indiceGrupo = -1;

    for (int i = 0; i < centroides.size(); i++) {
        double distancia = calcularDistancia(cliente, centroides[i]);
        if (distancia < distanciaMinima) {
            distanciaMinima = distancia;
            indiceGrupo = i;
        }
    }

    return indiceGrupo;
}

// Función para actualizar los centroides de los grupos
void actualizarCentroides(const std::vector<Cliente>& clientes, const std::vector<int>& asignaciones, std::vector<Cliente>& centroides) {
    std::vector<std::vector<double>> sumas(centroides.size(), std::vector<double>(clientes[0].caracteristicas.size(), 0.0));
    std::vector<int> conteo(centroides.size(), 0);

    for (int i = 0; i < clientes.size(); i++) {
        int grupo = asignaciones[i];
        for (int j = 0; j < clientes[i].caracteristicas.size(); j++) {
            sumas[grupo][j] += clientes[i].caracteristicas[j];
        }
        conteo[grupo]++;
    }

    for (int i = 0; i < centroides.size(); i++) {
        for (int j = 0; j < centroides[i].caracteristicas.size(); j++) {
            if (conteo[i] > 0) {
                centroides[i].caracteristicas[j] = sumas[i][j] / conteo[i];
            }
        }
    }
}

// Función para aplicar el algoritmo K-Means
void kMeans(std::vector<Cliente>& clientes, int k) {
    if (clientes.empty() || k <= 0 || k > clientes.size()) {
        std::cerr << "Entrada inválida" << std::endl;
        return;
    }

    std::vector<Cliente> centroides;
    centroides.reserve(k);

    // Inicializar centroides aleatoriamente
    for (int i = 0; i < k; i++) {
        int indiceAleatorio = rand() % clientes.size();
        centroides.push_back(clientes[indiceAleatorio]);
    }

    std::vector<int> asignaciones(clientes.size(), -1);
    bool cambios = true;

    while (cambios) {
        cambios = false;

        // Asignar cada cliente al grupo más cercano
        for (int i = 0; i < clientes.size(); i++) {
            int grupo = encontrarGrupoMasCercano(clientes[i], centroides);
            if (asignaciones[i] != grupo) {
                cambios = true;
                asignaciones[i] = grupo;
            }
        }

        if (cambios) {
            // Actualizar centroides
            actualizarCentroides(clientes, asignaciones, centroides);
        }
    }

    // Imprimir los resultados
    for (int i = 0; i < k; i++) {
        std::cout << "Grupo " << i << " (Centroide): ";
        for (double caracteristica : centroides[i].caracteristicas) {
            std::cout << caracteristica << " ";
        }
        std::cout << std::endl;

        std::cout << "Clientes en el Grupo " << i << ":" << std::endl;
        for (int j = 0; j < clientes.size(); j++) {
            if (asignaciones[j] == i) {
                std::cout << "Cliente " << j << ": ";
                for (double caracteristica : clientes[j].caracteristicas) {
                    std::cout << caracteristica << " ";
                }
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    // Ejemplo de uso
    int k = 3; // Número de grupos
    std::vector<Cliente> clientes = {
        {{1.0, 2.0, 3.0}},
        {{4.0, 5.0, 6.0}},
        {{7.0, 8.0, 9.0}},
        {{2.0, 3.0, 4.0}},
        {{5.0, 6.0, 7.0}},
        {{8.0, 9.0, 10.0}}
    };

    kMeans(clientes, k);

    return 0;
}
