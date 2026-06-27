/*
 * Problem : Max Sum of K-Elements
 * Time Complexity : O(N)
 * Space Complexity : O(1)
 *
 * Description:
 * Given an array of integers nums and an integer k, find the maximum sum of any contiguous subarray of size exactly k.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumKElements(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return 0;

        int current_sum = 0;
        // Sum the first window of size k
        for (int i = 0; i < k; i++) {
           current_sum += nums[i];
        }
        int max_sum = current_sum;
        
        // Slide the window: add the incoming element and subtract the outgoing element
        for (int i = k; i < n; i++) {
            current_sum = current_sum + nums[i] - nums[i - k];
            max_sum = max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};
