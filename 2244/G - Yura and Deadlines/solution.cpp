#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        vector<long long> a(n+1);
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
        }
 
        // Fenwick tree for prefix maximum (1-indexed)
        vector<long long> fen(n+2, 0);
        auto update = [&](int pos, long long val){
            for(; pos <= n; pos += pos & (-pos)){
                fen[pos] = max(fen[pos], val);
            }
        };
        auto query = [&](int pos) -> long long {
            long long res = 0;
            for(; pos > 0; pos -= pos & (-pos)){
                res = max(res, fen[pos]);
            }
            return res;
        };
 
        // events[T] = list of indices that become active at time T
        vector<vector<int>> events(n + 2);
 
        vector<long long> dp(n+1, 0);
        long long answer = 0;
 
        for(int i = 1; i <= n; i++){
            // Activate all assignments scheduled to become active at time i
            for(int p : events[i]){
                update(p, dp[p]);
            }
 
            // Compute L = i - a_i - 1
            long long Lraw = (long long)i - a[i] - 1;
            long long best = 0;
            if(Lraw >= 1){
                int L = (Lraw > n) ? n : (int)Lraw; // Lraw < i <= n always, so this is safe
                best = query(L);
            }
            // if Lraw < 1, best stays 0 (no valid previous element; subset {i} alone)
 
            dp[i] = best + a[i];
            answer = max(answer, dp[i]);
 
            // Schedule activation time for i: T = i + a_i + 1
            long long tRaw = (long long)i + a[i] + 1;
            if(tRaw <= n){
                events[(int)tRaw].push_back(i);
            }
            // if tRaw > n, this assignment never becomes usable as a "previous" element
            // within the array bounds, so simply skip scheduling it.
        }
 
        printf("%lld
", answer);
    }
    return 0;
}