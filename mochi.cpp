#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
void intercambiar(vector<tuple<int, float>>& A, int i, int j)
{
    tuple<int, float> temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int pivot(vector<tuple<int, float>>& V, int start, int end)
{
    int i = start;
    float pivote = get<1>(V[end]);
    for (int j = start; j < end; j++)
    {
        if (get<1>(V[j]) >= pivote)
        {
            intercambiar(V, i, j);
            i++;
        }
    }
    intercambiar(V, i, end);
    return i;
}

void quickSort(vector<tuple<int, float>>& V, int start, int end)
{
    if (start < end)
    {
        int pivot_index = pivot(V, start, end);
        quickSort(V, start, pivot_index - 1);
        quickSort(V, pivot_index + 1, end);
    }
}

vector<int> Mochila(int M, vector<int> b, vector<int> p)
{
    vector<int> X;
    for (int i = 0; i < b.size(); i++)
    {
        X.push_back(0);
    }
    int pesoAct = 0;
    vector<tuple<int,float>> bp_relation;
    for (int i = 0; i < b.size(); i++)
    {
        float aux = static_cast<float>(b[i]) / p[i];
        bp_relation.push_back(make_tuple(i, aux));
    }
    quickSort(bp_relation, 0, bp_relation.size() - 1);
    int i = 0;
    while (pesoAct < M)
    {
        int currentIndex = get<0>(bp_relation[i]);
        if (pesoAct + p[currentIndex] <= M)
        {
            X[currentIndex] = 1;
            pesoAct = pesoAct + p[currentIndex];
        }
        else
        {
            X[currentIndex] = (M - pesoAct) / p[currentIndex];
            pesoAct = M;
        }
        i++;
    }
    return X;
}
int main()
{
    vector<int> p = { 10,3,3,4 };
    vector<int> b = { 10,9,9,9 };
    int M = 10;
    vector<int> solution = Mochila(M, b, p);
    for (int i = 0; i < solution.size(); i++)
    {
        cout << solution[i] << ' ';
    }
    cout << endl;
    vector<int> p2 = { 10,3,3,4 };
    vector<int> b2 = { 10,1,1,1 };
    int M2 = 10;
    vector<int> solution2 = Mochila(M2, b2, p2);
    for (int i = 0; i < solution2.size(); i++)
    {
        cout << solution2[i] << ' ';
    }
}

