#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (nums[j] < pivot) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[right]);
    return i;
}
int findKthElement(vector<int>& nums, int left, int right, int k) {
    if (left == right) {
        return nums[left];
    }

    int pivotIndex = partition(nums, left, right);
    if (k == pivotIndex) {
        return nums[k];
    }
    else if (k < pivotIndex) {
        return findKthElement(nums, left, pivotIndex - 1, k);
    }
    else {
        return findKthElement(nums, pivotIndex + 1, right, k);
    }
}
double findMedian(vector<int>& nums) {
    int n = nums.size();
    if (n % 2 == 1) {
        return findKthElement(nums, 0, n - 1, n / 2);
    }
    else {
        int left = findKthElement(nums, 0, n - 1, n / 2 - 1);
        int right = findKthElement(nums, 0, n - 1, n / 2);
        return (left + right) / 2.0;
    }
}

int main() {
    vector<int> numbers = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };

    double median = findMedian(numbers);

    cout << "La mediana es: " << median << endl;

    return 0;
}