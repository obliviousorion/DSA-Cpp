#include <bits/stdc++.h>
using namespace std;

// Section : Strings
// Problem : Roman to Integer

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

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while (cin >> s) {
        Solution sol;
        cout << sol.romanToInt(s) << "\n";
    }

    return 0;
}