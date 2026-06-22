#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: Previous Smaller Element
 * Description: Given an array of integers, find the nearest smaller element for every element 
 *              to its left. If no smaller element exists on the left, return -1.
 * 
 * Approach:
 *   - Use a monotonic stack to store elements in increasing order.
 *   - For each element, pop elements from the stack that are greater than or equal to the current element.
 *   - If the stack is empty, return -1. Otherwise, the top of the stack is the nearest smaller element.
 *   - Push the current element onto the stack to serve as history for future elements.
 * 
 * Time Complexity: O(N) as each element is pushed and popped from the stack at most once.
 * Space Complexity: O(N) auxiliary space for the stack.
 */

class Solution {
public:
  vector<int> previousSmallestElement(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> pse(n); // Allocated size n upfront

    for (int i = 0; i < n; i++) {

      // Clear elements that are greater than or equal to the current element
      while (!st.empty() && st.top() >= arr[i]) {
        st.pop();
      }

      // If stack is empty, no smaller element exists to the left
      if (st.empty()) {
        pse[i] = -1;
      } else {
        pse[i] = st.top(); // The closest smaller element
      }

      // Push current element to serve as history for elements to its right
      st.push(arr[i]);
    }
    return pse;
  }
};
