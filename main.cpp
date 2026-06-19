#include <bits/stdc++.h>
using namespace std;

// Section : Strings
// Problem : Remove Outermost Parentheses

class Solution {
public:
    string removeOuterParentheses(string s) {
        string newString = "";
        newString.reserve(s.length());
        int depth = 0;
        for (char c: s) {
            if (c == '(') {
                if (depth++ > 0) {
                    newString += c;
                }
                
            } else {
                if (--depth > 0) {
                    newString += c;
                }
            }
        }
        return newString;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        Solution sol;
        cout << sol.removeOuterParentheses(s) << "\n";
    }

    return 0;
}