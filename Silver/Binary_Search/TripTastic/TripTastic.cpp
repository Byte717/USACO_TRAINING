#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int solve(){
    int n, m; cin >> n >> m;
    ll k; cin >> k;
    vector<vector<int>> a(n,vector<int>(m,0));
    vector<vector<int>> pref(n,vector<int>(m,0));
    ll total = 0;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            cin >> a[i][j];
            total += a[i][j];
        }
    }

    if(total < k + 1){
        return -1;
    }
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            pref[i][j] = a[i][j];
            if (i > 0) { pref[i][j] += pref[i - 1][j]; }
            if (j > 0) { pref[i][j] += pref[i][j - 1]; }
            if (i > 0 && j > 0) { pref[i][j] -= pref[i - 1][j - 1]; }
        }
    }
    function<ll(int,int,int,int)> rangeSum = [&](int x1,int y1, int x2,int y2){
        if(x1 < 0) x1 = 0;
        if(x2 >= n) x2 = n-1;
        if(y1 < 0) y1 = 0;
        if(y2 >= m) y2 = m-1;
        
        
        ll ans = 0; 
        ans += pref[x2][y2];
        if(x1 > 0) ans -= pref[x1-1][y2];
        if(y1 > 0) ans -= pref[x2][y1-1];
        if(x1 > 0 && y1 > 0) ans += pref[x1-1][y1-1];
        return ans;
    };

    function<int(int)> works = [&](int x){
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(a[i][j] == 0){
                    continue;
                }
                if(rangeSum(i-x, j-x,i+x,j+x) >= k+1) return true;

            }
        }
        return false;
    };



    function<int(int,int)> MinDist = [&](int low, int high){
        high++;
        ll ans;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(works(mid)){
                high = mid - 1;
                ans = mid;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    };

    return MinDist(0,max(n,m));

}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("TT.in","r",stdin);
    int t; cin >> t;
    while(t--){cout << solve() << endl;}
    return 0;
}