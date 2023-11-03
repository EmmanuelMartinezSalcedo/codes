#include <iostream>
#include <vector>

using namespace std;

// Función para buscar el índice i tal que X[i] = i en un vector ordenado
int findIndexEqualsValue(const vector<int>& X, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (X[mid] == mid) {
            return mid; // Se encontró un índice que cumple la condición
        }
        else if (X[mid] > mid) {
            // El índice que buscamos está en la mitad izquierda
            return findIndexEqualsValue(X, left, mid - 1);
        }
        else {
            // El índice que buscamos está en la mitad derecha
            return findIndexEqualsValue(X, mid, right);
        }
    }

    return -1;
}

int main() {
    vector<int> X = { 1, 2, 3, 3, 4, 5, 5, 6, 8 };

    int index = findIndexEqualsValue(X, 0, X.size() - 1);

    if (index != -1) {
        cout << "Se encontró un índice i tal que X[i] = " << index << endl;
    }
    else {
        cout << "No se encontró ningún índice i tal que X[i] = i" << endl;
    }

    return 0;
}