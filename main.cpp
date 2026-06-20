#include <bits/stdc++.h>
using namespace std;

// Section : Stacks and Queues
// Problem : Learn stack

class MyStack {
private:
    int arr[1000];
    int top;
public:
    MyStack() {
        top = -1;
    }
    
    void push(int x) {
        // Write push logic here
        
    }
    
    int pop() {
        // Write pop logic here
        
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
                cout << s.pop() << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}