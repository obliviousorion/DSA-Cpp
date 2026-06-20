#include <bits/stdc++.h>
using namespace std;


// Section : Strings
// Problem : Rotate String

class Solution {
public:
    bool rotateString(string s, string goal) {

        
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, goal;
    while (cin >> s >> goal) {
        Solution sol;
        if (sol.rotateString(s, goal)) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }

    return 0;
}