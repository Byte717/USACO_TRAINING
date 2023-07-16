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

    auto bruteForce = [&](ll total){
        int x, y; 
        for(int i = 0; i <= total;i++){
            x = tc-i; y = tm-(total-i);
            bool works = true;
            for(auto &i : v){
                ll time = i.a*x+i.b*y;
                if(time <= i.c){
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

    // auto works2 = [&](ll x, ll y){
    //     for(int i = 0; i < n;i++){
    //         if(v[i].a * x + v[i].b * y > v[i].c){
    //             return false;
    //         }
    //     }
    //     return true;
    // };

    // auto works = [&](ll total){
    //     // x + y <= total
    //     // y <= total - x or x <= total - y
    //     // ai *x + bi*y <= ci
    //     // x <= ci-bi*(total-x)/ai ->
    //     ll x, y;
    //     ll low = 0, high = total, mid;
    //     while(low <= high){
    //         mid = low + (high-low)/2;
    //         x = max(tc - mid, (ll)0); y = max(tm - (total - mid),(ll)0);
    //         if(works2(x, y)){
    //             return true;
    //         }else{
    //             y = max(tm - mid, (ll)0); x = max(tc - (total - mid),(ll)0);
    //         }
    //         if(works2(x,y)){
    //             return true;
    //         }else{
    //             return false;
    //         }
    //     }
    //     return false;
    // };
    // cout << bruteForce(11) << endl;
    ll low = 0, high = tc+tm, ans;
    while(low <= high){
        ll mid = low + (high-low)/2;
        if(bruteForce(mid)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    cout << ans << " ";
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("bakery.in","r",stdin);
    ifstream input("bakery.out");
    int t; cin >> t;
    for(int i = 0; i < t;i++){
        solve();
        int a; input >> a;
        cout << a << endl;
    }
    return 0;
}