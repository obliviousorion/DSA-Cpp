#include <bits/stdc++.h>
using namespace std;

// Section : Sliding Window and Two Pointers
// Problem : Binary Subarrays With Sum

/*
Problem Statement:
Given a binary array nums and an integer goal, return the number of non-empty subarrays 
with a sum equal to goal.

Constraints:
1 <= nums.length <= 3 * 10^4
nums[i] is either 0 or 1.
0 <= goal <= nums.length

Time Complexity Goal: O(N)
Auxiliary Space Complexity Goal: O(1)

Example:
Input: nums = [1, 0, 1, 0, 1], goal = 2
Output: 4
Explanation: The 4 subarrays are:
- [1, 0, 1] (indices 0 to 2)
- [1, 0, 1, 0] (indices 0 to 3)
- [0, 1, 0, 1] (indices 1 to 4)
- [1, 0, 1] (indices 2 to 4)
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Write solution logic here
        return 0;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, goal;
    if (!(cin >> n >> goal)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solver;
    cout << solver.numSubarraysWithSum(nums, goal) << "\n";

    return 0;
}