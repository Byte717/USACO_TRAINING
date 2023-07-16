#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};
struct friends{
    ll cookies, muffins, time;
};




void solve(){
    int n;ll tc, tm; cin >> n >> tc >> tm;
    vector<friends> v;
    for(int i = 0; i < n;i++){
        ll a, b, c; cin >> a >> b >> c;
        v.push_back({a,b,c});
    }


    function<bool(ll)> works = [&](ll total){
        bool impossible = false;
        ll minX = 1, maxX = tc;
        for(friends & i : v){
            ll optimalX;
            if(i.cookies >= i.muffins){ // max I can spend on cookie Machine
                optimalX = tc - min(total,tc-1);
                minX = max(optimalX, minX); 
                ll lowX = optimalX, highX = tc - total- min(total, tm-1), ans=-1;
                while(lowX <= highX){
                    ll mid = lowX + (highX-lowX)/2;
                    if(i.cookies *mid+ (tm-(total-(tc-mid)))*i.muffins <= i.time){
                        ans = mid;
                        lowX = mid+1;
                    }else{
                        highX = mid -1;
                    }
                }
                if(ans != -1){
                    maxX = min(maxX, ans);
                }else{
                    impossible = true;
                    break;
                } 
            }else{
                optimalX = tc -(total-min(total,tm-1));
                maxX = min(optimalX, maxX);
                ll lowX = optimalX, highX = tc-(total-min(total, tm-1)), ans = -1;
                while(lowX <= highX){
                    ll mid = lowX +(highX-lowX)/2;
                    if(mid*i.cookies + (tm-(total-(tc-mid)))*i.muffins <= i.time){
                        ans = mid;
                        highX = mid -1;
                    }else{
                        lowX = mid + 1;
                    }
                }
                if(ans != -1){
                    minX = max(minX,ans);
                }else{
                    impossible = true;
                    break;
                }
            }
        }
        return minX <= maxX && !impossible;
    };

    ll low = 0, high = tc + tm, ans;
    while(low <= high){
        ll mid = low + (high-low)/2;
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
    freopen("bakery.in","r",stdin);
    int t; cin >> t;
    for(int i = 0; i < t;i++){
        solve();
    }
    return 0;
}