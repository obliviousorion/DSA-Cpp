/*
 * Problem: Implement Stack using Queues
 * Description: Implement a last-in-first-out (LIFO) stack using only two queues or a single queue.
 *              The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
 * Approach: Single Queue Rotation. When pushing an element, we enqueue it and then rotate the queue 
 *           by moving the previous elements to the back. This reverses the order, keeping the newly 
 *           added element at the front (LIFO order).
 * Time Complexity:
 *   - push(): O(N) where N is the number of elements in the stack.
 *   - pop(): O(1)
 *   - top(): O(1)
 *   - empty(): O(1)
 * Space Complexity: O(N) to store elements in the queue.
 */

#include <bits/stdc++.h>
using namespace std;

class MyStack {
  queue<int> q;
  int count;

public:
  MyStack() { this->count = 0; }

  // Pushes element x to the top of the stack.
  void push(int x) {
    q.push(x);

    // Rotate the queue to bring the new element to the front
    for (int i = 0; i < count; i++) {
      int temp = q.front();
      q.pop();
      q.push(temp);
    }
    count++;
  }

  // Removes the element on the top of the stack and returns it.
  int pop() {
    int temp = q.front();
    q.pop();
    count--;
    return temp;
  }

  // Returns the element on the top of the stack.
  int top() {
    if (empty()) {
      return -1;
    }
    return q.front();
  }

  // Returns true if the stack is empty, false otherwise.
  bool empty() { return count == 0; }
};
