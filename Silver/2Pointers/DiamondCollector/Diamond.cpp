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


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n;i++){cin >> a[i];}
    sort(all(a));
    vector<int> numTaken(n);
    int i = 0, r = 0;
    for(;i < n;i++){
        while(r < n && a[r] -a[i] <= k) r++;
        numTaken[i] = r - i;
    }
    vector<int> MaxTakenAfter(n+1);
    MaxTakenAfter[n] = 0;
    for(int i = n-1;i >= 0;i--){
        MaxTakenAfter[i] = max(MaxTakenAfter[i+1], numTaken[i]);
    }
    int ans = 0;
    for(int i = 0; i < n;i++){
        ans = max(ans, numTaken[i] + MaxTakenAfter[i + numTaken[i]])
    }
    cout << ans << endl;
    return 0;
}
