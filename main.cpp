#include <bits/stdc++.h>
using namespace std;

// Section : Stacks and Queues
// Problem : Implementing Queue using arrays

class MyQueue {
private:
    int* arr;
    int qFront;
    int qRear;
    int capacity;
    int count;

public:
    MyQueue(int capacity) {
        
    }

    void enqueue(int num) {
        
    }

    int dequeue() {
        
    }

    int getFront() {
        
    }

    bool empty() {
        
    }

    bool full() {
        
    }

    int size() {
        
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int capacity, q;
    while (cin >> capacity >> q) {
        MyQueue s(capacity);
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int num;
                cin >> num;
                s.enqueue(num);
            } else if (type == 2) {
                cout << s.dequeue() << "\n";
            } else if (type == 3) {
                cout << s.getFront() << "\n";
            } else if (type == 4) {
                cout << (s.empty() ? "true" : "false") << "\n";
            } else if (type == 5) {
                cout << (s.full() ? "true" : "false") << "\n";
            } else if (type == 6) {
                cout << s.size() << "\n";
            }
        }
    }

    return 0;
}