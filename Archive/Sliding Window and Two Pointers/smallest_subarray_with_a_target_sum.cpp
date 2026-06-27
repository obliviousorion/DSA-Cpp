/*
 * Problem : Smallest Subarray with a Target Sum
 * Time Complexity : O(N)
 * Space Complexity : O(1)
 *
 * Description:
 * Given an array of positive integers nums and a target integer target, 
 * find the minimal length of a contiguous subarray of which the sum is 
 * greater than or equal to target. If there is no such subarray, return 0 instead.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l_ptr = 0;
        int n = nums.size();
        int sum = 0;
        int min_length = n + 1;

        for (int r_ptr = 0 ; r_ptr < n; r_ptr++) {
            sum += nums[r_ptr];

            while (sum >= target) {
                min_length = min(min_length, r_ptr - l_ptr + 1);    
                sum -= nums[l_ptr++]; 
            }
        }
        return (min_length == n+1) ? 0 : min_length;
    }
};
