#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * Problem: Longest Repeating Character Replacement
 * 
 * Description:
 * You are given a string s and an integer k. You can choose any character of the string 
 * and change it to any other uppercase English character. You can perform this operation 
 * at most k times. Return the length of the longest substring containing the same letter 
 * you can get after performing the above operations.
 * 
 * Constraints:
 * 1 <= s.length <= 10^5
 * s consists of only uppercase English letters.
 * 0 <= k <= s.length
 * 
 * Approach:
 * Sliding window technique (variable size). Maintain a count array of size 26 for frequencies.
 * Track maxFreq, which is the maximum frequency of any character within the current window [left, right].
 * The size of the window is (right - left + 1). The number of characters that need to be replaced is
 * (window_size - maxFreq).
 * - If (window_size - maxFreq) > k, we shrink the window from the left by decrementing count[s[left]]
 *   and incrementing left.
 * - Otherwise, the window is valid, and we update maxLength.
 * 
 * Time Complexity: O(N) where N is the length of string s.
 * Space Complexity: O(1) auxiliary space (using a constant-sized frequency array of size 26).
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxFreq = 0;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            // Update frequency of the current character
            count[s[right] - 'A']++;
            
            // Track the highest frequency character seen in the current window
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            // If (window size - maxFreq) > k, we have exceeded allowed replacements
            if ((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            // The window is always valid here, update max length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
