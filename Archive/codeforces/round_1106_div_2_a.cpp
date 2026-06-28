/*
 * Problem: Papyrus's Puzzle (Convert Array a to Array b)
 * Contest: Codeforces Round 1106 (Div. 2) Problem A
 * 
 * Time Complexity: O(N log N) - Sorting arrays a and b takes O(N log N) time.
 * Space Complexity: O(1) auxiliary space - Sorting is done in-place on the input vectors.
 * 
 * Description:
 * Determine the minimum cost to convert array a to array b.
 * We can either convert without reordering, or reorder the elements of array a and b at cost c.
 * In both cases, array a can only be converted to array b if every element a[i] >= b[i].
 *
 * Hint/Approach:
 * 1. Without reordering: Directly compare a[i] and b[i]. If any a[i] < b[i], conversion is impossible. Otherwise, the cost is the sum of differences.
 * 2. With reordering: Sort both arrays first, then compare element-wise. The cost is c + sum of differences of sorted elements.
 * 3. Return the minimum of the two costs if both are possible, or the only possible one, or -1 if impossible.
 */

#include <bits/stdc++.h>
using namespace std;

// CodeForces Round 1106 Div 2. Problem A.
// Section : Greedy
// Problem : Papyrus's Puzzle (Convert Array a to Array b)

class Solution {
public:
    long long solvePuzzle(int n, int c, vector<int>& a, vector<int>& b) {
        long long cost_with_reorder = c;
        long long cost_without_reorder = 0;

        // calculate cost without reorder and if its possible or not
        bool possible_without_reorder = true; // assuming its truee
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                possible_without_reorder = false;
                break;
            }
            cost_without_reorder += (a[i] - b[i]);
        }

        // now if we choose to reorder then all the relevant elements  
        // have to line up
        // lets sort first to simulate that
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        bool possible_with_reorder = true;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                possible_with_reorder = false;
                break;
            }
            cost_with_reorder += (a[i] - b[i]);
        }

        if (!possible_without_reorder && !possible_with_reorder) {
            return -1;
        }
        if (!possible_without_reorder) {
            return cost_with_reorder;
        }
        if (!possible_with_reorder) {
            return cost_without_reorder;
        }
        
        return min(cost_without_reorder, cost_with_reorder);
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n, c;
        cin >> n >> c;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        Solution solver;
        cout << solver.solvePuzzle(n, c, a, b) << "\n";
    }

    return 0;
}


/*Example Input:

6
3 5
5 2 3
2 3 4
3 3
1 2 3
4 5 6
4 4
4 5 2 3
3 5 1 2
6 4
2 4 5 3 6 8
5 8 3 1 2 5
5 11
5 8 11 14 17
16 12 10 10 6
3 5
20 14 20
12 18 17

Output
6
-1
3
8
-1
12


*/
