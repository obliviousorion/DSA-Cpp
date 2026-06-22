#include <bits/stdc++.h>
using namespace std;

// Section : Stacks and Queues
// Problem : Previous Smaller Element

class Solution {
public:
    vector<int> prevSmaller(vector<int>& arr) {
        // Write solution logic here
        return {};
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res = ob.prevSmaller(arr);
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}