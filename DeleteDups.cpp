#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para fusionar dos mitades ordenadas y eliminar duplicados
vector<int> combinar(vector<int> a, vector<int> b)
{
    vector<int> c;
    int i = 0;
    int j = 0;
    while (a.size() > i && b.size() > j)
    {
        if (a[i] < b[j])
        {
            c.push_back(a[i]);
            i++;
        }
        else if (a[i] > b[j])
        {
            c.push_back(b[j]);
            j++;
        }
        else if (a[i]==b[j])
        {
            c.push_back(a[i]);
            i++;
            j++;
        }
    }
    while (a.size() > i)
    {
        c.push_back(a[i]);
        i++;
    }
    while (b.size() > j)
    {
        c.push_back(b[j]);
        j++;
    }
    return c;
}

vector<int> mergeSort(vector<int> V)
{
    int size = V.size();
    if (size == 1)
    {
        return V;
    }
    int mid = size / 2;
    vector<int> izq(V.begin(), V.begin() + mid);
    vector<int> der(V.begin() + mid, V.end());
    izq = mergeSort(izq);
    der = mergeSort(der);
    return combinar(izq, der);
}

int main() {
    vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    // Ordena el vector antes de eliminar duplicados
    sort(numbers.begin(), numbers.end());

    vector<int> noDups = mergeSort(numbers);

    cout << "Vector sin duplicados: ";
    for (int num : noDups) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}