#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

ll rec(ll i, ll sum, vector<ll> &v, ll &tot, vector<vector<ll>> &dp){
    if(i == v.size()){
        return (tot-sum) * sum;
    }
    if(dp[i][sum] != -1){
        return dp[i][sum];
    }
    ll take = rec(i+1,sum + v[i], v,tot,dp);
    ll notTake = rec(i + 1, sum, v,tot,dp);
    return dp[i][sum] = max(take,notTake);
}

ll helper(vector<ll> &v,ll &tot){
    ll n = v.size();
    vector<vector<ll>> dp(n, vector<ll>(tot+1,-1));
    return rec(0,0,v,tot,dp);
}

ll calc(ll node, vector<vector<ll>> &adj, ll &res){
    ll children = 0;
    vector<ll> v;
    for(ll i : adj[node]){
        ll x = calc(i,adj,res);
        children += x;
        v.push_back(i);
    }
    res += helper(v,children);
    return children+1;
}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("permutree.in","r",stdin);
    ll n,x; cin >> n;
    vector<vector<ll>> adj(n);
    for(int i = 1; i < n;i++){
        cin >> x;
        adj[x-1].push_back(i);
    }
    ll res = 0;
    res = calc(0,adj,res);
    cout << res << endl;
    return 0;
}