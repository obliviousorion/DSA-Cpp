/*
 * Problem: Rotate String
 * 
 * Description:
 * Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
 * A shift on s consists of moving the leftmost character of s to the rightmost position.
 * 
 * Complexity:
 * - Time Complexity:
 *   1. Brute Force (rotateString2): O(N^2) where N is the length of s. Each rotation takes O(N) and we rotate at most N times.
 *   2. Optimal Substring Search (rotateString): O(N) since substring search (e.g., using standard string::find) runs in linear time.
 * - Space Complexity:
 *   1. Brute Force (rotateString2): O(1) auxiliary space.
 *   2. Optimal Substring Search (rotateString): O(N) auxiliary space to store the doubled string (s + s).
 * 
 * Approaches:
 * 1. Brute Force (rotateString2):
 *    Repeatedly rotate the string `s` one character at a time using `std::rotate` and check if it matches `goal`.
 * 
 * 2. Doubled String Substring Search (rotateString - Most Optimal):
 *    A rotated version of `s` must always be a substring of `s + s` (the concatenated doubled string).
 *    If `s.size() == goal.size()` and `(s + s).find(goal) != string::npos`, then `goal` is a valid rotation of `s`.
 */

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
  // bruteforce method
  bool rotateString2(string s, string goal) {
    if (s.size() != goal.size()) {
      return false;
    }
    if (s == goal)
      return true;
    // approach 1 is just rotate string and compare
    int n = s.size();

    for (int i = 0; i < n; i++) {
      rotate(s.begin(), s.begin() + 1, s.end());
      if (s == goal) {
        return true;
      }
    }
    return false;
  }

  // much more efficient method
  bool rotateString(string s, string goal) {
    // A rotated string must have the same length
    if (s.size() != goal.size()) {
      return false;
    }

    // Concatenate s with itself
    string doubledString = s + s;

    // Check if goal is a substring of the doubled string
    // string::npos is returned if the substring is not found
    return doubledString.find(goal) != string::npos;
  }
};
