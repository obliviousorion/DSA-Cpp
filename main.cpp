#include <bits/stdc++.h>
using namespace std;

// Section : Sliding Window and Two Pointers
// Problem : Stock span

class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    StockSpanner* obj = new StockSpanner();
    int price;
    while (cin >> price) {
        cout << obj->next(price) << " ";
    }
    cout << "\n";
    delete obj;

    return 0;
}