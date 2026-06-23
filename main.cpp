#include <bits/stdc++.h>
using namespace std;

// Section : Stacks and Queues
// Problem : Sum of Subarray Minimums

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // Write solution logic here
        return 0;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.sumSubarrayMins(arr) << "\n";
    }

    return 0;
}