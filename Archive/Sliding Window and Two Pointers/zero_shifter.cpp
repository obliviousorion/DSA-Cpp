/*
 * Problem : Zero Shifter
 * Time Complexity : O(N)
 * Space Complexity : O(1)
 *
 * Description:
 * Given an integer array nums, move all 0's to the end of it while maintaining
 * the relative order of the non-zero elements. You must do this in-place.
 */

#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
  // Approach 1: Write and Read pointers
  void moveZeroes(vector<int> &nums) {
    int n = nums.size();
    int wrt_ptr = 0;
    int rd_ptr = 0;
    while (rd_ptr < n) {
      if (nums[rd_ptr] == 0) {
        rd_ptr++;
      } else {
        nums[wrt_ptr++] = nums[rd_ptr++];
      }
    }
    // Fill the rest with zeros
    while (wrt_ptr < n) {
      nums[wrt_ptr++] = 0;
    }
  }

  // Approach 2: Swapping non-zero elements
  void moveZeroes2(vector<int> &nums) {
    int n = nums.size();
    int wrt_ptr = 0;

    for (int rd_ptr = 0; rd_ptr < n; rd_ptr++) {
      if (nums[rd_ptr] != 0) {
        swap(nums[wrt_ptr++], nums[rd_ptr]);
      }
    }
  }
};
