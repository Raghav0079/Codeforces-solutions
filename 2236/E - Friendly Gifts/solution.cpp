#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    int max_L = 0;
 
    // We can iterate over all possible lengths L from n/2 down to 1
    // Optimization: If we find a valid solution for length L, 
    // since we want to maximize L, we can stop early if we check downwards.
    // However, checking all pairs of valid subsegments is cleaner:
    
    // valid_segments[L] will store pairs of {starting_index, min_value} for good subarrays of length L
    vector<vector<pair<int, int>>> valid_segments(n / 2 + 2);
 
    for (int i = 0; i < n; i++) {
        int min_val = a[i];
        int max_val = a[i];
        vector<bool> visited(n + 2, false);
        visited[a[i]] = true;
 
        for (int j = i; j < n; j++) {
            if (j > i) {
                if (visited[a[j]]) break; // Duplicate found, no longer good
                visited[a[j]] = true;
                min_val = min(min_val, a[j]);
                max_val = max(max_val, a[j]);
            }
 
            int len = j - i + 1;
            if (len > n / 2) break; // Elements cannot exceed n/2 to have two disjoint segments
 
            // Check condition 1: Elements form a contiguous permutation block
            if (max_val - min_val == len - 1) {
                valid_segments[len].push_back({i, min_val});
            }
        }
    }
 
    // Now process each length L to find two non-overlapping, value-contiguous segments
    for (int len = n / 2; len >= 1; len--) {
        if (valid_segments[len].empty()) continue;
 
        // Sort by starting index to handle overlap checks efficiently
        sort(valid_segments[len].begin(), valid_segments[len].end());
 
        int sz = valid_segments[len].size();
        bool found = false;
 
        for (int i = 0; i < sz; i++) {
            int i1 = valid_segments[len][i].first;
            int j1 = i1 + len - 1;
            int v1 = valid_segments[len][i].second;
 
            for (int j = i + 1; j < sz; j++) {
                int i2 = valid_segments[len][j].first;
                int v2 = valid_segments[len][j].second;
 
                // Check if they overlap in the array index space
                if (i2 <= j1) continue; 
 
                // Check if they are perfectly continuous in value space
                if (v2 == v1 + len || v1 == v2 + len) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
 
        if (found) {
            max_L = len;
            break; // Since we are traversing downwards, the first match is the maximum
        }
    }
 
    cout << max_L << "
";
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