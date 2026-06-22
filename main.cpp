#include <bits/stdc++.h>
using namespace std;

// Section : Stacks and Queues
// Problem : Next Greater Element II

class Solution {
public:
    // Function to find the next greater element for each element in a circular array.
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Write solution logic here
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            vector<int> nums(n);
            for (int i = 0; i < n; i++) {
                cin >> nums[i];
            }
            Solution ob;
            vector<int> res = ob.nextGreaterElements(nums);
            for (int i = 0; i < n; i++) {
                cout << res[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}