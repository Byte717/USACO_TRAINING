#include <bits/stdc++.h>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("pi.in","r",stdin);
    string pi = "3141592653589793238462643383279";
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int ans = 0; 
        for(int i = 0; i < s.length();i++){
            if(s[i] == pi[i]){
                ans++;
                continue;
            }else{
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}