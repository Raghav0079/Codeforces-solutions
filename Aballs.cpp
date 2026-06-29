#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    // dp[i][j] will store the minimum operations to clear subarray c[i...j]
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base cases: 
    // - A single ball takes 1 operation to delete.
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    // Solve for all interval lengths from 2 up to n
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            
            // Initialize with the worst-case split
            dp[i][j] = len; 

            // Case 1: Try splitting the interval at every possible position k
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
            }

            // Case 2: If the endpoints match, they can destroy each other 
            // after the inside segment is completely cleared.
            if (c[i] == c[j]) {
                if (i + 1 <= j - 1) {
                    dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
                } else {
                    // This case handles len == 2 if adjacent elements could be equal,
                    // though the problem guarantees no two consecutive elements are equal.
                    dp[i][j] = min(dp[i][j], 0);
                }
            }
        }
    }

    // The answer for the full array
    cout << dp[0][n-1] << "\n";

    return 0;
}