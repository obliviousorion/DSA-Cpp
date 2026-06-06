/*
Problem: Insertion Sort
Section: Sorting

Time Complexity: $O(n^2)$ (best $O(n)$ when nearly sorted)
Space Complexity: $O(1)$

Stable in-place insertion sort. Efficient for small or nearly-sorted
arrays.
*/

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = (int)arr.size();
    for (int i = 1; i < n; ++i) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            --j;
        }
    }
}
