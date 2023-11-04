#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
// #include <bits/stdc++.h>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("mountain.in","r",stdin);
    int n; cin >> n;
    vector<pair<int, pair<int,int>>> peaks(n);
    int x, y;
    for(int i = 0; i < n;i++){
        cin >> x >> y;
        peaks[i] = make_pair(x-y, make_pair(x,y));
    }
    sort(peaks.begin(),peaks.end());
    int ans = n;
    int maxEnd = peaks[0].second.first+peaks[0].second.second;
    for(int i = 1; i < n;i++){
        if(peaks[i].second.first+peaks[i].second.second <= maxEnd){
            ans--;
            continue;
        }else{
            maxEnd = max(maxEnd, peaks[i].second.first+peaks[i].second.second);
        }
    }
    cout << ans << endl;


    return 0;
}