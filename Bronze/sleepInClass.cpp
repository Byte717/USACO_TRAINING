#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    int N; cin >> N; 
    vector<ll> arr(N);
    ll sum = 0;
    for(int i = 0; i < N;i++){
        ll x; cin >> x;
        sum+=x;
        arr[i] = x;
    }
    for(int r = N; r >= 1;r--){
        if(!sum%r){
            ll currSum = 0;
            bool ok = true; 
            for(int i = 0; i < N;i++){
                currSum+=arr[i];
                if(currSum == sum/r){
                    
                }
            }
            
        }
    }
    
}

int main(){
    int t;cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
    return 0;
}



