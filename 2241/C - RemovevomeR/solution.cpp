#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    int transitions = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != s[i + 1]) {
            transitions++;
        }
    }
 
    if (transitions == 1) {
        cout << 2 << "
";
    } else {
        cout << 1 << "
";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}