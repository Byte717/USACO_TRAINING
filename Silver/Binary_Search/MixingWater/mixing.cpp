#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;



void solve(){
    int h, c, t; cin >> h >> c >> t;
    if(t == h){
        cout << 1 << endl;
        return;
    }
    int last = -1;
    int lastTot = -1;
    auto works = [&](int total){
        int x, y;
        if(total % 2 == 0){
            x = total/2;
            y = total/2;
        }else{
            x = ((total-1)/2) + 1;
            y = x - 1;
        }
        if(last == -1){
            last = abs(t-((h*x+c*y)/total));
            return true;
        }else{
            int cur = abs(t-((h*x+c*y)/total));
            if(cur < last){
                last = cur;
                lastTot = total;
                return true;
            }else if(cur == last && total < lastTot){
                lastTot = total;
                return true;
            }else{
                return false;
            }
        }
    };


    int low = 0, high = h, mid, ans = -1;
    while(low <= high){
        mid = low + (high-low)/2; // mid = how much spent total
        if(works(mid)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("mixing.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}