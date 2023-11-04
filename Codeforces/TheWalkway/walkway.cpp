#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

/*
solution: on the walkway, the amount earned at the Ith stand is stand[i] - stand[i-1] - 1/ d; 
basically, the we know that the distance between two stands divided by d is the amount of time the guys stops to eat cookies.

What I learned Walkway:
    - think of base cases! AGAIN
    - boil the problem to math.


*/



int calcAns(int d, vector<int> r){
    int ans = 0;
    for(int i = 1; i < r.size();i++){
        ans += (r[i] - r[i-1]-1)/d;
    }
    ans += (int)r.size() -2;
    return ans;
}

void solve(){
    int n, m, d; cin >> n >> m >> d;
    vector<int> r(m);
    for(int i = 0; i < m;i++) cin >> r[i];
    r.insert(r.begin(),1-d);
    r.push_back(n+1);
    int ans = 2e9;
    vector<int> res;
    for(int i = 1; i <= m;i++){
        int A = r[i] - r[i-1] - 1;
        int B = r[i+1] - r[i] - 1;
        int C = r[i+1] - r[i-1] -1;
        int D = C/d - (A/d + B/d);
        if(D < ans){
            ans = D;
            res.clear();
        }
        if(D == ans){
            res.push_back(r[i]);
        }
    }
    cout << ans + calcAns(d,r) - 1 << ' ' << res.size() << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("walkway.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}