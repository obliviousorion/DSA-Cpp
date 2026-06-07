#include <bits/stdc++.h>
using namespace std;

/*
 * Problem : Find Nth root of M
 * Description : Given two integers N and M, find the integer X such that X^N = M. If no such integer exists, return -1.
 * Approach : Binary Search over the search space [1, M/N] using pow() function to verify.
 * Time Complexity : O(log(M/N) * log(N))
 * Space Complexity : O(1)
 */

class Solution {
public:
    int findNthrootofM (int n, int m) {
        int low = 1;
        int high = m / n;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Using standard pow() function to check matching value
            if (pow(mid, n) == m) {
                return mid;
            } else if (pow(mid, n) < m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
