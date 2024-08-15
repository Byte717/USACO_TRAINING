#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define debug

#ifndef debug
    #pragma GCC optimize("O3","unroll-loops")
    #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#endif

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<long long> a(k+1), b(k+1);
    a[0] = 0;
    b[0] = 0;
    for(int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= k; i++)
    {
        cin >> b[i];
    }
    for(int i = 0; i < q; i++)
    {
        long long c;
        cin >> c;
        int l = 0, r = k;
        while(l <= r)
        {
            int mid = l+r>>1;
            if(a[mid] > c)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        if(a[r] == c)
        {
            cout << b[r] << " ";
            continue;
        }
        long long ans = b[r] + (c-a[r])*(b[r+1]-b[r])/(a[r+1]-a[r]);
        cout << ans << " ";
    }
    cout << endl;

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    #ifdef LOCAL
	auto _clock_start = chrono::high_resolution_clock::now();
    #endif 
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    #ifdef LOCAL
    cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
        chrono::high_resolution_clock::now()
            - _clock_start).count() << "ms." << endl;
    #endif
    return 0;
}