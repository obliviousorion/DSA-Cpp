/*
 * Problem : Count All Distinct Elements
 * Time Complexity : O(N)
 * Space Complexity : O(K) (to store elements currently inside the window)
 *
 * Description:
 * Given an array of integers nums and an integer k, find the number of 
 * distinct (unique) elements in every single contiguous window of size 
 * exactly k. Return a vector containing these counts.
 */

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> countDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq;
        int n = nums.size();
        vector<int> ans;

        // setup the first window
        for (int i = 0; i < k; i++) {
            num_freq[nums[i]]++;
        }
        ans.push_back(num_freq.size());
        
        // slide the window and record the count
        for (int j = k; j < n; j++) {
            num_freq[nums[j]]++;
            num_freq[nums[j - k]]--;
            if (num_freq[nums[j - k]] == 0) {
                num_freq.erase(nums[j - k]);
            }
            ans.push_back(num_freq.size());
        }
        return ans;
    }
};
