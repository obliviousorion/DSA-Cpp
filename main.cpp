#include <bits/stdc++.h>
using namespace std;

// Section : Stacks and Queues
// Problem : Implement Min Stack

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        
    }
    
    void pop() {
        
    }
    
    int top() {
        
    }
    
    int getMin() {
        
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    while (cin >> q) {
        MinStack s;
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int x;
                cin >> x;
                s.push(x);
            } else if (type == 2) {
                s.pop();
            } else if (type == 3) {
                cout << s.top() << "\n";
            } else if (type == 4) {
                cout << s.getMin() << "\n";
            }
        }
    }

    return 0;
}