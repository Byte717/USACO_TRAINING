#include <iostream>
#include <cstdio>
#define ll long long

using namespace std; 

int main(){
    freopen("loan.in","r",stdin);
    freopen("loan.out","w",stdout);
    ll n, k, m; cin >> n >> k >> m; 
    auto works = [&](ll mid){
        ll paidSoFar = 0;
        ll daysPassed = 0;
        ll numPaid;
        while(daysPassed < k){
            numPaid = (ll)((((double)n - (double)paidSoFar)/(double)mid) + 0.5);
            numPaid = (numPaid <= m) ? m : numPaid;
            paidSoFar+=numPaid;
            daysPassed++;
        }
        if(paidSoFar >= n) return true;
        else return false;
    };


    auto worksBetter = [&](ll x){
        


    };

    ll low = 1, hi = 1e12, mid, ans;
    while(low <= hi){
        mid = low + (hi - low)/2;
        if(works(mid)){
            low = mid+1;
            ans = mid;
        }else{
            hi = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}