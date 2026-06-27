#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: Fruits and Basket
 * 
 * Description:
 * You are visiting a farm where fruit trees are planted in a single row from left to right.
 * The types of fruit produced by each tree are represented by an integer array tree,
 * where tree[i] indicates the type of fruit produced by the tree at position i.
 * Find the maximum number of fruits you can gather such that you can collect at most
 * two types of fruits using two baskets.
 * 
 * Constraints:
 * 1 <= tree.length <= 10^5
 * 0 <= tree[i] < tree.length
 * 
 * Approach:
 * Sliding window technique (variable size). Maintain a window [left, right] that represents
 * the trees we are picking fruits from. We use an unordered_map (basket) to store the fruit 
 * types and their counts in the current window.
 * - Expand the window by adding tree[right] to the map.
 * - If the map size exceeds 2, it means we have 3 types of fruits in our window. Shrink the window 
 *   from the left by decrementing the count of tree[left] and erasing it if its count hits 0. 
 *   Increment left.
 * - Record the maximum window size at each valid step.
 * 
 * Time Complexity: O(N) where N is the length of the tree array.
 * Space Complexity: O(1) auxiliary space (the map stores at most 3 distinct keys).
 */

class Solution {
public:
  int fruitsBaskets(vector<int> &tree) {
    unordered_map<int, int> basket;
    int left = 0, maxFruits = 0;

    for (int right = 0; right < tree.size(); ++right) {
      // Add current fruit to the basket
      basket[tree[right]]++;

      // If we have more than 2 types, shrink the window from the left
      while (basket.size() > 2) {
        basket[tree[left]]--;
        if (basket[tree[left]] == 0) {
          basket.erase(tree[left]);
        }
        left++;
      }

      // Update the maximum window size found so far
      maxFruits = max(maxFruits, right - left + 1);
    }

    return maxFruits;
  }
};
