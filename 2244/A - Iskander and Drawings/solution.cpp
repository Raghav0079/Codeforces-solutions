#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        char buf[15];
        scanf("%s", buf);
        string s(buf);
 
        int ans = 0;
        int i = 0;
        while(i < n){
            if(s[i] == '#'){
                int j = i;
                while(j < n && s[j] == '#') j++;
                int len = j - i;
                int time = (len + 1) / 2;
                ans = max(ans, time);
                i = j;
            } else {
                i++;
            }
        }
 
        printf("%d
", ans);
    }
    return 0;
}