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
        
        for(int left = 0; left < n-1;left++){

        }
    };



    int low = 0, high = 1e6,ans;
    while(low <= high){
        int mid = low + (high-low)/2;

    }
    return 0;
}
