#include <bits/stdc++.h>
using namespace std;

// Section : Stacks and Queues
// Problem : Implement Stack using Queues

class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        
    }
    
    int pop() {
        
    }
    
    int top() {
        
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
        MyStack s;
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int x;
                cin >> x;
                s.push(x);
            } else if (type == 2) {
                cout << s.pop() << "\n";
            } else if (type == 3) {
                cout << s.top() << "\n";
            } else if (type == 4) {
                cout << (s.empty() ? "true" : "false") << "\n";
            }
        }
    }

    return 0;
}