#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

struct friends{
    ll a, b, c;
};

void solve(){
    int n;ll tc, tm; cin >> n >> tc >> tm;
    vector<friends> v;
    for(int i = 0; i < n;i++){
        ll a, b, c; cin >> a >> b >> c;
        v.push_back({a,b,c});
    }
    // ai * tc + bi * tm <= ci

    auto works = [&](ll total){
        // (true, true) if all n friends satisfied,
        // (false, false) if both values are too high
            // how do we define if values are too high?
        // ()
        int x, y; 
        for(int i = 1; i < total-1;i++){
            x = i; y = total-i;
            bool works = true;
            for(auto &i : v){
                if(i.a*x+i.b*y <= i.c){
                    continue;
                }else{
                    works = false;
                    break;
                }
            }
            if(works){return true;}
        }
        return false;
    };

    ll low = 0, high = tc+tm, ans;
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
    while(t--){solve();}
    return 0;
}