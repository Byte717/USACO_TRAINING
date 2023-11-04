#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()
#define flipBits(n,b) ((n)^((1u<<(b))-1))

typedef long long ll;

using namespace std;

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){
    int n,k; cin >> n >> k;
    vector<pair<ll,int>> numbers(n);
    for(int i = 0; i < n;i++){
        cin >> numbers[i].first;
        numbers[i].second = i;
    }
    sort(all(numbers));
    int MX = -1, optimalX = -1, optimalA, optimalB;
    for(int i = 0; i < n-1;i++){
        ll ai = numbers[i].first, bi = numbers[i+1].first;
        ll sum = (ai&bi) ^ flipBits((ai&bi),k);
        if(sum > MX){
            MX = sum;
            optimalX = flipBits((ai&bi),k);
            optimalA = numbers[i].second+1; optimalB = numbers[i+1].second+1;
        }
    }
    cout << min(optimalA,optimalB) << ' ' << max(optimalA,optimalB) << ' ' << optimalX << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("martians.in","r",stdin);
    int t; cin >> t;
    while(t--){solve();}
    return 0;
}