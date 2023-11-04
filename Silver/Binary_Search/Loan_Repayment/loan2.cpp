#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("loan.in","r",stdin);
    freopen("loan.out","w",stdout);
    ll n, m, k;
    cin >> n >> k >> m;

    auto works = [&](ll x){
        ll leftOver = n;
        ll daysPassed = 0;
        while(daysPassed < k){
            ll amount = leftOver/x;
            if(amount < m){
                ll daysNeeded = leftOver/m;
                if(leftOver % m != 0) daysNeeded++;
                leftOver -= (daysNeeded*m);
                daysPassed+= daysNeeded;
                break;
            }else{
                ll distFromMult = leftOver - (x*(leftOver/x));
                if(distFromMult == 0){
                    daysPassed++;
                    leftOver -= (leftOver)/x;
                    continue;
                }
                ll daysNeeded = distFromMult/amount;
                if(distFromMult % amount != 0) daysNeeded++;
                leftOver -= amount*daysNeeded;
                daysPassed += daysNeeded;
            }
        }
        return daysPassed <= k && leftOver <= 0; 
    }; 

    
    ll low = 1, high = 1e18, ans = -1;
    while(low <= high){
        ll mid = low + (high-low)/2;
        if(works(mid)){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}