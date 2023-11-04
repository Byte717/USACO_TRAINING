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
    int a[n];
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }

    auto works = [&](int median){
        vector<int> f(n);
        for(int i = 0; i < n;i++){
            if(a[i] >= median){
                f[i] = 1;
            }else{
                f[i] = -1;
            }
            if(i > 0){
                f[i] += f[i-1];
            }
        }
        int MIN = 0;
        int diff = 0;
        for(int i = k - 1;i < n; i++){
            MIN = min(MIN, f[i-k]);
             diff = max(diff, f[i] - MIN);
        }
        return diff > 0;
    };


    int low = 1, high = n, ans  = -1;
    while(low <= high){
        int mid = (low + high + 1)/2;
        if(works(mid)){
            low = mid + 1;
            ans = mid;
        }else{
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
