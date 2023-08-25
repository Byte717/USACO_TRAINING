#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;
/*
keep two prefix sums, the first the prefix of the original. the second the prefix of th prefix where pref2 = pref[i+k-1] - pref[i-1]
basically, a prefix that tells you how much u get from the ith element being the first.
then keep a variable t to represent b's subarray value and j the index of it;
then a variable m for a's subarray, and i represents its index; 

What I learned Max Absurdity: revisit *****
    - prefix sums can be used twice
*/


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("absurd.in","r",stdin);
    int n, k; cin >> n >> k;
    vector<ll> laws(n);
    for(int i = 0;i < n;i++){
        cin >> laws[i];
    }
    vector<ll> pref(n+1,0);
    for(int i = 0; i < n;i++){
        pref[i+1] = pref[i] + laws[i];
    }
    vector<ll> pref2(n+1);
    for(int i = 1; i <= n-k+1; i++){
        pref2[i] = pref[i+k-1] - pref[i-1];
    }
    int a, b;
    int j=0, t = 0, m=0;
    for(int i = n-2*k+1; i >= 1;i--){
        if(t <= pref2[i+k]){t = pref[i+k]; j = i + k;}
        if(t + pref2[i] >= m){m = pref2[i] + t; a= i; b = j;}
    }
    cout << a << ' ' << b << endl;
    // ll MX = -1;
    // int a = -1;
    // for(int i = 1; i <= n-k+1;i++){
    //     ll total = pref[i + k - 1] - pref[i-1];
    //     if(total > MX){
    //         MX = total;
    //         a = i;
    //     }
    // }
    // ll MX2 = -1; 
    // int b = -1;
    // for(int i = 1; i <= n-k+1;){
    //     if(i >= a && i <= a+k-1){
    //         i = a + k;
    //         continue;
    //     }
    //     ll total = pref[i+k-1] - pref[i-1];
    //     if(total > MX2 && i + k -1 != a){
    //         MX2 = total;
    //         b = i;
    //     }
    //     i++;
    // }
    // cout << min(a,b) << ' ' << max(a,b) << endl;
    return 0;
}