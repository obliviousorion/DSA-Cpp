/*
 * Problem: Sum of Subarray Minimums
 * Section: Stacks and Queues
 *
 * Description:
 * Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
 * Since the answer may be large, return the answer modulo 10^9 + 7.
 *
 * ==========================================
 * DETAILED BREAKDOWN OF APPROACHES
 * ==========================================
 *
 * Approach 1: Brute Force Method
 * ------------------------------
 * - Intuition: Generate every possible subarray, compute its minimum, and add it to the running sum.
 * - Implementation: 
 *   - Outer loop controls the start index `i` of the subarray.
 *   - Inner loop expands the subarray to end index `j`, updating a running minimum `mini` along the way.
 *   - Modulo arithmetic is applied at each step to prevent overflow.
 * - Time Complexity: O(N^2)
 * - Space Complexity: O(1)
 *
 * Approach 2: Monotonic Stack (Optimal Method)
 * --------------------------------------------
 * - Intuition:
 *   Instead of iterating over subarrays, compute the contribution of each element arr[i] as the minimum.
 *   For each element arr[i], find:
 *     1. Previous Smaller Element (PSE): The index of the first smaller element to its left.
 *     2. Next Smaller Element (NSE): The index of the first smaller element to its right.
 *   The element arr[i] acts as the minimum for all subarrays starting between (PSE, i] and ending between [i, NSE).
 *   Number of such subarrays is: left_count * right_count = (i - PSE) * (NSE - i).
 *   Total contribution of arr[i] is: arr[i] * (i - PSE) * (NSE - i) % MOD.
 *
 * - Handling Duplicates & Edge Cases:
 *   If duplicates exist in the array (e.g., [2, 2]), we might double-count subarrays containing both duplicates.
 *   To solve this, we define:
 *     - NSE as the next strictly smaller element (use `>=` in comparison to pop equal or larger elements).
 *     - PSEE (Previous Smaller or Equal Element) as the previous smaller or equal element (use `>` in comparison to pop strictly larger elements).
 *   Using >= in one boundary search and > in the other defines a unique, non-overlapping range for duplicates,
 *   serving as an elite-level solution to prevent double-counting.
 *
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Brute Force Method
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;
        int MOD = 1e9 + 7;
        for(int i = 0; i < n; i++) {
            int mini = arr[i];
            for(int j = i; j < n; j++) {
                mini = min(mini, arr[j]);
                total = (total + mini) % MOD;
            }
        }
        return total;
    }

    // Approach 2: Monotonic Stack (Optimal Method)
    
    // Finds Next Smaller Element (NSE) index for each element
    // Uses >= to ensure elements equal to arr[i] on the right are excluded from its range
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    // Finds Previous Smaller or Equal Element (PSEE) index for each element
    // Uses > to ensure elements equal to arr[i] on the left are included in its range
    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    int sumSubarrayMins2(vector<int>& arr){
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);
        int n = arr.size();
        long long total = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            long long ways = (left * right) % mod;
            long long contribution = (ways * arr[i]) % mod;
            total = (total + contribution) % mod;
        }
        return (int) total;
    }
};
