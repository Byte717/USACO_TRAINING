#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("ConsSub.in","r",stdin);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    map<int,int> dp;
    int ans = 0, lst = 0;
    for(int i = 0; i < n; i++){
        dp[a[i]] = dp[a[i]-1] + 1;
        if(ans < dp[a[i]]){
            ans = dp[a[i]];
            lst = a[i];
        }
    }
    vector<int> res;
    for(int i = n-1; i >= 0; i--){
        if(a[i] == lst){
            res.push_back(i);
            lst--;
        }
    }
    reverse(all(res));
    cout << ans << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}