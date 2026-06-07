#include <bits/stdc++.h>
using namespace std;

// Section : Binary Search
// Problem : Find Square Root of N

// Determine square root of N and if N is not a perfect square
// determine the floor value of sqrt(N).


class Solution{
public:
    int findSqrtOfN(int n){
        int low = 0;
        int high = n;
        int ans = -1;
        // we need to find k such that k * k is n
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long square = (long long)mid * mid;
            if(square == n){
                return mid;
            } else if(square < n){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};


int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.findSqrtOfN(n);
    return 0;
}