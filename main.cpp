#include <bits/stdc++.h>
using namespace std;

// Section : Sliding Window and Two Pointers
// Problem : Square Sorter

/*
Problem Statement:
Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order.

Constraints:
1 <= nums.size() <= 10^4
-10^4 <= nums[i] <= 10^4
nums is sorted in non-decreasing order.

Time Complexity Goal: O(N)
Auxiliary Space Complexity Goal: O(1) (excluding the returned output array)

Example:
Input: nums = [-4, -1, 0, 3, 10]
Output: [0, 1, 9, 16, 100]
Explanation: After squaring, the array becomes [16, 1, 0, 9, 100]. 
Sorted order is [0, 1, 9, 16, 100].
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Write solution logic here
        return {};
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solver;
    vector<int> ans = solver.sortedSquares(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}