#include <bits/stdc++.h>
using namespace std;

// Section : Linked List
// Problem : LRU Cache

class LRUCache {
public:
    LRUCache(int capacity) {
        // Initialize capacity and any supporting structures here
    }
    
    int get(int key) {
        // Return value of key if it exists, otherwise -1
        return -1;
    }
    
    void put(int key, int value) {
        // Insert or update key-value pair, evicting LRU if capacity is exceeded
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int capacity;
    if (!(cin >> capacity)) return 0;
    
    LRUCache* lru = new LRUCache(capacity);
    
    string op;
    while (cin >> op) {
        if (op == "put") {
            int key, value;
            cin >> key >> value;
            lru->put(key, value);
        } else if (op == "get") {
            int key;
            cin >> key;
            cout << lru->get(key) << "\n";
        }
    }
    
    delete lru;
    return 0;
}