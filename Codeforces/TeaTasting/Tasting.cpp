#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

/*
keep a prefix of the amounts each tester will drink at once. then, for the ith tea, you can see how much the i..n testers will need
denote that as x.  if  x <= a[i], then all the members from i to n get their amounts of tea. otherwise, we need to binary seach the prefix sum array for a value that is less than or equal to a[i]
this can be done using upper bound. a[i] + sums[i] is the amount of tea + the amount of stuff before that can be ignored.
    
    sum[i]    sum[i] + a[i]
_____i ----- j_____
now whatever that is left over from a[i] will go to a[j+1]

then we can use delta encoding,for each i and j pair, we can store the amount of times the ith tester gets exactly the amount wanted
then add[i] is the amount of leftovers that the ith tester gets.

What I learned Tea tasting:
    - binary search can be used to speed up a solution that requires a second pointer
    - delta encoding, using cnt[i] as a prefix technique to count how many times the ith element has an operation done

*/



void solve(){
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0; i < n;i++) cin >> b[i];
    vector<ll> pref(n+1,0);
    for(int i = 0; i < n;i++){
        pref[i+1] = pref[i] + b[i];
    }
    vector<ll> cnt(n+1) , add(n+1);
    for(int i = 0; i < n;i++){
        ll j = upper_bound(all(pref),a[i] + pref[i]) - pref.begin() - 1; // 
        cnt[i]++;
        cnt[j]--;
        add[j] += a[i] - pref[j] + pref[i];
    }
    for(int i = 0; i < n;i++){
        cout << cnt[i] * b[i] + add[i] << ' ';
        cnt[i+1] += cnt[i];
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}