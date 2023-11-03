#include <iostream>
#include <vector>
using namespace std;
vector<int> EfficientGas(vector<int> gas, int capacity)
{
    vector<int> solution = { 0 };
    int candidate;
    int currentDistance;
    int j = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        if (gas[i]-solution[j] < capacity)
        {
            candidate = gas[i];
        }
        else
        {
            solution.push_back(candidate);
            i--;
            j++;
        }
    }
    solution.push_back(gas[gas.size() - 1]);
    return solution;
}
int main()
{
    vector<int> gas = { 6,15,26,50,61,62  };
    vector<int> solution = EfficientGas(gas, 30);
    for (int i = 0; i < solution.size(); i++)
    {
        cout << solution[i] << ' ';
    }
}
