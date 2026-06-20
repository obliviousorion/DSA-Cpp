#include <bits/stdc++.h>
using namespace std;

/*
 * Problem : Monkey Eats Banana (Koko Eating Bananas)
 * Description : Find the minimum integer eating speed K (bananas per hour) such
 * that all piles of bananas can be eaten within H hours. Approach : Binary
 * search on the answer in the range [1, max(piles)]. For each mid speed, check
 * the total hours required to finish all piles. Time Complexity : O(N * log(M))
 * where N is the number of piles and M is the maximum bananas in a pile. Space
 * Complexity : O(1)
 */

class Solution {
public:
  // Pass 'n' explicitly since raw arrays don't track their own size
  int findMax(int arr[], int n) {
    int maxm = INT_MIN;
    for (int i = 0; i < n; i++) {
      if (arr[i] > maxm) {
        maxm = arr[i];
      }
    }
    return maxm;
  }

  // Changed return type to long long to insulate against overflow
  long long calculate_total_hours(int arr[], int n, int hourlyRate) {
    long long totalHours = 0;
    for (int i = 0; i < n; i++) {
      // Using integer arithmetic for ceil avoids floating-point precision
      // issues: ceil(a / b) is equivalent to (a + b - 1) / b
      totalHours += ((long long)arr[i] + hourlyRate - 1) / hourlyRate;
    }
    return totalHours;
  }

  int minimum_rate_to_eat_bananas(int arr[], int n, int h) {
    int low = 1;
    int high = findMax(arr, n); // Passed n correctly

    while (low <= high) {
      int mid = low + (high - low) / 2;
      long long totalHours = calculate_total_hours(arr, n, mid);

      if (totalHours <= h) {
        high = mid - 1; // Rate is valid, try to find a smaller one
      } else {
        low = mid + 1; // Too slow, must speed up
      }
    }
    return low; // low naturally converges to the optimal answer
  }
};
