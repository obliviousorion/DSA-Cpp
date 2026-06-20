/*
 * Problem: Implementing Queue using arrays
 * 
 * Description:
 * Implement a queue data structure using a fixed-capacity array. The queue should support the following operations:
 * - enqueue(num): Enqueue 'num' to the rear.
 * - dequeue(): Dequeue from the front and return it (or -1 if empty).
 * - getFront(): Return the front element (or -1 if empty).
 * - empty(): Return true if empty, otherwise false.
 * - full(): Return true if full, otherwise false.
 * - size(): Return the number of elements in the queue.
 * 
 * Complexity:
 * - Time Complexity: All operations (enqueue, dequeue, getFront, empty, full, size) run in O(1) constant time.
 * - Space Complexity: O(N) where N is the capacity of the queue, needed for the array storage.
 * 
 * Approaches:
 * 1. Circular Array Pointer (User's Solution):
 *    Tracks queue elements using front and rear pointers in a circular buffer with modular arithmetic `(index + 1) % capacity`.
 *    Keeps a size counter to easily track emptiness and fullness and avoid slot ambiguity.
 * 
 * 2. Standard Queue / Dynamic Array (Alternative):
 *    Using dynamic array/vector which shifting elements on dequeue (which takes O(N) time), or using a linked list (dynamic allocations).
 */

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
  int *arr;
  int qFront;
  int qRear;
  int capacity;
  int count;

public:
  MyQueue(int capacity) {
    this->capacity = capacity;
    this->qFront = 0;
    this->qRear = 0;
    this->count = 0;
    this->arr = new int[capacity];
  }

  // Destructor to prevent memory leaks
  ~MyQueue() { delete[] arr; }

  void enqueue(int num) {
    if (count == capacity) {
      return; // Queue is full
    }
    arr[qRear] = num;
    qRear = (qRear + 1) % capacity; // Perfect circular wrap-around
    count++;
  }

  int dequeue() {
    if (count == 0) {
      return -1; // Safely handle empty queue
    }

    int value = arr[qFront];
    arr[qFront] = 0;
    qFront = (qFront + 1) % capacity;
    count--;

    return value;
  }

  int getFront() {
    if (count == 0) {
      return -1; // Safely handle empty queue
    }
    return arr[qFront];
  }

  bool empty() { return count == 0; }

  bool full() { return count == capacity; }

  int size() { return count; }
};
