#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: Next Greater Element II
 * Description: Given a circular integer array nums, return the next greater number for every element in nums.
 *              The next greater number of a number x is the first greater number to its traversing-order next
 *              in the array, which means we could search circularly to find its next greater number.
 *              If it doesn't exist, return -1 for this number.
 * 
 * =========================================================================================================
 * DETAILED BREAKDOWN OF APPROACHES
 * =========================================================================================================
 * 
 * ---------------------------------------------------------------------------------------------------------
 * Method 1: Doubled Array Approach
 * ---------------------------------------------------------------------------------------------------------
 * 1. Concept:
 *    - To handle the circular nature of the array, we can construct a virtual/physical doubled array.
 *      For an input array `nums` of size N, we construct `superarr` of size 2*N where:
 *        `superarr[i] = nums[i % N]` for 0 <= i < 2*N.
 *    - This simulates the circular traversal because any element at index i can scan forward up to N - 1
 *      more elements, which are seamlessly represented by the second half of `superarr`.
 * 
 * 2. Monotonic Stack Algorithm:
 *    - We traverse `superarr` from right to left (index 2*N - 1 down to 0) maintaining a monotonic stack.
 *    - The stack stores elements in decreasing order from bottom to top (i.e. top is the smallest).
 *    - For each element `superarr[i]`:
 *      a. Pop elements from the stack while they are smaller than or equal to `superarr[i]`. This is because
 *         a smaller element to the right cannot be the next greater element for the current or any elements
 *         to the left (the current element is larger and closer, making those smaller elements obsolete).
 *      b. If the stack is empty, it means there is no greater element to the right, so we assign -1.
 *      c. Otherwise, the top of the stack is the first greater element to the right.
 *      d. Push the current element `superarr[i]` onto the stack to act as potential next-greater history.
 * 
 * 3. Result Extraction:
 *    - The next greater elements for the original array are stored in the first N elements of the `nge` vector.
 *    - Copy `nge[0]` to `nge[N-1]` into our final answer vector `ans`.
 * 
 * ---------------------------------------------------------------------------------------------------------
 * Method 2: Space-Optimized Cyclic Simulation (Most Optimal)
 * ---------------------------------------------------------------------------------------------------------
 * 1. Concept:
 *    - Instead of allocating extra O(N) space to physically double the array, we simulate the same behavior
 *      by running our loop N * 2 times (index i from 2*N - 1 down to 0) and accessing elements with index `i % N`.
 * 
 * 2. Two-Pass Simulation Logic:
 *    - First Pass (i from 2*N - 1 down to N):
 *      - We process these elements solely to populate the stack with the correct circular history.
 *      - We do NOT write answers to our output `nge` array since these represent the "virtual" second copy.
 *      - We push elements to the stack after popping smaller ones.
 *    - Second Pass (i from N - 1 down to 0):
 *      - By the time we enter the second pass, the stack already contains the elements from the "right side"
 *        of our circular boundary (which is actually the array itself).
 *      - We pop smaller/equal elements, record the top of the stack as the answer for index `i`, and push `arr[i]`.
 * 
 * 3. Complexity Comparison:
 *    - Method 1: Time Complexity O(N), Auxiliary Space O(N) (for the physical 2*N doubled array).
 *    - Method 2: Time Complexity O(N) (2*N iterations), Auxiliary Space O(N) (for the stack only, no duplicated array).
 */

class Solution {
public:
  // Function to find the next greater element for each
  // element in a circular array.
  vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();

    // 1. core idea: Create and populate the doubled array
    // We must initialize the size (2 * n) so we can use [] indexing safely
    vector<int> superarr(2 * n);
    for (int i = 0; i < 2 * n; i++) {
      superarr[i] = nums[i % n];
    }

    // 2. core idea: Run the monotonic stack
    // The array size is now 2*n, so we need to size 'nge' to 2*n
    // and run the loop from the very end of superarr (2*n - 1) down to 0
    vector<int> nge(2 * n);
    stack<int> st;
    for (int i = (2 * n) - 1; i >= 0; i--) {
      // Maintain monotonic stack order (remove smaller/equal elements)
      while (!st.empty() && st.top() <= superarr[i]) {
        st.pop();
      }

      if (st.empty()) {
        nge[i] = -1;
      } else {
        nge[i] = st.top();
      }

      st.push(superarr[i]);
    }

    // 3. core idea: Extract the final answers
    // The answers for our original elements are now sitting in the
    // first 'n' slots of our processed 'nge' vector.
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i] = nge[i];
    }

    return ans;
  }

  // Method 2: Space-Optimized Cyclic Simulation
  // We simulate a pass over a doubled array of size 2*N using modulo operations.
  vector<int> nextGreaterElements2(vector<int> arr) {
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--) {
      // Step 1: Clear out elements that are smaller or equal to the current element.
      // This is because a smaller element to the right can never be the next greater
      // element for the current element or any element to its left.
      while (!st.empty() && st.top() <= arr[i % n]) {
        st.pop();
      }

      // Step 2: Only record the answer during the second pass (real indices where i < N).
      // During the first pass (N <= i < 2*N), we only populate the stack to build history.
      if (i < n) {
        if (st.empty()) {
          nge[i] = -1; // No greater element found in the circular traversal
        } else {
          nge[i] = st.top(); // The nearest greater element in circular search
        }
      }

      // Step 3: Always maintain history by pushing the current element
      st.push(arr[i % n]);
    }
    return nge;
  }
};
