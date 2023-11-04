#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("books.in","r",stdin);
    ll n, t; cin >> n >> t;
    vector<ll> books(n);
    for(int i = 0; i < n;i++){
        cin >> books[i];
    }
    vector<ll> pref(n+1,0);
    for(int i = 0; i < n;i++){
        pref[i+1] = pref[i] + books[i];
    }

    auto verifySize = [&](ll size){
        for(int i = 1; i + size <= n;i++){
            if(pref[i+size] - pref[i-1] <= t){
                return true;
            }
        }
        return false;
    };


    ll low = 0, high = n, ans = -1; 
    while(low <= high){
        ll mid = low + (high-low)/2;
        if(verifySize(mid)){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1; 
        }
    }
    cout << ans+1 << endl;
    return 0;
}