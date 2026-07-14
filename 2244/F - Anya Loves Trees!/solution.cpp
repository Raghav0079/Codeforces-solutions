#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        vector<int> par(n+1, 0);
        for(int i = 2; i <= n; i++){
            scanf("%d", &par[i]);
        }
        vector<int> a(n+1);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
 
        vector<vector<int>> children(n+1);
        for(int i = 2; i <= n; i++){
            children[par[i]].push_back(i);
        }
 
        // BFS order from root (guarantees parents appear before children)
        vector<int> order;
        order.reserve(n);
        {
            vector<int> q;
            q.reserve(n);
            q.push_back(1);
            size_t head = 0;
            while(head < q.size()){
                int u = q[head++];
                order.push_back(u);
                for(int c : children[u]) q.push_back(c);
            }
        }
 
        vector<int> mn(n+1), mx(n+1);
        vector<char> feasible(n+1, 1);
 
        // Process bottom-up: reverse of BFS order
        for(int idx = (int)order.size() - 1; idx >= 0; idx--){
            int u = order[idx];
            if(children[u].empty()){
                // Leaf node
                mn[u] = mx[u] = a[u];
                feasible[u] = 1;
            } else {
                int m = (int)children[u].size();
                bool ok = true;
                for(int c : children[u]){
                    if(!feasible[c]){ ok = false; break; }
                }
                if(!ok){
                    feasible[u] = 0;
                } else if(m == 1){
                    int c = children[u][0];
                    mn[u] = mn[c];
                    mx[u] = mx[c];
                    feasible[u] = 1;
                } else {
                    int badCount = 0;
                    for(int j = 0; j < m; j++){
                        int c1 = children[u][j];
                        int c2 = children[u][(j+1) % m];
                        if(!(mx[c1] < mn[c2])) badCount++;
                    }
                    if(badCount > 1){
                        feasible[u] = 0;
                    } else {
                        feasible[u] = 1;
                        int minv = INT_MAX, maxv = INT_MIN;
                        for(int c : children[u]){
                            minv = min(minv, mn[c]);
                            maxv = max(maxv, mx[c]);
                        }
                        mn[u] = minv;
                        mx[u] = maxv;
                    }
                }
            }
        }
 
        printf(feasible[1] ? "YES
" : "NO
");
    }
    return 0;
}