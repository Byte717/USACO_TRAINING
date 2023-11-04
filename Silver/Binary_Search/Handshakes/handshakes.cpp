#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(all(a));
    vector<int> prefix(n);
    prefix[0] = a[0];
    for(int i = 1; i < n;i++){
        prefix[i] = prefix[i-1] + a[i];
    }

    auto works = [&](int happiness){
        ll totalHandShake = 0, totalHappiness = 0;
        for(int left = 0; left < n-1;left++){
            if(a[left] + a[n-1] < happiness) continue;
            int l = left, r = n-1;
            while(l < r){
                int mid = l + (r-l)/2;
                if(a[mid] + a[left] >= happiness) r = mid;
                else l = mid + 1;
            }
            totalHandShake += 2*(n-1);
            if(l == left) totalHandShake--;
            totalHappiness += 2 * (n-1) * a[left] + 2*(prefix[n-1]-prefix[l]);
            if(l == left) totalHappiness -= 2*a[left];
        }
        return {totalHandShake,totalHappiness};
    };



    int low = 0, high = 1e6,ans;
    while(low < high){
        int mid = low + (high-low)/2;
        auto res = works(mid);
        if(res.first >= m) low = mid;
        else high = mid - 1;
    }
    auto res = works(low);
    for(int i = res.first; i > m;i--) res.second -= 1;
    cout << res.second << endl;
    return 0;
}
