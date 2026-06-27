/*
 * Problem: Binary Subarrays With Sum
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 * Description:
 * Given a binary array 'nums' and an integer 'goal', return the number of non-empty
 * subarrays with a sum equal to 'goal'.
 *
 * Approach:
 * The number of subarrays with sum exactly equal to 'goal' can be calculated as:
 *   count(exactly goal) = count(at most goal) - count(at most goal - 1)
 * Using a sliding window / two pointers approach, we find the number of subarrays
 * with sum at most 'goal' in O(N) time.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int atmost(vector<int> &nums, int goal) {
        // Guard clause for when goal - 1 becomes negative
        if (goal < 0) return 0; 

        int count = 0;
        int n = nums.size();
        int l_ptr = 0;
        int sum = 0;
        
        for (int r_ptr = 0; r_ptr < n; r_ptr++) { 
            sum += nums[r_ptr];

            // Shrink window if sum exceeds goal
            while (sum > goal) {
                sum -= nums[l_ptr++];
            }
            
            // All subarrays ending at r_ptr with length up to (r_ptr - l_ptr + 1)
            // have sum <= goal.
            count += r_ptr - l_ptr + 1;
        }
        return count;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};
