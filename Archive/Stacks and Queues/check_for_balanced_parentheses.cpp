/*
 * Problem: Check for Balanced Parentheses (Valid Parentheses)
 * Description: Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
 *              determine if the input string is valid. An input string is valid if open brackets 
 *              are closed by the same type of brackets, and in the correct order.
 * Approach: Stack match. Traverse the string and push the corresponding closing bracket to a stack
 *           whenever an opening bracket is seen. For a closing bracket, verify that the stack is 
 *           not empty and the top of the stack matches the current character, then pop.
 * Time Complexity: O(N) where N is the length of the string.
 * Space Complexity: O(N) to store the brackets in the stack in the worst case.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> tracer;
    for (char c : s) {
      // If it's an opening bracket, push its expected CLOSING match
      if (c == '(') {
        tracer.push(')');
      } else if (c == '[') {
        tracer.push(']');
      } else if (c == '{') {
        tracer.push('}');
      }
      // If it's a closing bracket
      else {
        // Trap 1: If stack is empty, we have a closing bracket with no opener
        // Trap 2: If the top of stack doesn't match 'c', the order is wrong
        if (tracer.empty() || tracer.top() != c) {
          return false;
        }
        tracer.pop(); // Successfully matched, pop it!
      }
    }
    // If tracer stack is empty then all the brackets were matched
    return tracer.empty();
  }
};
