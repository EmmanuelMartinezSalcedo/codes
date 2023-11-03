#include <iostream>
#include <vector>

using namespace std;

// Funci�n para buscar el �ndice i tal que X[i] = i en un vector ordenado
int findIndexEqualsValue(const vector<int>& X, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (X[mid] == mid) {
            return mid; // Se encontr� un �ndice que cumple la condici�n
        }
        else if (X[mid] > mid) {
            // El �ndice que buscamos est� en la mitad izquierda
            return findIndexEqualsValue(X, left, mid - 1);
        }
        else {
            // El �ndice que buscamos est� en la mitad derecha
            return findIndexEqualsValue(X, mid, right);
        }
    }

    return -1;
}

int main() {
    vector<int> X = { 1, 2, 3, 3, 4, 5, 5, 6, 8 };

    int index = findIndexEqualsValue(X, 0, X.size() - 1);

    if (index != -1) {
        cout << "Se encontr� un �ndice i tal que X[i] = " << index << endl;
    }
    else {
        cout << "No se encontr� ning�n �ndice i tal que X[i] = i" << endl;
    }

    return 0;
}