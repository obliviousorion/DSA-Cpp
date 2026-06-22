#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: Next Greater Element II
 * Description: Given a circular integer array nums, return the next greater number for every element in nums.
 *              The next greater number of a number x is the first greater number to its traversing-order next
 *              in the array, which means we could search circularly to find its next greater number.
 *              If it doesn't exist, return -1 for this number.
 * 
 * Approach:
 *   - Method 1: Double the array length to 2 * N to handle the circular nature using a monotonic stack.
 *   - Method 2: Process the array from 2 * N - 1 down to 0, accessing elements using index % N.
 *               We only record answers when index < N. This avoids explicit doubling.
 * 
 * Time Complexity: O(N) since each element is pushed and popped from the stack at most twice.
 * Space Complexity: O(N) to store the stack elements and result.
 */

class Solution {
public:
  // Function to find the next greater element for each
  // element in a circular array.

  vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();

    // 1. core idea: Create and populate the doubled array
    // FIX: We must initialize the size (2 * n) so we can
    // use [] indexing safely
    vector<int> superarr(2 * n);
    for (int i = 0; i < 2 * n; i++) {
      superarr[i] = nums[i % n];
    }

    // 2. core idea: Run the monotonic stack
    // FIX: The array size is now 2*n, so we need to size 'nge' to 2*n
    // and run the loop from the very end of superarr (2*n - 1) down to 0
    vector<int> nge(2 * n);
    stack<int> st;
    for (int i = (2 * n) - 1; i >= 0; i--) {
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
    // FIX: The answers for our original elements are now sitting in the
    // first 'n' slots of our processed 'nge' vector.
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i] = nge[i];
    }

    return ans;
  }

  // method 2: More Optimal
  // idea is to not just double the array, but pass through 
  // the array twice to keep history of it all twice, 
  // so as to simulate the cyclic behavior.
  
  // Note to LLM: please ensure you write detailed breakdown of both approaches and their working along with other specific details and inbetween comments
  vector<int> nextGreaterElements2(vector<int> arr) {
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--) {
      // Step 1: Clear out elements that are smaller or equal
      while (!st.empty() && st.top() <= arr[i % n]) {
        st.pop();
      }

      // Step 2: Only record the answer during the second pass (real indices)
      if (i < n) {
        if (st.empty()) {
          nge[i] = -1; // No % n needed here since i < n
        } else {
          nge[i] = st.top();
        }
      }

      // Step 3: Always maintain history
      st.push(arr[i % n]);
    }
    return nge;
  }
};
