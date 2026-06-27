#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>
using namespace std;

/*
 * Problem: Square Sorter
 * 
 * Description:
 * Given an integer array nums sorted in non-decreasing order, return an array of 
 * the squares of each number sorted in non-decreasing order.
 * 
 * Constraints:
 * 1 <= nums.size() <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in non-decreasing order.
 * 
 * Approach:
 * Two-pointer technique. Since the array is sorted, the squares of the numbers at both 
 * ends (very small negative numbers and large positive numbers) will yield the largest squares.
 * We initialize one pointer at the start and one at the end of the array, compare the absolute
 * values, compute their squares, and populate a new result array from back to front.
 * 
 * Time Complexity: O(N) where N is the length of the array.
 * Space Complexity: O(1) auxiliary space (excluding the output array).
 */

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size();
    int low = 0, high = n - 1;
    vector<int> result(n);

    // Fill from the back to the front
    for (int i = n - 1; i >= 0; i--) {
      if (abs(nums[low]) > abs(nums[high])) {
        result[i] = nums[low] * nums[low];
        low++;
      } else {
        result[i] = nums[high] * nums[high];
        high--;
      }
    }
    return result;
  }
};
