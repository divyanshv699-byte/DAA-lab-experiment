#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArray(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArray(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < leftArray.size() && j < rightArray.size()) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k++] = leftArray[i++];
        } else {
            arr[k++] = rightArray[j++];
        }
    }

    while (i < leftArray.size()) {
        arr[k++] = leftArray[i++];
    }

    while (j < rightArray.size()) {
        arr[k++] = rightArray[j++];
    }
}

// Recursive Merge Sort

void recursiveMergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    recursiveMergeSort(arr, left, mid);
    recursiveMergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

// Iterative Merge Sort

void iterativeMergeSort(vector<int>& arr) {
    int n = arr.size();

    for (int size = 1; size < n; size *= 2) {

        for (int left = 0; left < n - 1; left += 2 * size) {

            int mid = min(left + size - 1, n - 1);
            int right = min(left + 2 * size - 1, n - 1);

            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    vector<int> recursiveArray = arr;
    vector<int> iterativeArray = arr;

    recursiveMergeSort(recursiveArray, 0, recursiveArray.size() - 1);

    cout << "Recursive Merge Sort: ";
    for (int x : recursiveArray) {
        cout << x << " ";
    }

    cout << endl;

    iterativeMergeSort(iterativeArray);

    cout << "Iterative Merge Sort: ";
    for (int x : iterativeArray) {
        cout << x << " ";
    }

    return 0;
}