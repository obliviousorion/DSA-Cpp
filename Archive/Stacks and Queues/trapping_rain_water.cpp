#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: Trapping Rain Water
 * Description: Given n non-negative integers representing an elevation map where the width of each bar is 1,
 *              compute how much water it can trap after raining.
 * 
 * Approach:
 *   - Method 1 (Prefix/Suffix Max Precomputation):
 *     Find the maximum height bar to the left and right of every index. The water trapped at any index is
 *     min(left_max, right_max) - height[i]. Time Complexity: O(N), Space Complexity: O(N) for prefix/suffix max arrays.
 * 
 *   - Method 2 (Two Pointers - Optimal):
 *     Keep left and right pointers at both ends. Maintain left_max and right_max. If height[left] <= height[right],
 *     the amount of water trapped depends on left_max, so we update left_max and add difference to total, then increment left.
 *     Otherwise, the water depends on right_max, so we update right_max, add difference to total, and decrement right.
 *     Time Complexity: O(N), Space Complexity: O(1).
 */

class Solution {
public:
    int trap2(vector<int>& height) {
        int n = height.size();
        int leftmax = 0;
        int rightmax = 0;
        int l = 0;
        int r = n - 1;
        int total = 0;
        while (l < r) {
            leftmax = max(leftmax, height[l]);
            rightmax = max(rightmax, height[r]);

            if (height[l] <= height[r]) {
                if (leftmax > height[l]){
                    total += leftmax - height[l];
                } else {
                    leftmax = height[l];
                }
                l++;
            } else {
                if (rightmax > height[r]) {
                    total += rightmax - height[r];
                } else {
                    rightmax = height[r];
                }
                r--;
            }
        }
        return total;
    }

    // prefix and suffix max precomputation approach
    vector<int> prefixMax(const vector<int> &arr, int n) {
        if (n == 0)
            return {};
        vector<int> prefixMax(n);
        prefixMax[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], arr[i]);
        }
        return prefixMax;
    }

    vector<int> suffixMax(const vector<int> &arr, int n) {
        if (n == 0)
            return {};
        vector<int> suffixMax(n);
        suffixMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], arr[i]);
        }
        return suffixMax;
    }

    int trap(vector<int> &height) {
        int n = height.size();
        if (n == 0)
            return 0;
        vector<int> rightmax = suffixMax(height, n);
        vector<int> leftmax = prefixMax(height, n);
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (height[i] < leftmax[i] && height[i] < rightmax[i]) {
                total += (min(rightmax[i], leftmax[i]) - height[i]);
            }
        }
        return total;
    }
};
