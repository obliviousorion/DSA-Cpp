/*
 * Problem: Storming Arasaka (Layered Divisors)
 * Contest: Codeforces Round 1106 (Div. 2) Problem D
 * 
 * Time Complexity: O(MAXN log log MAXN) precomputation, O(log N) per query.
 * Space Complexity: O(MAXN) auxiliary space for the Smallest Prime Factor (SPF) array.
 * 
 * Description:
 * Determine the minimum number of layers/operations to reduce or decompose a number N using divisor rules.
 *
 * Hint/Approach:
 * 1. Precompute the Smallest Prime Factor (SPF) for all numbers up to 1,000,000 using a sieve.
 * 2. For each query, perform prime factorization of N in O(log N) time using the SPF array.
 * 3. Count total prime factors (with multiplicity) and distinct prime factors.
 * 4. The minimum layers formula is derived as: total_factors + distinct_factors - 1.
 */

#include <bits/stdc++.h>
using namespace std;

// CodeForces Round 1106 Div 2. Problem D.

// Section : Number Theory / Math
// Problem : Storming Arasaka (Layered Divisors)


const int MAXN = 1000000;
int spf[MAXN + 1];

// Precompute the Smallest Prime Factor (SPF) using a Sieve
void sieve() {
    for (int i = 1; i <= MAXN; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

class Solution {
public:
    int minLayers(int n) {
        int total_factors = 0;
        int distinct_factors = 0;
        int temp = n;

        // Perform prime factorization using the precomputed SPF array
        while (temp > 1) {
            int p = spf[temp];
            distinct_factors++;
            while (temp % p == 0) {
                total_factors++;
                temp /= p;
            }
        }

        // Apply the derived formula
        return total_factors + distinct_factors - 1;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Run the sieve once before processing test cases
    sieve();

    int t;
    if (!(cin >> t)) return 0;

    Solution solver;
    while (t--) {
        int n;
        cin >> n;
        cout << solver.minLayers(n) << "\n";
    }

    return 0;
}

/*
Input
8
2
4
8
16
32
67
120
33

Output
1
2
3
4
5
1
7
3

*/