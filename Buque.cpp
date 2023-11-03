#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> MaximizeCont(vector<int> contenedores, int capacity)
{
    int carga = 0;
    vector<int> contenedoresResp;
    for (int i = 0; i < contenedores.size(); i++)
    {
        contenedoresResp.push_back(0);
    }
    for (int i = 0; i < contenedores.size(); i++)
    {
        if (contenedores[i] + carga <= capacity)
        {
            carga = carga + contenedores[i];
            contenedoresResp[i] = contenedores[i];
        }
    }
    return contenedoresResp;

}
vector<int> MaximizeTons(vector<int> contenedores, int capacity)
{
    int carga = 0;
    vector<int> contenedoresResp;
    for (int i = 0; i < contenedores.size(); i++)
    {
        contenedoresResp.push_back(0);
    }
    for (int i = 0; i < contenedores.size(); i++)
    {
        if (contenedores[i] + carga <= capacity)
        {
            carga = carga + contenedores[i];
            contenedoresResp[i] = contenedores[i];
        }
    }
    return contenedoresResp;

}
bool comparadorMayorAMenor(int a, int b) {
    return a > b;
}
int main()
{
    vector<int> contenedores = { 1,3,2,5,2,3,5,6,8 };
    sort(contenedores.begin(), contenedores.end());
    vector<int> respuesta = MaximizeCont(contenedores, 16);
    for (int i = 0; i < respuesta.size(); i++)
    {
        cout << respuesta[i]<<' ';
    }
    cout << endl;
    sort(contenedores.begin(), contenedores.end(), comparadorMayorAMenor);
    vector<int> respuesta2 = MaximizeTons(contenedores, 16);
    for (int i = 0; i < respuesta2.size(); i++)
    {
        cout << respuesta2[i] << ' ';
    }
}
