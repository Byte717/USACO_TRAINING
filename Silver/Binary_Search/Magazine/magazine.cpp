#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int k; cin >> k;
    string s; cin >> s;


    auto works = [&](int width){
        // greedily fit each word into with dimensions k by width
        int numLines = 0;
        string currLine = "";
        int i = 0;
        while(numLines < k && i < s.length()){
            if(s[i] ==)
        }
    };

    int low = 0, high = s.length(), mid, ans = -1;
    while(low <= high){
        mid = low + (high - low)/2;
        if(works(mid)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return 0;
}