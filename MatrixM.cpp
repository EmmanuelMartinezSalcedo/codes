#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixSubtraction(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

vector<vector<int>> matrixAddition(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

vector<vector<int>> strassenMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1, 0));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int m = n / 2;
    vector<vector<int>> A11(m, vector<int>(m));
    vector<vector<int>> A12(m, vector<int>(m));
    vector<vector<int>> A21(m, vector<int>(m));
    vector<vector<int>> A22(m, vector<int>(m));

    vector<vector<int>> B11(m, vector<int>(m));
    vector<vector<int>> B12(m, vector<int>(m));
    vector<vector<int>> B21(m, vector<int>(m));
    vector<vector<int>> B22(m, vector<int>(m));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + m];
            A21[i][j] = A[i + m][j];
            A22[i][j] = A[i + m][j + m];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + m];
            B21[i][j] = B[i + m][j];
            B22[i][j] = B[i + m][j + m];
        }
    }

    vector<vector<int>> P1 = strassenMultiply(A11, matrixSubtraction(B12, B22));
    vector<vector<int>> P2 = strassenMultiply(matrixAddition(A11, A12), B22);
    vector<vector<int>> P3 = strassenMultiply(matrixAddition(A21, A22), B11);
    vector<vector<int>> P4 = strassenMultiply(A22, matrixSubtraction(B21, B11));
    vector<vector<int>> P5 = strassenMultiply(matrixAddition(A11, A22), matrixAddition(B11, B22));
    vector<vector<int>> P6 = strassenMultiply(matrixSubtraction(A12, A22), matrixAddition(B21, B22));
    vector<vector<int>> P7 = strassenMultiply(matrixSubtraction(A11, A21), matrixAddition(B11, B12));

    vector<vector<int>> C11 = matrixAddition(matrixSubtraction(matrixAddition(P5, P4), P2), P6);
    vector<vector<int>> C12 = matrixAddition(P1, P2);
    vector<vector<int>> C21 = matrixAddition(P3, P4);
    vector<vector<int>> C22 = matrixSubtraction(matrixSubtraction(matrixAddition(P5, P1), P3), P7);

    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = C11[i][j];
            C[i][j + m] = C12[i][j];
            C[i + m][j] = C21[i][j];
            C[i + m][j + m] = C22[i][j];
        }
    }

    return C;
}

int main() {
    vector<vector<int>> A = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
    vector<vector<int>> B = { {17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32} };

    vector<vector<int>> C = strassenMultiply(A, B);
    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[i].size(); j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
