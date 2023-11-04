#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

/*
instead of looking for the first 2 numbers that can lead to a sequence, look for the number before n

then simulate downwards for k steps to see if its a valid sequence

WHat I learned:
- Try looking at solving brute force in reverse for a faster solution
*/


void solve(){
    int n; int k; cin >> n >> k;
    int ans = 0;
    for(int i = 1; i <= n;i++){
        int second = n;
        int first = i;
        bool valid = true;
        for(int j = 0; j < k-2;j++){
            int fx = first;
            first = second - fx;
            second = fx;
            valid &= first <= second;
            valid &=  min(first,second) >= 0;
            if(!valid) break;
        }
        if(valid) ans++;
    }
    cout << ans << endl;
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("fib.in","r",stdin);
    int t; cin >> t;
    while(t--){solve();}
    return 0;
}