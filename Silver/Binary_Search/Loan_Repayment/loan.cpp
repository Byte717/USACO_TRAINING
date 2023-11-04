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
        ll given = 0;
        ll daysLeft = k;
        ll minAmount = m;
        while(daysLeft > 0 && g < n){
            ll y = (n-given)/x;
            if(y < m){
                ll leftOver = ((n-given) + (m-1))/m;
                return leftOver <= daysLeft;
            }
            ll maxMatch = n - (x*y);
            ll numDays = min(daysLeft, (maxMatch-g)/y+1);
            given += y*numDays;
            daysLeft -= numDays;
        }
        return given >= n;
    };

    ll low = 1, hi = 1e12, mid, ans;
    while(low <= hi){
        mid = low + (hi - low)/2;
        if(worksBetter(mid)){
            low = mid+1;
            ans = mid;
        }else{
            hi = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}