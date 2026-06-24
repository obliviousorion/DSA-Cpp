#include <bits/stdc++.h>
using namespace std;

// Section : Stacks and Queues
// Problem : Sum of Subarray Ranges

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // Write solution logic here
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        Solution ob;
        cout << ob.subArrayRanges(nums) << "\n";
    }

    return 0;
}