#include <iostream>
#include <vector>

using namespace std;
vector<int> tareas(vector<int> b, vector<int> d)
{
    vector<int> X;
    for (int i = 0; i < b.size(); i++)
    {
        X.push_back(0);
    }
    int maxDuration = *max(d.begin(), d.end());
    int i = 0;
    int j = 0;
    while (maxDuration >= 1)
    {
        if (d[i] >= maxDuration && X[i] != b[i])
        {
            X[j] = b[i];
            j++;
            i = 0;
            maxDuration--;
        }
        else
        {
            i++;
        }
        if (i > X.size()-1)
        {
            maxDuration--;
            i = 0;
        }
    }
    return X;
}
int main()
{
    vector<int> b = { 20,15,10,7,5,3 };
    vector<int> d = { 3,1,1,3,1,3 };
    vector<int> solution = tareas(b, d);
    for (int i = 0; i < solution.size(); i++)
    {
        cout << solution[i] << ' ';
    }
}
