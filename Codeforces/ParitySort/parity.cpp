#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


void solve(){
    int n; cin >> n;
    vector<int> even, odd, evenIdx, oddIdx;
    for(int i = 0; i < n;i++){
        int x; cin >> x;
        if(x %2 == 0){
            even.push_back(x);
            evenIdx.push_back(i);
        }else{
            odd.push_back(x);
            oddIdx.push_back(i);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    vector<int> ans(n);
    for(int i = 0; i < even.size();i++){
        ans[evenIdx[i]] = even[i];
    }
    for(int i = 0; i < odd.size();i++){
        ans[oddIdx[i]] = odd[i];
    }
    bool works = true;
    for(int i = 1; i < n;i++){
        if(ans[i] < ans[i-1]){
            works = false;
            break;
        }
    }
    cout << ((works) ? "YES" : "NO") << endl;
}

int main(){
    // freopen("parity.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}