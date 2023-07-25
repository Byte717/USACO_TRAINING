#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


void solve(){
    int n, m; cin >> n >> m;
    vector<pair<int,int>> ranges(m);
    for(int i = 0; i < m;i++){
        cin >> ranges[i].first >> ranges[i].second;
    }
    int q; cin >> q;
    vector<int> updates(q);
    for(int i = 0; i < q;i++){
        cin >> updates[i];
    }

    auto works = [&](int x){
        vector<int> arr(n+1,0);

        for(int i = 0; i < x;i++){
            arr[updates[i]] = 1;
        }
        for(int i = 1; i <= n;i++){
            arr[i] += arr[i-1];
        }
        for(int i = 0; i < m;i++){
            int a = ranges[i].first, b = ranges[i].second;
            int sum = arr[b] - arr[a-1], len = b-a+1;
            if(2*sum > len){
                return true;
            }
        }
        return false;
    };

    int low = 1, high = q, ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(works(mid)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("tracking.in","r",stdin);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}