#include <iostream>
 
using namespace std;
 
void solve() {
    int x, y;
    cin >> x >> y;
    
    // If x is divisible by y, we can always reach y
    if (x % y == 0) {
        cout << "YES
";
    } else {
        cout << "NO
";
    }
}
 
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}