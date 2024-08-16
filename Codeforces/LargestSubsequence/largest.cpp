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
     int n;
        string s;
        cin >> n >> s;
        s = '$' + s;
        vector<int> subset; // finds biggest subsequence in the string
        for (int i = 1; i <= n; ++i)
        {
            while (!subset.empty() && s[subset.back()] < s[i])
            {
                subset.pop_back();
            }
            subset.push_back(i);
        }
        int ans = 0;
        int m = (int)subset.size() - 1;
        while (ans <= m && s[subset[ans]] == s[subset[0]]) // finds largest prefix of value equal to the first character
        {
            ans++;
        }
        ans = m - ans + 1; // then the pivot point is length of the substring - longest prefix

        for (int i = 0; i <= m; ++i) // execute swaps
        {
            if (i < m - i)
            {
                swap(s[subset[i]], s[subset[m - i]]);
            }
        }
        for (int i = 2; i <= n; ++i)
        {
            if (s[i] < s[i - 1])
            {
                ans = -1;
                break;
            }
        }
        cout << ans << '\n';
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