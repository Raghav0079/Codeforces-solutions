#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXV = 1000001;
bool isSquare[MAXV];
 
int main(){
    for(int k=1;(ll)k*k<MAXV;k++) isSquare[k*k]=true;
 
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;i++){
            int u,v; scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> parent(n+1,0), order; order.reserve(n);
        vector<int> sz(n+1,1);
        vector<char> visited(n+1,0);
        queue<int> q;
        q.push(1); visited[1]=1;
        while(!q.empty()){
            int u=q.front(); q.pop();
            order.push_back(u);
            for(int v: adj[u]) if(!visited[v]){
                visited[v]=1; parent[v]=u; q.push(v);
            }
        }
        for(int i=(int)order.size()-1;i>=0;i--){
            int u=order[i];
            if(parent[u]) sz[parent[u]] += sz[u];
        }
        ll ans=0;
        ll nn=n;
        for(int x=1;x<=n;x++){
            if(!isSquare[a[x]]) continue;
            ll sumSq=1, sumCube=1; // branch {x} itself
            for(int v: adj[x]) if(v!=parent[x]){
                ll s = sz[v];
                sumSq += s*s;
                sumCube += s*s*s;
            }
            ll out = nn - sz[x];
            sumSq += out*out;
            sumCube += out*out*out;
            ll e3 = (nn*nn*nn - 3*nn*sumSq + 2*sumCube)/6;
            ans += e3;
        }
        printf("%lld
", ans);
    }
}