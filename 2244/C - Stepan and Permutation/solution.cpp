#include <bits/stdc++.h>
using namespace std;
 
struct DSU {
    vector<int> par, rnk;
    void init(int n){
        par.resize(n+1);
        rnk.assign(n+1, 0);
        for(int i = 0; i <= n; i++) par[i] = i;
    }
    int find(int u){
        while(par[u] != u){
            par[u] = par[par[u]];
            u = par[u];
        }
        return u;
    }
    void unite(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return;
        if(rnk[u] < rnk[v]) swap(u, v);
        par[v] = u;
        if(rnk[u] == rnk[v]) rnk[u]++;
    }
};
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, x, y;
        scanf("%d %d %d", &n, &x, &y);
        vector<int> p(n+1);
        for(int i = 1; i <= n; i++){
            scanf("%d", &p[i]);
        }
 
        DSU dsu;
        dsu.init(n);
 
        for(int i = 1; i <= n; i++){
            if(i + x <= n) dsu.unite(i, i + x);
            if(i + y <= n) dsu.unite(i, i + y);
        }
 
        bool ok = true;
        for(int i = 1; i <= n; i++){
            if(dsu.find(i) != dsu.find(p[i])){
                ok = false;
                break;
            }
        }
 
        printf(ok ? "YES
" : "NO
");
    }
    return 0;
}