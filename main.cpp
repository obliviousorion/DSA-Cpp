#include <bits/stdc++.h>
using namespace std;

// Section : Stacks and Queues
// Problem : Remove K Digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        // Write solution logic here
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string num;
    int k;
    if (cin >> num >> k) {
        Solution ob;
        cout << ob.removeKdigits(num, k) << "\n";
    }

    return 0;
}