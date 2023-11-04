#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;


/*
solution: we can notice that we can keep a prefix of the array. If we query from [l,r], and its pref[r]-pref[l-1], the 2 rock isnt there
so we use a binary search like technique, from mid to low, if the query answer is the number of rocks in those piles,we break the range

WHat I learned Interview:
    - Binary search can be used to search an interval

*/


void solve(){
    int n; cin >> n;
    vector<int> a(n+1), pref(n + 1,0);

    for(int i = 1; i <= n;i++){
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
    int low = 1, high = n, ans = 0;
    while(low <= high){
        int mid = low + (high-low)/2;
        int expectedLeft = pref[mid] - pref[low - 1];
        // int expectedRight = (mid > 0) ? pref[high] - pref[mid-1] : pref[high] - pref[mid];
        cout << "? " << mid - low + 1 << ' ';
        for(int i = low; i <= mid; i++){
            cout << i << ' ';
        }
        cout << endl;
        int x; cin >> x;
        if(x == expectedLeft){
            low = mid + 1;
        }else{
            high = mid - 1;
            ans = mid;
        }
    }
    cout << "! " << ans << endl;
}   

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("interview.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}