/*
 * Problem: Infix to Prefix
 * Description: Convert an infix expression to a prefix expression.
 * Approach:
 *   1. Reverse the infix expression.
 *   2. Swap the opening and closing parentheses: '(' becomes ')' and vice versa.
 *   3. Convert the modified expression to postfix. To maintain the correct evaluation 
 *      order (associativity), pop from the stack only when the stack top has strictly 
 *      greater precedence (or equal precedence when operator is right-associative '^').
 *   4. Reverse the resulting postfix expression to get the prefix expression.
 * 
 * Time Complexity: O(N) where N is the length of the string, as each character is processed in O(1) time.
 * Space Complexity: O(N) for the stack.
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

  string infixToPrefix(string s) {
    // 1. Reverse the infix expression
    reverse(s.begin(), s.end());

    // 2. Swap '(' and ')' to restore grouping orientation
    for (int i = 0; i < (int)s.length(); i++) {
      if (s[i] == '(') {
        s[i] = ')';
      } else if (s[i] == ')') {
        s[i] = '(';
      }
    }

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
        // Pop operators from stack with strictly higher priority,
        // or equal priority only if it is right-associative '^'
        while (!stack.empty() && (
            priority(s[i]) < priority(stack.top()) ||
            (priority(s[i]) == priority(stack.top()) && s[i] == '^')
        )) {
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

    // 3. Reverse the postfix expression to get prefix
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
