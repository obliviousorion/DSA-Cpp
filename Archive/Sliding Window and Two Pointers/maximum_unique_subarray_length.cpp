/*
 * Problem : Maximum Unique Subarray Length
 * Time Complexity : O(N)
 * Space Complexity : O(min(N, U)) where U is the size of the character alphabet set.
 *
 * Description:
 * Given a string s, find the length of the longest substring that contains 
 * only unique characters (no duplicate characters allowed within the substring).
 */

#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        unordered_set<char> tracker;
        int n = s.size();
        int l_ptr = 0;
        for (int r_ptr = 0; r_ptr < n; r_ptr++) {
            // Remove characters from left until there are no duplicates of s[r_ptr]
            while (!tracker.insert(s[r_ptr]).second) {
                tracker.erase(s[l_ptr++]);
            }
            max_len = max(max_len, r_ptr - l_ptr + 1);
        }
        return max_len;
    }
};
