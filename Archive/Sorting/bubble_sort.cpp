/*
Problem: Bubble Sort
Section: Sorting

Time Complexity: $O(n^2)$ (best $O(n)$ with early exit)
Space Complexity: $O(1)$

Simple bubble sort with an early-exit optimization when the array
becomes already sorted.
*/

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = (int)arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // already sorted
    }
}
