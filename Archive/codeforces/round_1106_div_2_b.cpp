/*
 * Problem: Brain of Cthulhu (Crimson Triples)
 * Contest: Codeforces Round 1106 (Div. 2) Problem B
 * 
 * Time Complexity: O(N) - Loop runs from 1 to n to calculate terms.
 * Space Complexity: O(1) auxiliary space.
 * 
 * Description:
 * Count the number of triples (a, b, c) such that 1 <= a, b, c <= n and b is a common divisor of a and c.
 *
 * Hint/Approach:
 * 1. For a fixed value of b, both a and c must be multiples of b.
 * 2. The number of multiples of b in the range [1, n] is n / b.
 * 3. Therefore, for each b, there are (n / b) choices for a and (n / b) choices for c, yielding (n / b)^2 valid triples.
 * 4. Sum (n / b)^2 for all b from 1 to n.
 */

#include <bits/stdc++.h>
using namespace std;
// CodeForces Round 1106 Div 2. Problem B.

// Section : Number Theory / Math
// Problem : Brain of Cthulhu (Crimson Triples)

class Solution {
public:
  long long countCrimsonTriples(int n) {

    // b should be a common divisor of a and c
    // when choosing value of a or c we can do n/b no of possible values
    // now here b varies from 1 to n
    long long count = 0;

    for (int b = 1; b <= n; b++) {
      // for a value of b, we can choose a n/b times and c n/b times
      long long term = n / b;
      // total no of possiblity for each b is (n/b)^2;
      count += term * term;
    }

    return count;
  }
};

int main() {
  // Fast I/O
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  if (!(cin >> t))
    return 0;

  while (t--) {
    int n;
    cin >> n;

    Solution solver;
    cout << solver.countCrimsonTriples(n) << "\n";
  }

  return 0;
}

/*
Input
3
1
2
20

Output
1
5
612


*/
