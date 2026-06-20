/*
 * Problem: Longest Common Prefix
 * Description: Find the longest common prefix string amongst an array of strings. 
 *              If there is no common prefix, return an empty string "".
 * 
 * Approach 1 (Sorting):
 * - Sort the array alphabetically. The longest common prefix of the entire array 
 *   will be the common prefix between the first and the last strings after sorting.
 * - Time Complexity: O(N * L * log(N)), where N is the number of strings and L is the max length of a string.
 * - Space Complexity: O(L) to store the prefix / sorting space.
 * 
 * Approach 2 (Vertical Scanning):
 * - Take the first word as a reference and compare each character position of 
 *   this reference word across all other words.
 * - Time Complexity: O(N * L), where N is the number of strings and L is the length of the shortest string.
 * - Space Complexity: O(1) auxiliary space.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  // Approach 1: Sorting-based search
  string longestCommonPrefix(vector<string> &words) {
    // The simplest solution is to sort the vector alphabetically (N log N)
    // and compare the prefix shared by the first and the last element.
    sort(words.begin(), words.end());
    int n = words.size();
    string first = words[0];
    string last = words[n - 1];
    string reversed;
    int idx = 0;
    while (idx < first.length() && idx < last.length() &&
           first[idx] == last[idx]) {
      reversed.push_back(first[idx++]);
    }
    return reversed;
  }

  // Approach 2: Vertical scanning
  string longestCommonPrefix2(vector<string> &words) {
    if (words.empty())
      return "";

    // Take the first word as a reference
    string reference = words[0];

    // Loop through every character index of the reference word
    for (int j = 0; j < reference.size(); j++) {
      char ch = reference[j];

      // Check this character against the same position in all other words
      for (int i = 1; i < words.size(); i++) {
        // Edge case check: if current word is shorter than index 'j' or character mismatches
        if (j >= words[i].size() || words[i][j] != ch) {
          // Return the prefix found so far (from index 0 to j)
          return reference.substr(0, j);
        }
      }
    }

    return reference;
  }
};
