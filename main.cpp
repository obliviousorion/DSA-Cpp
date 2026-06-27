#include <bits/stdc++.h>
using namespace std;

// Section : Sliding Window and Two Pointers
// Problem : Fruits and Basket

/*
Problem Statement:
You are visiting a farm where fruit trees are planted in a single row from left to right. 
The types of fruit produced by each tree are represented by an integer array tree, 
where tree[i] indicates the type of fruit produced by the tree at position i.

You want to gather as many fruits as possible, but there are specific rules you need to follow:
- You have two baskets, and each basket can only hold fruits of one type. There's no 
  restriction on how many fruits of a given type a basket can carry.
- Starting from any tree, you must pick one fruit from every tree as you move to the right, 
  and all the collected fruits must fit into one of the two baskets.
- You must stop collecting as soon as you encounter a tree that produces a fruit type that 
  doesn't fit into either of your baskets.

Given the integer array tree, return the maximum number of fruits you can gather.

Constraints:
1 <= tree.length <= 10^5
0 <= tree[i] < tree.length

Time Complexity Goal: O(N)
Auxiliary Space Complexity Goal: O(1)

Examples:
1. Input: tree = [3, 1, 3]
   Output: 3
   Explanation: You can pick from all three trees as they all fit into the two baskets 
   (both baskets can hold type 3 and type 1 fruits).

2. Input: tree = [4, 2, 3, 3]
   Output: 3
   Explanation: You can collect from trees [2, 3, 3] (types 2 and 3). 
   Starting at tree 0 (type 4) would allow you to pick only from trees 0 and 1 (types 4 and 2).
*/

class Solution {
public:
    int fruitsBaskets(vector<int>& tree) {
        // Write solution logic here
        return 0;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> tree(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }

    Solution solver;
    cout << solver.fruitsBaskets(tree) << "\n";

    return 0;
}