/*
 * Problem: Next Greater Element
 * Description: Find the next greater element for each element in the array. 
 *              The next greater element of an element x is the first larger element to its right. 
 *              If no such element exists, output -1.
 * 
 * Theory of Monotonic Stack:
 *   A monotonic stack is a stack that maintains its elements in a specific sorted order. 
 *   For finding the Next Greater Element, we maintain a monotonically decreasing stack (from bottom to top).
 *   By iterating from right to left (backwards):
 *     1. We pop elements from the stack that are smaller than or equal to the current element. 
 *        Since the current element is larger and appears to the left of these elements, 
 *        none of the popped elements can ever be the next greater element for any element further to the left.
 *     2. After the while loop, if the stack is empty, it means there is no element to the right of the 
 *        current element that is greater than it (so we assign -1). Otherwise, the stack top is the next greater element.
 *     3. We push the current element onto the stack to act as a potential next greater element for elements to its left.
 *   This ensures each element is pushed and popped at most once, yielding O(N) time complexity.
 * 
 * Time Complexity:
 *   - Method 1 (Brute-force): O(N^2)
 *   - Method 2 (Monotonic Stack): O(N) since each element is pushed and popped at most once.
 * Space Complexity:
 *   - Method 1: O(1) auxiliary space (excluding result array).
 *   - Method 2: O(N) for the stack.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Method 1: Brute-force
  vector<int> nextLargerElement(vector<int> arr, int n) {
    vector<int> nge;
    for (int i = 0; i < n; i++) {
      bool found = false;
      for (int j = i + 1; j < n; j++) {
        if (arr[i] < arr[j]) {
          nge.emplace_back(arr[j]);
          found = true;
          break;
        }
      }
      if (!found) {
        nge.emplace_back(-1);
      }
    }
    return nge;
  }

  // Method 2: Monotonic Stack (Optimal)
  vector<int> nextLargerElement2(vector<int> arr, int n) {
    vector<int> nge(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
      // For each iteration, we first remove the smaller top elements
      while (!st.empty() && st.top() <= arr[i]) {
        st.pop();
      }

      // Then check if stack is empty
      if (st.empty()) {
        nge[i] = -1; // If empty, there is no greater element
      } else {
        nge[i] = st.top(); // If not empty, the top of stack is the next greater element
      }

      st.push(arr[i]); // Push the current element as well to keep a history
    }
    return nge;
  }
};
