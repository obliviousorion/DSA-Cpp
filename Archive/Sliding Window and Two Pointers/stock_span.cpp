#include <bits/stdc++.h>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

/*
 * Problem: Stock Span
 * 
 * Description:
 * The stock span problem is a financial problem where we need to calculate the span of stock’s price 
 * for all n days. The span of the stock’s price in one day is defined as the maximum number of 
 * consecutive days (starting from today and going backward) that the stock price was less than or 
 * equal to its price on the current day.
 * 
 * Approach:
 * 1. Online queries (next): Maintain a monotonic stack storing pairs of {price, span}.
 * 2. Offline arrays (getSpans): Similar to online, using a vector as a stack.
 * 3. Offline arrays with indices (getSpans2): Store index in stack. The span of current day is:
 *    - (i + 1) if stack is empty (meaning all previous days had lesser/equal prices).
 *    - (i - stack.top()) if stack is not empty (stack top is index of first day with strictly greater price).
 * 
 * Time Complexity:
 * - next(): O(1) amortized. Each price is pushed and popped at most once.
 * - getSpans() / getSpans2(): O(N) overall where N is the array size.
 * 
 * Space Complexity:
 * - O(N) to store elements/indices in stack/vector.
 */

class StockSpanner {
private:   
    stack<pair<int, int>> s;

public:
    StockSpanner() {}

    // Approach 1: Online queries (This part was already perfect!)
    int next(int price) {
        int span = 1;
        // Pop elements while stack is not empty and top price is less than or equal to current price
        while (!s.empty() && s.top().first <= price) {
            span += s.top().second;
            s.pop();
        }
        s.push({price, span});
        return span;        
    }

    // Approach 2: Offline array processing using pairs
    vector<int> getSpans(int prices[], int m) {
        vector<int> ans(m);
        vector<pair<int, int>> st; // Monotonic stack of {price, span}

        for(int i = 0; i < m; i++) {
            int span = 1;
            while (!st.empty() && st.back().first <= prices[i]) {
                span += st.back().second;
                st.pop_back();
            }
            st.push_back({prices[i], span});
            ans[i] = span;
        }

        return ans;
    }

    // Approach 3: Offline array processing storing indices (Most elegant)
    vector<int> getSpans2(int prices[], int m) {
        vector<int> ans(m);
        vector<int> st; // Monotonic stack of indices

        for (int i = 0; i < m; i++) {
            // Maintain decreasing order of prices in stack
            while (!st.empty() && prices[st.back()] <= prices[i]) {
                st.pop_back();
            }
            // If stack is empty, all elements to the left are smaller/equal. Otherwise, boundary is st.back()
            ans[i] = st.empty() ? (i + 1) : (i - st.back());
            st.push_back(i);
        }

        return ans;
    }
};
