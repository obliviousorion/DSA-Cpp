/*
 * Problem: Implement Queue using Stacks
 * Description: Implement a first-in-first-out (FIFO) queue using only two stacks.
 *              The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
 * Approach: Push-heavy method. To ensure the oldest element is always at the top of the stack `s1`
 *           (acting as the front of the queue), we transfer all elements from `s1` to `s2`, 
 *           push the new element to `s1`, and then move everything back from `s2` to `s1`.
 * Time Complexity:
 *   - push(): O(N) where N is the number of elements in the queue.
 *   - pop(): O(1)
 *   - peek(): O(1)
 *   - empty(): O(1)
 * Space Complexity: O(N) to store elements in the two stacks.
 */

#include <bits/stdc++.h>
#include <stack>
using namespace std;

class MyQueue {
  stack<int> s1;
  stack<int> s2;

public:
  MyQueue() {}

  // Pushes element x to the back of the queue.
  void push(int x) {
    // 1. Move all elements from s1 to s2
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }

    // 2. Push the new element to the bottom of the queue order
    s1.push(x);

    // 3. Move everything back from s2 to s1
    while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
  }

  // Removes the element from the front of the queue and returns it.
  int pop() {
    if (empty()) {
      return -1; // Guard against pulling from an empty queue
    }
    int temp = s1.top();
    s1.pop(); // s1 automatically decrements its own internal size
    return temp;
  }

  // Get the front element.
  int peek() {
    if (empty()) {
      return -1; // Guard against viewing an empty queue
    }
    return s1.top();
  }

  // Returns whether the queue is empty.
  bool empty() { return s1.empty(); }
};
