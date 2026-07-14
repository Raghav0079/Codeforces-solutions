#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        vector<long long> a(n);
        for(auto &x : a) scanf("%lld", &x);
 
        long long prev = 0;
        bool ok = true;
 
        for(int i = 0; i < n - 1; i++){
            long long need = prev + 1;
            if(a[i] < need){
                ok = false;
                break;
            }
            long long extra = a[i] - need;
            a[i+1] += extra;
            prev = need;
        }
 
        if(ok){
            if(a[n-1] <= prev) ok = false;
        }
 
        printf(ok ? "YES
" : "NO
");
    }
    return 0;
}