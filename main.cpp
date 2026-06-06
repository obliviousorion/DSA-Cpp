#include <bits/stdc++.h>
using namespace std;

// Section : Binary Search
// Problem : Minimum Rotations for Sorted Array.

class Solution{
public:
    int minRotations(int arr[], int n){
        if (n == 0) {
            return -1;
        }

        int low = 0;
        int high = n - 1;
        int ansIndex = -1;

        while (low <= high) {
            if (arr[low] <= arr[high]) {
                ansIndex = low;
                break;
            }

            int mid = low + (high - low) / 2;

            if (arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                ansIndex = mid;
                high = mid - 1;
            }
        }

        return ansIndex;
    }
};


int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution sol;
    cout << sol.minRotations(arr, n);
    return 0;
}