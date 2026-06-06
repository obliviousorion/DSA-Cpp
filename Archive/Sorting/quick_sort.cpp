/*
Problem: Quick Sort
Section: Sorting

Time Complexity: Average $O(n\log n)$, Worst $O(n^2)$
Space Complexity: $O(\log n)$ (recursion stack)

Lomuto-style partition based quicksort. Average performance is good;
worst case occurs on already-sorted inputs unless pivot selection is
randomized.
*/

#include <bits/stdc++.h>
using namespace std;

int partitionLomuto(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int p = partitionLomuto(arr, low, high);
    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
}
