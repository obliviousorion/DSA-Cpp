/*
 * Problem: Asteroid Collision
 * Section: Stacks and Queues
 *
 * Description:
 * You are given an array asteroids of integers representing asteroids in a row.
 * For each asteroid, the absolute value represents its size, and the sign represents
 * its direction (positive = right, negative = left). Each asteroid moves at the same speed.
 * Find out the state of the asteroids after all collisions.
 *
 * ==========================================
 * DETAILED BREAKDOWN OF APPROACHES
 * ==========================================
 *
 * Stack-Based Simulation (Implemented)
 * ------------------------------------
 * - Intuition:
 *   As we traverse the asteroids, we push right-moving asteroids (+ve) onto the stack.
 *   When we encounter a left-moving asteroid (-ve), it will collide with any right-moving
 *   asteroids currently on the top of the stack.
 * 
 * - Implementation Details:
 *   - Vector as a Stack: Using a `std::vector` as a stack is highly efficient as it allows
 *     direct dynamic resizing and avoids extra copying when returning the final result.
 *   - Positive Asteroid: Simply push to the stack.
 *   - Negative Asteroid Block: Keep popping smaller positive asteroids from the stack
 *     (`st.back() < abs(asteroid)`) because they explode.
 *     - If the top asteroid is of equal size (`st.back() == abs(asteroid)`), both explode
 *       (pop the stack and drop the current asteroid).
 *     - If the stack becomes empty or the top asteroid is also moving left (negative),
 *       the current negative asteroid survives and is pushed.
 *     - If the top asteroid is larger (`st.back() > abs(asteroid)`), the current negative
 *       asteroid explodes and is dropped.
 *
 * Time Complexity: O(N) — each asteroid is pushed and popped at most once.
 * Space Complexity: O(N) — auxiliary stack space for the result.
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // Using a vector as a stack is perfectly efficient
        int n = asteroids.size();
        
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            } else {
                // Keep popping all smaller positive asteroids moving right
                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                    st.pop_back();
                }
                
                // These checks must live completely inside the negative asteroid block!
                if (!st.empty() && st.back() == abs(asteroids[i])) {
                    st.pop_back(); // Both explode
                } else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]); // Current negative asteroid survives
                }
                // If st.back() > abs(asteroids[i]), the current negative asteroid explodes 
                // and we simply do nothing (implicitly dropping it).
            }
        }
        return st;
    }
};
