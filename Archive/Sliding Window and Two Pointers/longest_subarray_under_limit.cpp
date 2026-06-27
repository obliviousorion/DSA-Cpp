/*
 * Problem : Longest Subarray Under Limit
 * Time Complexity : O(N)
 * Space Complexity : O(1)
 *
 * Description:
 * Given an array of positive integers nums and a target integer target, 
 * find the length of the longest contiguous subarray whose sum is less 
 * than or equal to target. If no such subarray exists, return 0.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubarrayUnderLimit(vector<int>& nums, int target) {
        int l_ptr = 0;
        int n = nums.size();
        int max_length = 0;
        int current_sum = 0;

        for (int r_ptr = 0; r_ptr < n; r_ptr++) {
            // increase the rptr and update the sum
            current_sum += nums[r_ptr];

            // move the l_ptr if sum exceeds target
            while (current_sum > target && l_ptr <= r_ptr) {
                current_sum -= nums[l_ptr++];
            }

            max_length = max(max_length, r_ptr - l_ptr + 1);
        }
        return max_length;
    }
};
