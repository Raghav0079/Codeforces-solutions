#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        string s;
        cin >> n >> s;
 
        int left = 0, right = n - 1;
        while(left < n && s[left] == '0') left++;
        while(right >= 0 && s[right] == '1') right--;
 
        if(left > right){
            // string was already sorted (0...01...1 form fully) 
            cout << "Bob
";
            continue;
        }
 
        bool aliceWins = false;
        int count = 1;
        for(int i = left; i < right; i++){
            if(s[i+1] == s[i]) count++;
            else{
                if(count % 2 == 1) aliceWins = true;
                count = 1;
            }
        }
        if(count % 2 == 1) aliceWins = true;
 
        cout << (aliceWins ? "Alice
" : "Bob
");
    }
    return 0;
}