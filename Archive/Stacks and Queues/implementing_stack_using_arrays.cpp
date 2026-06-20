/*
 * Problem: Implementing Stack using arrays
 * 
 * Description:
 * Implement a stack data structure using a fixed-capacity array. The stack should support the following operations:
 * - push(num): Push 'num' onto the stack.
 * - pop(): Pop the top element and return it (or -1 if empty).
 * - topElement(): Return the top element (or -1 if empty).
 * - empty(): Return true if the stack is empty, otherwise false.
 * - full(): Return true if the stack is full, otherwise false.
 * - size(): Return the number of elements in the stack.
 * 
 * Complexity:
 * - Time Complexity: All operations (push, pop, topElement, empty, full, size) run in O(1) constant time.
 * - Space Complexity: O(N) where N is the capacity of the stack, needed for the array storage.
 * 
 * Approaches:
 * 1. Fixed-Size Array Pointer (User's Solution):
 *    Tracks stack elements in a dynamically allocated array using a pointer `top` representing the top element index.
 *    Extremely efficient since all operations are direct index operations.
 * 
 * 2. std::vector / Dynamic Array (Alternative):
 *    Uses a dynamic array (like std::vector) which allows the stack to grow dynamically, avoiding the Stack Overflow condition.
 *    amortized O(1) push operations.
 */

#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
    int top;
    int capacity;
    int* arr;
public:
    MyStack(int capacity) {
        this->capacity = capacity;
        this->top = -1;                 // -1 means the stack is completely empty
        this->arr = new int[capacity];
    }

    // Destructor to clean up dynamically allocated memory
    ~MyStack() {
        delete[] arr;
    }

    void push(int num) {
        if (top < capacity - 1) {       // Check if there is still room left
            arr[++top] = num;           // Pre-increment: Move top up to the next index, then insert
        }
    }

    int pop() {
        if (top != -1) {                // Check if the stack is not empty
            return arr[top--];          // Post-decrement: Return the value at top, then move top down
        } 
        return -1;                      // Return -1 if nothing is there to pop
    }

    int topElement() {
        if (top != -1) {
            return arr[top];            // top points directly to the actual top element
        }
        return -1;
    }

    bool empty() {
        return top == -1;
    }

    bool full() {
        return top == capacity - 1;     // If capacity is 5, it's full when top reaches index 4
    }

    int size() {
        return top + 1;                 // Since indices start at 0, size is always top + 1
    }
};
