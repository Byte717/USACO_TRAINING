#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;



int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("cowdemia.in","r",stdin);
    int n, k, l; cin >> n >> k >> l;
    vector<int> c(n);
    for(int i = 0; i < n;i++){
        cin >> c[i];
    }
    sort(all(c));
    reverse(all(c));
    if(k == 0 || l == 0){
        for(int i = 0; i < n;i++){
            if(c[i] >= i) continue;
            else{
                cout << i << endl;
                return 0;
            }
        }
    }
    auto works = [&](int x){
        int papersUsed = 0;
        for(int i = 0; i < x;i++){
            if(c[i] < x){
                int diff = x - c[i];
                int give = diff/l;
                if(diff % l != 0){
                    give += 1;
                }
                papersUsed += give;
            }
        }
        return papersUsed <= k;
    };

    // works(2);
    int low = 1, high = n, ans = 0;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(works(mid) && c[mid-1] + k >= mid){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}