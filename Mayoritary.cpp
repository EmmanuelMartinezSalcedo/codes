#include <iostream>
#include <vector>

using namespace std;

int findMajorityElement(const vector<int>& A) {
    int candidate = -1;
    int count = 0;

    for (int num : A) {
        if (count == 0) {
            candidate = num;
            count = 1;
        }
        else if (num == candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    // Verificar si el candidato es un elemento mayoritario
    count = 0;
    for (int num : A) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > A.size() / 2) {
        return candidate;
    }

    return -1; // No hay un elemento mayoritario
}

int main() {
    vector<int> A = { 1, 2, 2, 3, 2, 2, 1 };

    int majorityElement = findMajorityElement(A);

    if (majorityElement != -1) {
        cout << "El elemento mayoritario es: " << majorityElement << endl;
    }
    else {
        cout << "No hay un elemento mayoritario en el arreglo." << endl;
    }

    return 0;
}