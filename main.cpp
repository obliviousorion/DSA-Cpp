#include <bits/stdc++.h>
using namespace std;

// Section : Sliding Window and Two Pointers
// Problem : Two Sum II - Input Array Is Sorted

class Solution {
public:
    bool twoSum(vector<int>& arr, int target) {
        // Write solution logic here
        return false;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    if (!(cin >> n >> target)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution solver;
    if (solver.twoSum(arr, target)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}