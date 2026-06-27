#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

/*
 * Problem: Longest Substring Without Repeating Characters
 * 
 * Description:
 * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * Constraints:
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 * 
 * Approach:
 * Sliding window technique using an unordered_set to track characters in the current window.
 * The window is expanded by moving high_ptr. If a character is already present in the set,
 * we shrink the window from the left by moving low_ptr and removing characters from the set
 * until the duplicate character is removed.
 * 
 * Time Complexity: O(N) where N is the length of the string.
 * Space Complexity: O(min(M, N)) where M is the size of the alphabet/character set.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> tracker;
        int n = s.size();
        int low_ptr = 0;
        int max_len = 0;

        for (int high_ptr = 0; high_ptr < n; high_ptr++) {
            // Keep erasing characters from the left until we can insert the current character successfully
            while (!tracker.insert(s[high_ptr]).second) {
                tracker.erase(s[low_ptr++]);
            }

            max_len = max(max_len, high_ptr - low_ptr + 1);
        }
        return max_len;
    }
};
