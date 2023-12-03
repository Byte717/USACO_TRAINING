#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    int n; cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n;i++){
        cin >> c[i];
    }
    sort(all(c));
    int ans = 0;

    int low = 0, high = n-1;


    while(c[high] > c[low]*2 && low < high){
        int curDiff = (c[low]*2) - c[high], highDown = (c[low]*2) - c[high-1], lowUp = (c[low+1]*2) - c[high];
        if(highDown < lowUp){
            high--;
        }else{
            low++;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}