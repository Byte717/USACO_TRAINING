#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;
/*
    Options: DP, Greedy
    Maybe Prefix sums to loop through all i?
*/

/*
Actual solution: Maximum has to be s subarray of the original array. 
- Bad solution is to loop through all subarrays and calculate in O(n^3)

-Using basically a prefix sum, we keep a prefix of what xor sums we have seen in past subarrays from 1 to some index
- when we look at this element and look at the current Xor, we look for another value that it can be xored with
- when you xor 2 ranges, the intersection is canceled out, so you are left with the biggest segment


What I learned? 
- boolean arrays can be used to speed up the solution (tactic)
- Concept: Xor ranges
    - Intersections of ranges cancel out
*/

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    int MXVal = pow(2,8);
    vector<bool> pref(MXVal);
    pref[0] = true;
    int curr = 0;
    int ans = 0;
    for(auto &i : a){
        curr ^= i;
        for(int j = 0; j < MXVal;j++){
            if(pref[j]){
                ans = max(ans, j^curr);
            }
        }
        pref[curr] = true;
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("vampiric.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}