#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int findKthSmallest(vector<int>& nums, int k) {
    int n = nums.size();
    if (k > 0 && k <= n) {
        vector<int> medians;
        for (int i = 0; i < n; i += 5) {
            vector<int> subvector(nums.begin() + i, nums.begin() + min(i + 5, n));
            sort(subvector.begin(), subvector.end());
            medians.push_back(subvector[subvector.size() / 2]);
        }

        int medianOfMedians;
        if (medians.size() == 1) {
            medianOfMedians = medians[0];
        }
        else {
            medianOfMedians = findKthSmallest(medians, medians.size() / 2);
        }


        vector<int> lower, upper;
        for (int i = 0; i < n; i++) {
            if (nums[i] < medianOfMedians)
                lower.push_back(nums[i]);
            else if (nums[i] > medianOfMedians)
                upper.push_back(nums[i]);
        }

        if (k <= lower.size())
            return findKthSmallest(lower, k);
        else if (k == lower.size() + 1)
            return medianOfMedians;
        else
            return findKthSmallest(upper, k - (lower.size() + 1));
    }
    return INT_MAX; // Valor predeterminado si k está fuera de rango
}

int main() {
    vector<int> numbers = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    int k = 5;

    int kthSmallest = findKthSmallest(numbers, k);

    cout << "El " << k << "-ésimo menor elemento es: " << kthSmallest << endl;

    return 0;
}
