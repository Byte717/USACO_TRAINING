#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;


void solve(){
    string s; cin >> s;
    vector<int> password;    for(int i = 0; i < s.length();i++){
        password.push_back(int(s[i])-48);
    }
    int n = password.size();
    int len; cin >> len;
    string L, R; cin >> L >> R;
    vector<int> l, r;
    for(int i = 0; i < L.length();i++){
        l.push_back(int(L[i])-48);
        r.push_back(int(R[i])-48);
    }
    // int idx = 0;
    // int rightMost = 0;
    // while(idx < len){ // for each char of the password


    //     int currentRightMost = -1;

    //     for(int i = l[idx]; i <= r[idx];i++){
    //         int found = -1;
    //         for(int j = rightMost; j < n;j++){
    //             if(password[j] == i){
    //                 found = j;
    //             }
    //         }
    //         if(found == -1){
    //             cout << "YES" << endl;
    //             return;
    //         }else{
    //             currentRightMost = max(currentRightMost, found);
    //         }
    //     }

    //     rightMost = max(currentRightMost,rightMost);


    //     idx++;
    // }
    int rightMost = 0;
    for(int i = 0; i < len;i++){
        int newRight = rightMost;
        for(int j = l[i]; j <= r[i];j++){
            int curr = rightMost;
            while(curr < n && password[curr] != j){
                curr++;
            }
            newRight = max(newRight,curr);
        }
        rightMost = newRight + 1;
    }
    cout << ((rightMost > n) ? "YES":"NO") << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("password.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}