#include <bits/stdc++.h>
using namespace std;

// Implement your game logic inside this function
bool canEgorWin(int n, int k, vector<int>& a) {
    // ----------------------------------------------------
    // YOUR CODE HERE
    // Return true if Egor can be guaranteed a win ("YES")
    // Return false otherwise ("NO")
    // ----------------------------------------------------
    
        
    return false; // Placeholder
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    if (canEgorWin(n, k, a)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}