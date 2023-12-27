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
    freopen("cutting.in","r",stdin);
    int n, k; cin >> n >> k;
    vector<int> s(n);
    map<int,int> freq;
    for(int i = 0; i < n;i++){
        cin >> s[i];
        freq[s[i]]++;
    }
    vector<pair<int,int>> nums;
    for(auto &i : freq){
        nums.push_back({i.second, i.first});
    }
    sort(all(nums));
    reverse(all(nums));
    for(int i = 0; i < k;i++){
        cout << nums[i].second << ' ';
    }
    return 0;
}