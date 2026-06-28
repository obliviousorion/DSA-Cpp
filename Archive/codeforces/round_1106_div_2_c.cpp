/*
 * Problem: Guilds in a Rooted Tree
 * Contest: Codeforces Round 1106 (Div. 2) Problem C
 * 
 * Time Complexity: O(N) - Linear scan to compute depths and max subtree depths.
 * Space Complexity: O(N) - Arrays for depths, max_depths, and child tracking.
 * 
 * Description:
 * Count the total number of distinct guilds in a rooted tree. Each node starts with a unique
 * guild of size 1. A parent node can form distinct guilds with its children depending on the
 * subtree depth combinations.
 *
 * Hint/Approach:
 * 1. Compute depths in a forward pass (since parent[i] < i).
 * 2. Compute max_depth for each subtree in a backward pass.
 * 3. For each parent, track the top 2 largest subtree depths among its children.
 * 4. The number of distinct multi-node guilds formed by parent i is (max2[i] - depth[i]) if a second child exists.
 * 5. Add this to the base guild count of n.
 */

#include <bits/stdc++.h>
using namespace std;

// CodeForces Round 1106 Div 2. Problem C.

// Section : Trees / DFS / Graph Algorithms
// Problem : Guilds in a Rooted Tree

class Solution {
public:
    long long countDistinctGuilds(int n, const vector<int>& parent) {
        vector<int> depth(n + 1, 0);
        vector<int> max_depth(n + 1, 0);

        // 1. Compute depths in a forward pass (since parent[i] < i)
        depth[1] = 0;
        for (int i = 2; i <= n; i++) {
            depth[i] = depth[parent[i]] + 1;
        }

        // 2. Compute max_depth for each subtree in a backward pass
        for (int i = 1; i <= n; i++) {
            max_depth[i] = depth[i];
        }
        for (int i = n; i >= 2; i--) {
            int p = parent[i];
            max_depth[p] = max(max_depth[p], max_depth[i]);
        }

        // 3. Find the top 2 largest max_depths among children for each parent
        vector<int> max1(n + 1, -1);
        vector<int> max2(n + 1, -1);
        for (int i = 2; i <= n; i++) {
            int p = parent[i];
            int d = max_depth[i];

            if (d > max1[p]) {
                max2[p] = max1[p];
                max1[p] = d;
            } else if (d > max2[p]) {
                max2[p] = d;
            }
        }

        // 4. Calculate total distinct guilds
        // Every vertex automatically creates at least 1 unique base guild (size 1)
        long long total_guilds = n; 
        for (int i = 1; i <= n; i++) {
            if (max2[i] != -1) {
                total_guilds += (max2[i] - depth[i]);
            }
        }

        return total_guilds;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;

        // Store parents directly in a flat vector
        vector<int> parent(n + 1);
        for (int i = 2; i <= n; i++) {
            cin >> parent[i];
        }

        Solution solver;
        cout << solver.countDistinctGuilds(n, parent) << "\n";
    }

    return 0;
}

/*
Input
5
5
1 2 3 4
3
1 1
7
1 2 1 3 5 5
10
1 1 3 2 2 4 4 4 3
15
1 2 1 3 3 4 3 7 3 10 6 7 1 9


Output
5
4
9
15
22
*/
