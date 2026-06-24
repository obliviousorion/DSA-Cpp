/*
 * Problem: Largest Rectangle in Histogram
 * Section: Stacks and Queues
 *
 * Description:
 * Given an array of integers heights representing the histogram's bar height where the
 * width of each bar is 1, return the area of the largest rectangle in the histogram.
 *
 * ==========================================
 * DETAILED BREAKDOWN OF APPROACHES
 * ==========================================
 *
 * Approach 1: Two-Pass Monotonic Stack (Implemented via largestRectangleArea)
 * --------------------------------------------------------------------------
 * - Intuition:
 *   For each bar heights[i], we want to find the largest rectangle that uses heights[i] as the minimum height.
 *   This is bounded by:
 *     1. Previous Smaller Element (PSE): The first bar to the left that is shorter than heights[i].
 *     2. Next Smaller Element (NSE): The first bar to the right that is shorter than heights[i].
 *   The width of this rectangle is (NSE - PSE - 1).
 * 
 * - Implementation Details:
 *   - `findNSE` uses a monotonic stack to find the index of the next smaller element. If none exists, it defaults to `n`.
 *   - `findPSE` uses a monotonic stack to find the index of the previous smaller element. If none exists, it defaults to `-1`.
 *   - The main loop computes the area for each bar as `heights[i] * (nse[i] - pse[i] - 1)` and tracks the maximum.
 * 
 * - Complexity:
 *   - Time Complexity: O(N) (Three linear passes: NSE, PSE, and area calculation).
 *   - Space Complexity: O(N) (Auxiliary vectors for NSE and PSE, and stack).
 *
 * Approach 2: Single-Pass Monotonic Stack (Implemented via largestRectangleArea2)
 * -----------------------------------------------------------------------------
 * - Intuition:
 *   Instead of computing NSE and PSE in separate passes, we can process them in a single pass.
 *   When a bar heights[i] is smaller than the bar at the top of the stack (heights[st.top()]),
 *   it serves as the NSE for the stack top. The element below the stack top serves as the PSE.
 * 
 * - Implementation Notes / Bugs in User's Code:
 *   - Loop Range: The loop terminates at `i < n`. To trigger processing of remaining elements in the stack,
 *     the loop should run up to `i <= n` so that a sentinel height of `0` at index `n` is processed.
 *   - Width Expression: `int width = st.empty() ? i : (i - st.top() - i)` simplifies to `-st.top()`.
 *     It should be `(i - st.top() - 1)` to calculate the correct width.
 * 
 * - Complexity:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */

#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

class Solution {
private:
    // Finds index of the Next Smaller Element (NSE) for each bar
    vector<int> findNSE(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> nse(n);

        for (int i = n - 1; i >= 0; i--) {
            // Maintain monotonic increasing order in the stack
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            if (st.empty()) {
                // If no smaller element exists on the right, the boundary is the end of the array (n)
                nse[i] = n;
            } else {
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }

    // Finds index of the Previous Smaller Element (PSE) for each bar
    vector<int> findPSE(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> pse(n);

        for (int i = 0; i < n; i++) {
            // Maintain monotonic increasing order in the stack
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                // If no smaller element exists on the left, the boundary is -1
                pse[i] = -1;
            } else {
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse; 
    }

public:
// Approach 2: Single-Pass Monotonic Stack (Corrected)
    int largestRectangleArea2(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;

        // FIXED: Loop condition changed to i <= n to allow the sentinel value (0) to process at index n
        for(int i = 0; i <= n; i++) {
            // Sentinel value of 0 handles flushing the remaining stack elements at the end
            int current = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] >= current) {
                int height = heights[st.top()];
                st.pop();

                // FIXED: Used the exact width formula you called out in the notes
                int width = st.empty() ? i : (i - st.top() - 1);
                
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    // Approach 1: Two-Pass Monotonic Stack (Main Solution)
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = findPSE(heights);
        vector<int> nse = findNSE(heights);
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            // Width is the distance between Next Smaller and Previous Smaller boundaries minus 1
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};
