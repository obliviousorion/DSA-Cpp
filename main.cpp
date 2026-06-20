#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// Section : Strings
// Problem : Isomorphic Strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapofworld;
        
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    while (cin >> s >> t) {
        Solution sol;
        if (sol.isIsomorphic(s, t)) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }

    return 0;
}