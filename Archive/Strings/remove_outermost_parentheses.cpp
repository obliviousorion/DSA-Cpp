/*
 * Problem: Remove Outermost Parentheses
 * 
 * Description:
 * A valid parentheses string is either empty, "(" + A + ")", or A + B, where A and B are valid parentheses strings.
 * We want to remove the outermost parentheses of every primitive valid parentheses string in the decomposition of s.
 * 
 * Approach:
 * Keep track of the depth of parentheses. We only add a character to our result if:
 * - It is '(' and the depth was already greater than 0 (i.e. not the outermost opening parenthesis).
 * - It is ')' and the depth will remain greater than 0 after decrementing (i.e. not the outermost closing parenthesis).
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(N) (for the output string) / O(1) auxiliary
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string newString = "";
        newString.reserve(s.length());
        int depth = 0;
        for (char c: s) {
            if (c == '(') {
                if (depth++ > 0) {
                    newString += c;
                }
            } else {
                if (--depth > 0) {
                    newString += c;
                }
            }
        }
        return newString;
    }
};
