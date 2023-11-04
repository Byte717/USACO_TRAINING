#include <bits/stdc++.h>
#define ll long long


using namespace std; 

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    return a.first < b.first;
}


int main(){
    freopen("socdist.in","r",stdin);
    int n, m; cin >> n >> m;
    vector<pair<ll,ll>> intervals(m);
    for(int i = 0; i < m;i++) cin >> intervals[i].first >> intervals[i].second;
    sort(intervals.begin(),intervals.end(),cmp);

    auto works = [&](ll dist){
        int toBePlaced = n-1;
        int i = 0;
        int currX = intervals[0].first;
        while(currX + dist <= intervals[m-1].second){
            while(currX + dist > intervals[i].second){
                i++;
            }
            currX = max(currX+dist, intervals[i].first);
            toBePlaced--;
        }
        return toBePlaced <= 0;
    };
    // cout << works(2)<< endl;
    ll low = 0, high = 6, mid, ans;
    while(low <= high){
        mid = low + (high-low)/2;
        if(works(mid)){
            ans = mid; 
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}