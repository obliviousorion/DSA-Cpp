/*
 * Problem: Find Square Root of N
 * Description: Given a non-negative integer N, compute and return its square root. 
 *              If N is not a perfect square, return the floor value of the square root.
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 * 
 * Approach Hint: Perform binary search on the range [0, N]. In each step, compare mid * mid with N 
 *                and adjust the search boundaries. Use long long to avoid overflow when calculating mid * mid.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSqrtOfN(int n) {
        int low = 0;
        int high = n;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Use long long to guard against integer overflow during multiplication
            long long square = (long long)mid * mid;
            
            if (square == n) {
                return mid; // Exact square root found
            } else if (square < n) {
                ans = mid; // Track the floor of square root
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
