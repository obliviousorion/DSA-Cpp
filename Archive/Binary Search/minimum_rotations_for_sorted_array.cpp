/*
Problem: Minimum Rotations for Sorted Array
Section: Binary Search

Time Complexity: $O(\log n)$
Space Complexity: $O(1)$

Find the index of the minimum element in a rotated sorted array. The
index of the minimum element equals the number of rotations applied to
the original sorted array. Returns -1 for empty input.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns index of minimum element (rotation count), or -1 if empty.
    int minRotations(int arr[], int n) {
        if (n == 0) return -1;

        int low = 0, high = n - 1;

        while (low <= high) {
            // If current segment is already sorted, lowest index is minimum.
            if (arr[low] <= arr[high]) return low;

            int mid = low + (high - low) / 2;

            // If mid > high, minimum lies to the right of mid.
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                // Otherwise, minimum is at mid or to the left.
                high = mid - 1;
            }
        }

        return -1; // defensive; valid rotated arrays will return earlier
    }
};
