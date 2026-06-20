/*
 * Problem: Largest Odd Number in String
 * Description: Given a string num representing a large integer, return the largest-valued odd integer (as a string) 
 *              that is a non-empty substring of num, or an empty string "" if no odd integer exists.
 * 
 * Approach:
 * - An odd integer must end in an odd digit (1, 3, 5, 7, 9).
 * - To maximize the value, we should keep the substring as long as possible.
 * - Therefore, we scan the string from right to left (from the least significant digit to most).
 * - The first odd digit we encounter marks the end of the largest odd substring. We return the substring from index 0 to this index.
 * 
 * Complexity:
 * - Time Complexity: O(N) where N is the length of string `num`.
 * - Space Complexity: O(1) auxiliary space.
 */

#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) { 
        int n = num.length();

        // Scan from right to left to find the rightmost odd digit
        for (int i = n - 1; i >= 0; i--) {
            int digit = num[i] - '0';
            
            if (digit % 2 != 0) { // Found the rightmost odd digit!
                // The largest odd number is from index 0 to index i.
                // The length of this substring is (i + 1).
                return num.substr(0, i + 1);
            }
        }

        // If the loop finishes, no odd digit exists in the entire string
        return "";
    }
};
