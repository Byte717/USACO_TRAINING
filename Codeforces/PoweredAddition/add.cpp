#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;
/*
What I learned powered addition:
    - Filter an array based on conditions
        - eg. what is the minimum needed to make it sorted
        - its sorted when arr[i-1] < arr[i]
        - so add to a number when thats not met
    



*/







int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int &i : arr){
        cin >> i;
    }
    vector<int> target{arr[0]};
    vector<int> to_add;
    for(int i = 1; i < n;i++){
        if(target.back() > arr[i]){
            to_add.push_back(target.back()- arr[i]); // add the difference that we need to apply to the ith element to get it greater than or equal the last
            target.push_back(target.back()); // the difference is pushed, so the nums are equal
        }else{
            target.push_back(arr[i]);
        }
    }
    int ans = 0;
    for(auto &i : to_add){
        ans = max(ans, LOG2(i)+1);
    }
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}