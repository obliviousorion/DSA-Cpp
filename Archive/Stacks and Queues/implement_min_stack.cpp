/*
 * Problem: Implement Min Stack
 * Description: Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * Approach 1 (Optimal): One Stack + Min Variable. By pushing encoded values (2 * x - minElement) when a new 
 *                       minimum is encountered, we can retrieve/restore the previous minimum upon popping.
 *   - Time Complexity: O(1) for push, pop, top, getMin.
 *   - Space Complexity: O(1) auxiliary space (excluding the main stack).
 * 
 * Approach 2 (Two Stacks): A main stack to store values and an auxiliary stack to keep track of minimums.
 *   - Time Complexity: O(1) for push, pop, top, getMin.
 *   - Space Complexity: O(N) auxiliary space.
 */

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Single Stack (Optimal Space)
class MinStack {
private:
  stack<long long> s;
  long long minElement;

public:
  MinStack() { minElement = INT_MAX; }

  void push(int val) {
    long long x = val;

    if (s.empty()) {
      minElement = x;
      s.push(x);
    } else if (x >= minElement) {
      s.push(x); // Normal push
    } else {
      // New minimum encountered! Push the encoded flag
      s.push(2 * x - minElement);
      minElement = x; // Update current minimum
    }
  }

  void pop() {
    if (s.empty())
      return;

    long long topElement = s.top();
    s.pop();

    // If the popped element is less than minElement, it was a flag
    if (topElement < minElement) {
      // Decode and restore the previous minimum
      minElement = 2 * minElement - topElement;
    }
  }

  int top() {
    if (s.empty())
      return -1;

    long long topElement = s.top();
    // If it's less than minElement, the actual value is minElement itself
    if (topElement < minElement) {
      return minElement;
    }
    return topElement;
  }

  int getMin() {
    if (s.empty())
      return -1;
    return minElement;
  }
};

// Approach 2: Two Stacks
class MinStack2 {
  stack<int> s;
  stack<int> min_s;

public:
  MinStack2() {}

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
      return min_s.top();
    }
    return -1;
  }
};
