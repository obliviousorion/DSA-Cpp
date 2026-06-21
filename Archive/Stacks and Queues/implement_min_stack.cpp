/*
 * Problem: Implement Min Stack
 * Description: Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * Approach: Two Stacks. Use a main stack to store the elements, and an auxiliary stack to keep track of
 *           the minimum elements. When pushing an element, we push the current minimum to the auxiliary stack 
 *           so that both stacks are always synchronized in size.
 * Time Complexity:
 *   - push(): O(1)
 *   - pop(): O(1)
 *   - top(): O(1)
 *   - getMin(): O(1)
 * Space Complexity: O(N) auxiliary space.
 */

#include <bits/stdc++.h>
using namespace std;

class MinStack {
  stack<int> s;
  stack<int> min_s;

public:
  MinStack() {}

  void push(int val) {
    s.push(val);

    if (min_s.empty() || val <= min_s.top()) {
      min_s.push(val);
    } else {
      min_s.push(min_s.top());
    }
  }

  void pop() {
    if (!s.empty()) {
      s.pop();
      min_s.pop();
    }
  }

  int top() {
    if (!s.empty()) {
      return s.top();
    }
    return -1;
  }

  int getMin() {
    if (!min_s.empty()) {
      return min_s.top(); // The current minimum is always sitting right at the top!
    }
    return -1;
  }
};
