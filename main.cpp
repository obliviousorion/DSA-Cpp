#include <bits/stdc++.h>
using namespace std;

// Section : Stacks and Queues
// Problem : Trapping Rain Water

class Solution {
public:
    int trap(vector<int>& height) {
        // Write solution logic here
        return 0;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> height(n);
        for (int i = 0; i < n; i++) {
            cin >> height[i];
        }
        Solution ob;
        cout << ob.trap(height) << "\n";
    }

    return 0;
}