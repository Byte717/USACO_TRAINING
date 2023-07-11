#include <bits/stdc++.h> 
#define ll unsigned long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("div.in","r",stdin);
    int n, k; cin >> n >> k;
    vector<ll> x(n);
    for(int i = 0; i < n;i++){
        cin >> x[i];
    }
    auto works = [&](int target){
        ll groupNum = 0, sum = 0;
        for(int i = 0; i < n;i++){
            if(x[i] > target){
                return false;
            }
            if(x[i] + sum > target){
                sum = 0;
                groupNum++;
            }
            sum+=x[i];
        }
        if(sum > 0){
            groupNum++;
        }
        return groupNum <= k;

    };
    ll ans;
    ll low = 0, hi = 1e19, mid;
    while(low <= hi){
        mid = low + (hi - low)/2;
        if(works(mid)){
            hi = mid - 1;
            ans = mid;
        }else{
            low = mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}