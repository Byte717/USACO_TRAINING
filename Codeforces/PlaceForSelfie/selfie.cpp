#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

/*
solution: to see if an equation ax^2 + bx + c intersects with y = kx, 
the DIFFERENCE EQUATION must be used. which in this case is ax^2 + (b-k)x + c;
if that difference equation has no roots, then there is no solution, which is to say, 
(b-k)^2 - 4ac  < 0
so we binary search for the smallest value greater than b in our line k values, then see if those values satisfy the inequality

WHat I learned Selfie:
    - Binary search can be used to find values for queries.
    - Difference EQUATION can be used to find if 2 equations intersect.

*/


void solve(){
    int n,m; cin >> n >> m;
    vector<ll> lines(n);
    for(int i = 0; i < n;i++){
        cin >> lines[i];
    }
    sort(all(lines));
    for(int i = 0; i < m;i++){
        ll a, b, c; cin >> a >> b >> c;
        int idx = lower_bound(all(lines),b) - lines.begin();
        if(idx < n && (lines[idx]-b)*(lines[idx]-b) < 4*a*c){
            cout << "YES" << endl;
            cout << lines[idx] << endl;
            continue;
        }else if(idx > 0 &&(lines[idx-1]-b)*(lines[idx-1]-b) < 4*a*c){
            cout << "YES" << endl;
            cout << lines[idx-1] << endl;
            continue;  
        }
        cout << "NO" << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("selfie.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}