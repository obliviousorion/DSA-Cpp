/*
 * Problem: Isomorphic Strings
 * 
 * Description:
 * Given two strings s and t, determine if they are isomorphic.
 * Two strings s and t are isomorphic if the characters in s can be replaced to get t.
 * All occurrences of a character must be replaced with another character while preserving the order of characters.
 * No two characters may map to the same character, but a character may map to itself.
 * 
 * Complexity:
 * - Time Complexity: O(N) where N is the length of the strings. We iterate through the strings exactly once.
 * - Space Complexity: O(1) auxiliary space. We use two arrays of fixed size 256, which does not grow with input size.
 * 
 * Approaches:
 * 1. Direct Array Mapping (User's Solution - Most Optimal):
 *    Uses two fixed-size arrays (size 256) to track the last-seen indices of characters in both strings.
 *    Mapping is updated to `i + 1` (to distinguish from the default initialization value of 0).
 *    This is extremely cache-friendly and avoids hash map overhead/dynamic allocations.
 * 
 * 2. Map-based Mapping (Alternative):
 *    Uses two hash maps (std::unordered_map<char, char>) to store bi-directional character mappings.
 *    Provides O(N) average time complexity but has higher constant factor overhead due to hashing and dynamic allocations.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }

    // Two arrays of size 256 for direct ASCII character mapping
    int map_s[256] = {0};
    int map_t[256] = {0};

    for (int i = 0; i < s.length(); ++i) {
      // If characters map to different last-seen positions, strings are not isomorphic
      if (map_s[s[i]] != map_t[t[i]]) {
        return false;
      }

      // Update mapping to current index + 1 (using +1 to differentiate index 0 from unseen)
      map_s[s[i]] = i + 1;
      map_t[t[i]] = i + 1;
    }

    return true;
  }
};
