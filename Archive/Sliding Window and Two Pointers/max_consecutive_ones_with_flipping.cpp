#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * Problem: Max Consecutive Ones with Flipping
 * 
 * Description:
 * Given a binary array nums (containing only 0s and 1s) and an integer k,
 * return the maximum number of consecutive 1s in the array if you can
 * flip at most k 0s to 1s.
 * 
 * Constraints:
 * nums[i] is either 0 or 1.
 * 
 * Approach:
 * Sliding window technique (variable length). Maintain a window [l_ptr, r_ptr]
 * that contains at most k zeros. Expand the window by moving r_ptr. If the count
 * of zeros in the window exceeds k, shrink the window from the left by moving l_ptr
 * until the zero count is back to at most k. Track the maximum window size.
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(1) auxiliary space
 */

class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int n = nums.size();
    int l_ptr = 0;
    int zero_count = 0;
    int max_len = 0;

    // Expand the window with r_ptr
    for (int r_ptr = 0; r_ptr < n; r_ptr++) {
      if (nums[r_ptr] == 0) {
        zero_count++;
      }

      // Shrink the window from the left if we exceed k zeroes
      while (zero_count > k) {
        if (nums[l_ptr] == 0) {
          zero_count--;
        }
        l_ptr++;
      }

      // The window is now valid (contains <= k zeroes), record its length
      max_len = max(max_len, r_ptr - l_ptr + 1);
    }

    return max_len;
  }
};
