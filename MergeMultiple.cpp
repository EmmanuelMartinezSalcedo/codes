#include <iostream>
#include <vector>

using namespace std;

// Función para fusionar dos vectores ordenados
vector<int> mergeSortedVectors(const vector<int>& A, const vector<int>& B) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            result.push_back(A[i]);
            i++;
        }
        else {
            result.push_back(B[j]);
            j++;
        }
    }

    while (i < A.size()) {
        result.push_back(A[i]);
        i++;
    }

    while (j < B.size()) {
        result.push_back(B[j]);
        j++;
    }

    return result;
}

// Función principal para combinar varios vectores ordenados
vector<int> mergeSortedVectors(vector<vector<int>>& vectors, int left, int right) {
    if (left == right) {
        return vectors[left];
    }

    int mid = left + (right - left) / 2;
    vector<int> leftResult = mergeSortedVectors(vectors, left, mid);
    vector<int> rightResult = mergeSortedVectors(vectors, mid + 1, right);

    return mergeSortedVectors(leftResult, rightResult);
}

int main() {
    vector<vector<int>> vectors = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    vector<int> mergedVector = mergeSortedVectors(vectors, 0, vectors.size() - 1);

    cout << "Vector combinado y ordenado: ";
    for (int num : mergedVector) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}