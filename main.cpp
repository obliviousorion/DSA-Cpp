#include <bits/stdc++.h>
using namespace std;

// Section : Sliding Window and Two Pointers
// Problem : Longest Repeating Character Replacement

/*
Problem Statement:
You are given a string s and an integer k. You can choose any character of the string 
and change it to any other uppercase English character. You can perform this operation 
at most k times.

Return the length of the longest substring containing the same letter you can get after 
performing the above operations.

Constraints:
1 <= s.length <= 10^5
s consists of only uppercase English letters.
0 <= k <= s.length

Time Complexity Goal: O(N)
Auxiliary Space Complexity Goal: O(1)

Example:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        // Write solution logic here
        return 0;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int k;
    if (!(cin >> s >> k)) return 0;

    Solution solver;
    cout << solver.characterReplacement(s, k) << "\n";

    return 0;
}