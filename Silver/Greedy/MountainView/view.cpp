#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("mountains.in","r",stdin);
    freopen("mountains.out","w",stdout);
    int n; cin >> n;
    vector<pair<ll,ll>> peaks(n);
    for(int i = 0; i < n;i++){
        cin >> peaks[i].first >> peaks[i].second;
    }
    vector<pair<ll,ll>> intervals;
    for(auto &[x,y] : peaks){
        intervals.push_back({x-y,x+y});
    }
    
    sort(all(intervals), [](pair<ll,ll> & a, pair<ll,ll> & b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    int ans = n;
    ll invStart = -1, invEnd = -1;
    for(auto &[start,end] : intervals){
        if(invStart == -1 && invEnd == -1){
            invStart = start;
            invEnd = end;
        }else{
            if(end < invEnd){
                ans--;
                continue;
            }
            if(end > invEnd){
                invEnd = end;
                invStart = start;
            }
        }
    }
    cout << ans << endl;
    return 0;
}