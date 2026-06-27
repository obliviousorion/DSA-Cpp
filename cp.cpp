#include <bits/stdc++.h>
using namespace std;

/**
 * PROBLEM: A. Another Popcount Problem
 * * You are given two integers n and k.
 * Your task is to construct a sequence 'a' consisting of k non-negative integers 
 * a_1, a_2, ..., a_k such that:
 * 1. The sum of all a_i <= n
 * 2. The total number of set bits (sum of popcount(a_i)) is as large as possible.
 * * You only need to output the maximum possible value of the sum of popcounts.
 * Here, popcount(x) denotes the number of 1 bits in the binary representation of x.
 * * CONSTRAINTS:
 * - t (1 <= t <= 10^3) -> Number of test cases
 * - n, k (1 <= n, k <= 10^6) -> Max allowed sum and length of the sequence
 * * EXAMPLES: 
 * - Input: 2 1       -> Output: 1  (a = [1] or [2])
 * - Input: 3 1       -> Output: 2  (a = [3] -> popcount(3) = 2)
 * - Input: 6 2       -> Output: 4  (a = [3, 3] -> 2 + 2 = 4)
 * - Input: 14142 137205 -> Output: 14142
 * - Input: 1000000 100 -> Output: 1322
 * - Input: 1000000 1000000 -> Output: 1000000
 */

// Implement your logic to calculate the maximum popcount sum here
long long getMaxPopcountSum(long long n, long long k) {
    // ----------------------------------------------------
    // YOUR CODE HERE
    // Return the maximum possible value of the sum of popcounts
    // ----------------------------------------------------
}

void solve() {
    long long n, k;
    cin >> n >> k;
    
    cout << getMaxPopcountSum(n, k) << "\n";
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

// run command
// cd "c:\projects\DSA-Cpp\" ; if ($?) { g++ -O3 cp.cpp -o cp.exe } ; if ($?) { cat input.txt | ./cp.exe > output.txt } ; if ($?) { echo "" } ; if ($?) { echo "[Output]:" } ; if ($?) { cat output.txt } ; if ($?) { echo "" } ; if ($?) { rm cp.exe }