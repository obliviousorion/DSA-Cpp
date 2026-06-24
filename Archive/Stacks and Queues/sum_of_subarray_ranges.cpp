/*
 * Problem: Sum of Subarray Ranges [INCOMPLETE]
 * Section: Stacks and Queues
 * Status: Incomplete (Optimal approach using Monotonic Stack is not yet implemented)
 *
 * Description:
 * Given an integer array nums, return the sum of all subarray ranges of nums.
 * The range of a subarray is the difference between the largest and smallest element in that subarray.
 *
 * ==========================================
 * DETAILED BREAKDOWN OF APPROACHES
 * ==========================================
 *
 * Approach 1: Brute Force Method (Implemented)
 * -------------------------------------------
 * - Intuition: Generate every subarray and compute the difference between its maximum and minimum elements.
 * - Implementation:
 *   - Outer loop iterates through start index `i` from 0 to n-1.
 *   - Inner loop expands the subarray to end index `j` from i+1 to n-1.
 *   - Updates the running maximum `maxx` and running minimum `minn` dynamically for each subarray `nums[i...j]`.
 *   - Add `(maxx - minn)` to `sum` at each iteration.
 * - Time Complexity: O(N^2)
 * - Space Complexity: O(1)
 *
 * Approach 2: Monotonic Stack (Optimal Method - Not Implemented)
 * -------------------------------------------------------------
 * - Intuition:
 *   Rewrite sum of ranges as: sum(subarray_max) - sum(subarray_min).
 *   Compute the contribution of each element nums[i] as the maximum and minimum in subarrays using a Monotonic Stack.
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    // Left unimplemented in main.cpp
    long long subArrayRanges(vector<int>& nums) {
        // TODO: Implement O(N) optimal approach using Monotonic Stack
        return -1;
    }

    // Approach 1: Brute Force Method
    long long subArrayRanges_bruteforce(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int maxx = nums[i], minn = nums[i];
            for (int j = i + 1; j < n; j++) {
                maxx = max(maxx, nums[j]);
                minn = min(minn, nums[j]);

                sum += (maxx - minn);
            }
        }
        return sum;
    }
};
