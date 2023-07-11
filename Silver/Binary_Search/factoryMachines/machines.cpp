#include <bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    freopen("machines.in","r",stdin);
    ll n, t; cin >> n >> t; 
    vector<int> machines(n);
    
    for(int i = 0; i < n;i++) cin >> machines[i];
    ll low = 0, high = 1e2;
    ll ans;
    while(low < high){
        ll mid = low + (high-low)/2;
        ll sum = 0; 
        for(int i = 0; i < n;i++){
            sum+=(mid/machines[i]);
            if(sum >= t) break;
        }
        if(sum >= t){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    cout << ans << endl; 
}