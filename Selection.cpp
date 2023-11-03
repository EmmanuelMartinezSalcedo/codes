#include <iostream>
#include <vector>

using namespace std;
void intercambiar(vector<int>& A, int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int pivot(vector<int>& V, int start, int end)
{
    int i = start;
    int pivote = V[end];
    for (int j = start; j < end; j++)
    {
        if (V[j] <= pivote)
        {
            intercambiar(V, i, j);
            i++;
        }
    }
    intercambiar(V, i, end);
    return i;
}

int Selection(vector<int>& V, int s)
{
    int i = 0;
    int j = V.size() - 1;
    while (i < j)
    {
        int l = pivot(V, i, j);
        if (s < l)
        {
            j = l - 1;
        }
        else if (s > l)
        {
            i = l + 1;
        }
        else
        {
            return V[l];
        }
    }
    return V[i];
}