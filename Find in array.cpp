#include <iostream>
using namespace std;

int searchInSubmatrix(int x, int A[4][4], int rowStart, int rowEnd, int colStart, int colEnd) {
    if (rowStart > rowEnd || colStart > colEnd)
        return 0;

    int rowMid = (rowStart + rowEnd) / 2;
    int colMid = (colStart + colEnd) / 2;

    if (A[rowMid][colMid] == x)
        return 1;
    else if (A[rowMid][colMid] > x) {
        return searchInSubmatrix(x, A, rowStart, rowMid - 1, colStart, colEnd) | searchInSubmatrix(x, A, rowMid, rowEnd, colStart, colMid - 1);
    }
    else {
        return searchInSubmatrix(x, A, rowStart, rowMid, colMid + 1, colEnd) | searchInSubmatrix(x, A, rowMid + 1, rowEnd, colStart, colEnd);
    }
}

int inArray(int x, int A[4][4], int n) {
    return searchInSubmatrix(x, A, 0, n - 1, 0, n - 1);
}


int main() {
    int Arr[4][4] = { {1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16} };
    int sol = inArray(2, Arr, 4);
    cout << sol;
    return 0;
}