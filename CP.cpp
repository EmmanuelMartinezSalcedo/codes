#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;
void intercambiarx(vector<pair<int, int>>& A, int i, int j)
{
    pair<int, int> temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int pivotx(vector<pair<int, int>>& V, int start, int end)
{
    int i = start;
    int pivote = V[end].first;
    for (int j = start; j < end; j++)
    {
        if (V[j].first <= pivote)
        {
            intercambiarx(V, i, j);
            i++;
        }
    }
    intercambiarx(V, i, end);
    return i;
}

void quickSortx(vector<pair<int, int>>& V, int start, int end)
{
    if (start < end)
    {
        int pivot_index = pivotx(V, start, end);
        quickSortx(V, start, pivot_index - 1);
        quickSortx(V, pivot_index + 1, end);
    }
}

void intercambiary(vector<pair<int, int>>& A, int i, int j)
{
    pair<int, int> temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int pivoty(vector<pair<int, int>>& V, int start, int end)
{
    int i = start;
    int pivote = V[end].second;
    for (int j = start; j < end; j++)
    {
        if (V[j].second <= pivote)
        {
            intercambiary(V, i, j);
            i++;
        }
    }
    intercambiary(V, i, end);
    return i;
}

void quickSorty(vector<pair<int, int>>& V, int start, int end)
{
    if (start < end)
    {
        int pivot_index = pivoty(V, start, end);
        quickSorty(V, start, pivot_index - 1);
        quickSorty(V, pivot_index + 1, end);
    }
}

float distance(pair<pair<int, int>, pair<int, int>> points) {
    int x1 = points.first.first;
    int y1 = points.first.second;
    int x2 = points.second.first;
    int y2 = points.second.second;

    float distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    return distancia;
}
pair<pair<int, int>, pair<int, int>> closestP(vector<pair<int, int>>& N)
{
    quickSortx(N, 0, N.size() - 1);
    if (N.size() == 2) {
        return { N[0],N[1] };
    }
    else if (N.size() == 3)
    {
        float distancia1 = distance({ N[0],N[1] });
        float distancia2 = distance({ N[1],N[2] });
        float distancia3 = distance({ N[2],N[0] });

        float minDistancia = min(distancia1, distancia2);
        minDistancia = min(minDistancia, distancia3);

        if (minDistancia == distancia1)
        {
            return make_pair(N[0], N[1]);
        }
        else if (minDistancia == distancia2)
        {
            return make_pair(N[0], N[2]);
        }
        else
        {
            return make_pair(N[1], N[2]);
        }
    }
    int midIndex = N.size() / 2;
    float L = (N[midIndex].first + N[midIndex - 1].first) / 2;

    vector<pair<int, int>> leftN(N.begin(), N.begin() + midIndex);
    vector<pair<int, int>> rightN(N.begin() + midIndex, N.end());
    pair<pair<int, int>, pair<int, int>> NL = closestP(leftN);
    pair<pair<int, int>, pair<int, int>> NR = closestP(rightN);
    pair<pair<int, int>, pair<int, int>> minN;
    if (min(distance(NL), distance(NR)) == distance(NL))
    {
        minN = NL;
    }
    else
    {
        minN = NR;
    }
    float distancia = distance(minN);

    vector<pair<int, int>> NewN;
    for (int i = 0; i < N.size(); i++)
    {
        if (N[i].first > L - distancia && N[i].first < L + distancia)
        {
            NewN.push_back(N[i]);
        }
    }
    quickSorty(NewN, 0, NewN.size() - 1);

    for (int i = 0; i < NewN.size(); i++)
    {
        for (int j = i + 1; j < NewN.size(); j++)
        {
            if (j == i + 11)
            {
                break;
            }
            if (distance({ NewN[i], NewN[j] }) < distance(minN))
            {
                minN = { NewN[i], NewN[j] };
            }
        }
    }
    return minN;
}
int main() {
    vector<pair<int, int>> N = { {1,3},{5,3},{7,7},{8,6},{10,9},{6,1},{2,6},{3,3},{4,7},{9,6} };
    pair<pair<int, int>, pair<int, int>> solution = closestP(N);
    cout << solution.first.first << ' ';
    cout << solution.first.second << endl;
    cout << solution.second.first << ' ';
    cout << solution.second.second;
}