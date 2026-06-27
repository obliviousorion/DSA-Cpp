#include <bits/stdc++.h>
using namespace std;

// Section : Sliding Window and Two Pointers
// Problem : Max Consecutive Ones with Flipping

/*
Problem Statement:
Given a binary array nums (containing only 0s and 1s) and an integer k,
return the maximum number of consecutive 1s in the array if you can
flip at most k 0s to 1s.

Constraints:
nums[i] is either 0 or 1.

Time Complexity Goal: O(N)
Auxiliary Space Complexity Goal: O(1)

Example:
Input: nums = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0], k = 2
Output: 6
Explanation: nums[3] and nums[4] can be flipped from 0 to 1.
The longest subarray with consecutive 1s is [1, 1, 1, 1, 1, 1] from
index 5 to 10.
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

int main() {
  // Fast I/O
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  if (!(cin >> n >> k))
    return 0;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  Solution solver;
  cout << solver.longestOnes(nums, k) << "\n";

  return 0;
}