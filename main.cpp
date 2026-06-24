#include <bits/stdc++.h>
using namespace std;

// Section : Stacks and Queues
// Problem : Largest Rectangle in Histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Write solution logic here
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }
        Solution ob;
        cout << ob.largestRectangleArea(heights) << "\n";
    }

    return 0;
}