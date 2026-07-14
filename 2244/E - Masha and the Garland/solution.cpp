#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, q;
        scanf("%d %d", &n, &q);
        char buf[200005];
        scanf("%s", buf + 1); // store 1-indexed
 
        // badA[i]: mismatch with pattern starting '0' at position1
        // expectedA(i) = '0' if (i-1)%2==0 else '1'  (i is 1-indexed)
        vector<int> badA(n+1, 0), badB(n+1, 0);
        for(int i = 1; i <= n; i++){
            char expectedA = ((i-1) % 2 == 0) ? '0' : '1';
            badA[i] = (buf[i] != expectedA) ? 1 : 0;
            badB[i] = 1 - badA[i]; // complementary pattern
        }
 
        // prefix sum of "block starts" for A and B
        vector<int> prefA(n+1, 0), prefB(n+1, 0);
        for(int i = 1; i <= n; i++){
            int startA = (badA[i] == 1 && (i == 1 || badA[i-1] == 0)) ? 1 : 0;
            int startB = (badB[i] == 1 && (i == 1 || badB[i-1] == 0)) ? 1 : 0;
            prefA[i] = prefA[i-1] + startA;
            prefB[i] = prefB[i-1] + startB;
        }
 
        while(q--){
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
 
            long long blocksA = (long long)(prefA[r] - prefA[l-1]);
            if(badA[l] == 1 && l > 1 && badA[l-1] == 1) blocksA += 1;
 
            long long blocksB = (long long)(prefB[r] - prefB[l-1]);
            if(badB[l] == 1 && l > 1 && badB[l-1] == 1) blocksB += 1;
 
            long long need = min(blocksA, blocksB);
 
            if(need <= k) printf("YES
");
            else printf("NO
");
        }
    }
    return 0;
}