#include <bits/stdc++.h>
using namespace std;

// Section : Stacks and Queues
// Problem : Implement Queue using Stacks

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        
    }
    
    int pop() {
        
    }
    
    int peek() {
        
    }
    
    bool empty() {
        
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    while (cin >> q) {
        MyQueue que;
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int x;
                cin >> x;
                que.push(x);
            } else if (type == 2) {
                cout << que.pop() << "\n";
            } else if (type == 3) {
                cout << que.peek() << "\n";
            } else if (type == 4) {
                cout << (que.empty() ? "true" : "false") << "\n";
            }
        }
    }

    return 0;
}