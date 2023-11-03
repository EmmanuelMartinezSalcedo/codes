#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
float propinas(vector<int> tiempos)
{
    int tiempo_trans = 1;
    int demora = 1;
    float t_prop = 0;
    for (int i = 0; i < tiempos.size();)
    {
        if (tiempos[i] <= tiempo_trans)
        {
            t_prop = t_prop + static_cast<float> (1) / demora;
            i++;
        }
        if (i < tiempos.size())
        {
            tiempo_trans++;
            demora = tiempo_trans - tiempos[i] + 1;
        }
    }
    return t_prop;
}

float propinas_varias(vector<int> tiempos, int k)
{
    int tiempo_trans = 1;
    int demora = 1;
    float t_prop = 0;
    for (int i = 0; i < tiempos.size();)
    {
        for (int j = 0; j < k && i < tiempos.size(); j++)
        {
            if (tiempos[i] <= tiempo_trans)
            {
                t_prop = t_prop + static_cast<float> (1) / demora;
                i++;
            }
        }
        if (i < tiempos.size())
        {
            tiempo_trans++;
            demora = tiempo_trans - tiempos[i] + 1;
        }
    }
    return t_prop;
}
int main()
{
    vector<int> tiempo = { 2,2,3,5,5,5 };
    sort(tiempo.begin(), tiempo.end());
    cout << propinas(tiempo) << endl;
    cout << propinas_varias(tiempo,2);
}
