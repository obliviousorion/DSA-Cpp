/*
 * Problem: Remove K Digits
 * Section: Stacks and Queues
 *
 * Description:
 * Given string num representing a non-negative integer num, and an integer k,
 * return the smallest possible integer after removing k digits from num.
 * The relative order of the remaining digits must be preserved.
 *
 * ==========================================
 * DETAILED BREAKDOWN OF APPROACHES
 * ==========================================
 *
 * Greedy Monotonic Stack Approach (Implemented)
 * ---------------------------------------------
 * - Intuition:
 *   To minimize the value of the final number, we want the most significant digits
 *   (the leftmost digits) to be as small as possible. Therefore, we should greedily
 *   remove any peak element (a digit larger than its succeeding digit) from left to right.
 * 
 * - Implementation Details:
 *   - Stack representation: We use `std::string` as a stack directly so we can easily return it
 *     and perform `pop_back()` and `push_back()` efficiently.
 *   - For each digit `c` in `num`:
 *     - While the stack is not empty, the top of the stack is strictly greater than `c`, and we
 *       still have removals left (`k > 0`), we pop elements from the stack.
 *     - Push `c` onto the stack.
 * 
 * - Edge Cases Handled:
 *   1. Removals remaining: If the digits are in non-decreasing order (e.g., "1234") and `k > 0`
 *      after the loop, we pop the remaining `k` largest digits from the end of the stack.
 *   2. Leading Zeros: We strip out any leading zeros from the resulting string.
 *   3. Empty String: If the resulting string is empty (e.g., all digits were removed), we return "0".
 *
 * Time Complexity: O(N) — each digit is pushed and popped at most once.
 * Space Complexity: O(N) — space to store the resulting string.
 */

#include <bits/stdc++.h>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string answer = "";
        
        for (char c : num) {
            // Greedily remove larger preceding digits to keep significant digits small
            while (!answer.empty() && answer.back() > c && k > 0) {
                answer.pop_back();
                k--;
            }
            answer.push_back(c);
        }

        // Edge case: if we still have removals remaining (non-decreasing sequence)
        while (k > 0 && !answer.empty()) {
            answer.pop_back();
            k--;
        }

        // Edge case: handle leading zeros
        int idx = 0;
        while (!answer.empty() && idx < answer.size() && answer[idx] == '0') {
            idx++;
        }
        answer = answer.substr(idx);

        return answer.empty() ? "0" : answer;
    }
};
