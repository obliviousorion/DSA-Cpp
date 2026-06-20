/*
 * Problem: Sort Characters by Frequency
 * 
 * Description:
 * Given a string s, sort it in descending order based on the frequency of the characters.
 * The frequency of a character is the number of times it appears in the string.
 * Return the sorted string. If there are multiple answers, return any of them.
 * 
 * Complexity:
 * - Time Complexity:
 *   1. Suboptimal (frequencySort): O(N log K) or O(N log N) where N is the length of string s and K is the number of unique characters.
 *      Counting takes O(N). Sorting vector of size K takes O(K log K) where K <= 256.
 *   2. Optimal (optimalFrequencySort): O(N) using Bucket Sort.
 *      Counting frequencies takes O(N). Creating buckets takes O(K) where K = 256.
 *      Rebuilding the string takes O(N) since the sum of frequencies equals N.
 * - Space Complexity:
 *   1. Suboptimal (frequencySort): O(K) where K is the number of unique characters for the frequency map and vector.
 *   2. Optimal (optimalFrequencySort): O(N + K) to store the buckets array and the frequency array.
 * 
 * Approaches:
 * 1. Map & Sort (frequencySort - Suboptimal):
 *    Count character frequencies using an unordered_map. Move the key-value pairs to a vector of pairs,
 *    and sort the vector in descending order of frequency. Reconstruct the string.
 * 
 * 2. Bucket Sort (optimalFrequencySort - Most Optimal):
 *    Count frequencies using a fixed-size frequency array. Use an array of buckets where the index represents frequency.
 *    Place characters in their respective frequency buckets. Reconstruct the string by iterating through the buckets
 *    from highest frequency down to 1.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // this method is not the most optimal but suboptimal
    string frequencySort(string s) {
        // 1. Count character frequencies
        unordered_map<char, int> char_count;
        for (char c : s) {
            char_count[c]++;
        }
        
        // 2. Move data to a vector of pairs so we can sort it
        vector<pair<char, int>> freq_vec(char_count.begin(), char_count.end());
        
        // 3. Sort the vector in descending order based on frequency
        sort(freq_vec.begin(), freq_vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second; 
        });
        
        // 4. Build the final sorted string
        string result = "";
        for (auto& p : freq_vec) {
            // string::append(count, char) adds the character 'count' times
            result.append(p.second, p.first); 
        }
        
        return result;
    }

    string optimalFrequencySort(string s) {
        int n = s.size();
        
        // 1. Count frequencies using a fast flat array
        int char_count[256] = {0};
        for (char c : s) {
            char_count[c]++;
        }
        
        // 2. Create buckets. The index represents the frequency.
        // We need n + 1 buckets to account for frequency ranging from 0 to n.
        vector<vector<char>> buckets(n + 1);
        
        // Put characters into their respective frequency buckets
        for (int i = 0; i < 256; i++) {
            if (char_count[i] > 0) {
                buckets[char_count[i]].push_back((char)i);
            }
        }
        
        // 3. Build the result by reading buckets from right to left (highest frequency first)
        string result = "";
        for (int freq = n; freq > 0; freq--) {
            // If the bucket isn't empty, append the characters
            for (char c : buckets[freq]) {
                result.append(freq, c);
            }
        }
        
        return result;
    }
};
