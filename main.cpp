#include <bits/stdc++.h>
using namespace std;

// Section : Stacks and Queues
// Problem : Next Greater Element

class Solution {
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n) {
        // Write solution logic here
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            vector<long long> arr(n);
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            Solution ob;
            vector<long long> res = ob.nextLargerElement(arr, n);
            for (int i = 0; i < n; i++) {
                cout << res[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}