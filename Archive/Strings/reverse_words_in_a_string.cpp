/*
 * Problem: Reverse Words in a String
 * Description: Given an input string s, reverse the order of the words. A word is defined as a sequence of non-space characters.
 *              The returned string should only have a single space separating the words, with no leading/trailing spaces.
 * 
 * Complexity:
 * - Stringstream Approach (reverseWords2):
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 * - In-place Two-Pointer Approach (reverseWords):
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1) auxiliary space (modifying the string in-place)
 */

#include <algorithm>
#include <bits/stdc++.h>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords2(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        // Step 1: Extract all words -> O(N)
        while (ss >> word) {
            words.push_back(word);
        }

        // Step 2: Build the string by appending to the end -> O(N)
        string reversed = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            reversed += words[i];
            if (i > 0) {
                reversed += " ";
            }
        }
        
        return reversed; // The almost optimal approach
    }

    // The absolute best and optimal approach
    string reverseWords(string s) {
        // Step 1: Reverse the whole string
        reverse(s.begin(), s.end());
        
        int n = s.length();
        int writeIdx = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                // If it's not the first word, add a single space separator
                if (writeIdx != 0) s[writeIdx++] = ' ';
                
                // Go to the end of the current word
                int start = writeIdx;
                while (i < n && s[i] != ' ') {
                    s[writeIdx++] = s[i++];
                }
                
                // Reverse the word back to its original order
                reverse(s.begin() + start, s.begin() + writeIdx);
            }
        }
        
        // Resize the string to remove trailing garbage characters
        s.erase(s.begin() + writeIdx, s.end());
        return s;
    }
};
