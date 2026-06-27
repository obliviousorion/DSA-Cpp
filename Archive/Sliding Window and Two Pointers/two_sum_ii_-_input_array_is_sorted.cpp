#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: Two Sum II - Input Array Is Sorted
 * 
 * Description:
 * Given a sorted array of integers arr and a target integer target, determine if there exists 
 * any pair of elements (arr[i], arr[j]) where i != j such that their sum is exactly equal to target.
 * Your function should return true if such a pair exists, and false otherwise.
 * 
 * Constraints:
 * The array is guaranteed to be strictly sorted in ascending order.
 * 
 * Approach:
 * Two-pointer technique. Initialize low pointer at the start and high pointer at the end of the array.
 * Compute the sum of elements at both pointers.
 * - If the sum is equal to the target, return true.
 * - If the sum is less than the target, increment the low pointer to try and increase the sum.
 * - If the sum is greater than the target, decrement the high pointer to try and decrease the sum.
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(1) auxiliary
 */

class Solution {
public:
    bool twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        int low_ptr = 0;
        int high_ptr = n - 1;

        while (low_ptr < high_ptr) {
            int sum = arr[low_ptr] + arr[high_ptr];

            if (sum == target) {
                return true;
            } else if (sum < target) {
                low_ptr++;
            } else {
                high_ptr--;
            }
        }
        
        return false;
    }
};
