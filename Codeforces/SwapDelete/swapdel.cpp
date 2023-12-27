#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("del.in","r",stdin);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        vector<int> cnt(2);
        for(char &i : s){
            if(s[i] == '0'){
                cnt[0]++;
            }else{
                cnt[1]++;
            }
        }

        for(int i = 0; i < s.length()+1;i++){
            if(i == s.length() || cnt[1-(s[i]-'0')] == 0){
                cout << s.length() - i << endl;
                break;
            }
            cnt[1-(s[i]-'0')]++;
        }
        // if(s.length() == 1){
        //     cout << 1 << endl;
        //     continue;
        // }
        // int n = s.length();

        // vector<vector<int>> pref(2, vector<int>(n+1, 0));
        // for(int i = 0; i < n;i++){
        //     pref[0][i+1] = pref[0][i] + (s[i] == '0' ? 1:0);
        //     pref[1][i+1] = pref[1][i] + (s[i] == '1' ? 1:0);
        // }

        // int pt = n;
        // int ans = 0;
        // while(pt > 1){
        //     if(pref[0][pt] == pref[1][pt]){
        //         break;
        //     }
        //     pt--;
        //     ans++;
        // }
        // cout << ans << endl;

    }
    return 0;
}