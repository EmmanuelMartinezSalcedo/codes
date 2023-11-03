#include <iostream>
#include <vector>
#include <algorithm>

struct Licencia {
    double tasaIncremento; // pi
    int indice; // Índice de la licencia original
};

// Función de comparación para ordenar las licencias por tasa de incremento
bool compararPorTasaIncremento(const Licencia& licencia1, const Licencia& licencia2) {
    return licencia1.tasaIncremento < licencia2.tasaIncremento;
}

void adquirirLicencias(std::vector<Licencia>& licencias, int n) {
    int meses = 0;
    double costoTotal = 0.0;

    while (n > 0) {
        // Ordenar las licencias por tasa de incremento
        std::sort(licencias.begin(), licencias.end(), compararPorTasaIncremento);

        // Comprar la licencia más barata
        costoTotal += pow(1 + licencias[0].tasaIncremento, meses) * 100;
        meses++;

        // Reducir la cantidad de licencias que necesitas adquirir
        n--;

        // Actualizar la tasa de incremento para la licencia adquirida
        licencias[0].tasaIncremento++;
    }

    std::cout << "Costo total de adquisición de las licencias: " << costoTotal << " €" << std::endl;
}

int main() {
    int n = 5; // Número de licencias a adquirir
    std::vector<Licencia> licencias = { {0.1, 1}, {0.2, 2}, {0.3, 3}, {0.4, 4}, {0.5, 5} };

    adquirirLicencias(licencias, n);

    return 0;
}