#include <iostream>
#include <vector>

using namespace std;
vector<int> DevolverCambio(int P, vector<int> C)
{
    vector<int> X;
    int act = 0;
    int j = C.size() - 1;
    for (int i = 0; i < C.size(); i++)
    {
        X.push_back(0);
    }
    while (act != P)
    {
        while ((C[j] > P - act) && (j > 0))
        {
            j--;
        }
        if (j == 0)
        {
            return {0};
        }
        X[j] = int((P - act) / C[j]);
        act = act + C[j] * X[j];
    }
    return X;
}

int main()
{
    vector<int> Coins = { 1, 2, 5, 10, 20, 50, 100, 200 };
    int Total = 389;
    vector<int> Cambio = DevolverCambio(Total, Coins);
    for (int i = 0; i < Cambio.size(); i++)
    {
        cout << Cambio[i] << ' ';
    }
}
