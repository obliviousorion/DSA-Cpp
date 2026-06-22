/*
 * Problem: Convert Infix to Postfix
 * Description: Given an infix expression s, convert it to a postfix expression.
 * Precedence: '^' is highest, followed by '*', '/' and '+', '-'.
 * 
 * Time Complexity: O(N) - since each character is processed and stack operations (push/pop) take O(1) time.
 * Space Complexity: O(N) - auxiliary space for the stack storing operators.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int priority(char val) {
    if (val == '^') {
      return 3;
    } else if (val == '*' || val == '/') {
      return 2;
    } else if (val == '-' || val == '+') {
      return 1;
    } else {
      return -1;
    }
  }

  string infixToPostfix(string s) {
    int i = 0;
    int n = s.length();
    stack<int> stack;
    string ans;
    while (i < n) {
      if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
          (s[i] >= '0' && s[i] <= '9')) {
        ans = ans + s[i];
      } else if (s[i] == '(') {
        stack.push(s[i]);
      } else if (s[i] == ')') {
        while (!stack.empty() && stack.top() != '(') {
          ans += stack.top();
          stack.pop();
        }
        if (!stack.empty()) stack.pop();
      } else {
        // Pop operators from stack with higher or equal priority
        while (!stack.empty() && priority(s[i]) <= priority(stack.top())) {
          ans += stack.top();
          stack.pop();
        }
        stack.push(s[i]);
      }
      i++;
    }

    while (!stack.empty()) {
      ans += stack.top();
      stack.pop();
    }
    return ans;
  }
};
