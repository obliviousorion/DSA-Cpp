/*
 * Problem : Container With Most Water
 * Time Complexity : O(N)
 * Space Complexity : O(1)
 *
 * Description:
 * You are given an integer array height of length n. Find two lines that together 
 * with the x-axis form a container, such that the container contains the most water. 
 * Return the maximum amount of water a container can store.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low = 0, high = n - 1;
        int max_area = 0;

        while (low < high) {
            int area = (high - low) * min(height[low], height[high]);
            max_area = max(max_area, area);

            // Move the pointer that is limiting the height
            if (height[low] <= height[high]) {
                low++;
            } else {
                high--;
            }
        } 
        return max_area;
    }
};
