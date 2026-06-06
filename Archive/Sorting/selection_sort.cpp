/*
Problem: Selection Sort
Section: Sorting

Time Complexity: $O(n^2)$
Space Complexity: $O(1)$

In-place selection sort implementation. Repeatedly selects the
minimum element from the unsorted suffix and swaps it into place.
*/

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = (int)arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int mini = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[mini]) mini = j;
        }
        if (mini != i) swap(arr[mini], arr[i]);
    }
}
