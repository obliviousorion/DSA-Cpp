#include <bits/stdc++.h>
using namespace std;

// Section : Strings
// Problem : Longest Common Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& words) {
        
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        vector<string> strs(n);
        for (int i = 0; i < n; i++) {
            cin >> strs[i];
        }
        Solution sol;
        cout << sol.longestCommonPrefix(strs) << "\n";
    }

    return 0;
}