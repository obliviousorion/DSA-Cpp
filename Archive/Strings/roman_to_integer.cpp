/*
 * Problem: Roman to Integer
 * 
 * Description:
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * Given a roman numeral, convert it to an integer.
 * 
 * Complexity:
 * - Time Complexity: O(N) where N is the length of the string s. We iterate through the string once.
 * - Space Complexity: O(1) auxiliary space. The map size is fixed at 7 elements.
 * 
 * Approaches:
 * 1. Hash Map & Right-to-Left Traversal (User's Solution):
 *    Use an `std::unordered_map` to store key-value mappings. Traverse the string from right to left,
 *    accumulating the value. If the current character's value is smaller than the previous character's value,
 *    subtract it (subtractive rule); otherwise, add it.
 * 
 * 2. Helper/Switch Function (Alternative - Optimization):
 *    Instead of using `std::unordered_map`, resolve character values using a helper function with a `switch` statement.
 *    This avoids hash table overhead, lookup costs, and dynamic allocations, providing a minor speed and memory boost.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
      unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int n = (int)s.size();
        int ans = m[s[n - 1]];
        int prev = m[s[n - 1]];

        for (int i = n - 2; i >= 0; i--) {
            int cur = m[s[i]];

            if (cur < prev) {
                ans -= cur;
            } else {
                ans += cur;
            }

            prev = cur;
        }

        return ans;
    }
};
