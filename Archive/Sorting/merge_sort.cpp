/*
Problem: Merge Sort
Section: Sorting

Time Complexity: $O(n\log n)$
Space Complexity: $O(n)$ (auxiliary array)

Stable divide-and-conquer merge sort. `merge` merges two sorted
subarrays into a temporary buffer then copies back.
*/

#include <bits/stdc++.h>
using namespace std;

void mergeRanges(vector<int>& arr, int leftStart, int mid, int rightEnd) {
    vector<int> tmp;
    tmp.reserve(rightEnd - leftStart + 1);

    int i = leftStart, j = mid + 1;
    while (i <= mid && j <= rightEnd) {
        if (arr[i] <= arr[j]) tmp.push_back(arr[i++]);
        else tmp.push_back(arr[j++]);
    }
    while (i <= mid) tmp.push_back(arr[i++]);
    while (j <= rightEnd) tmp.push_back(arr[j++]);

    for (int k = leftStart; k <= rightEnd; ++k) arr[k] = tmp[k - leftStart];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    mergeRanges(arr, left, mid, right);
}
