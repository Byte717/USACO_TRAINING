#include <bits/stdc++.h> 
using namespace std;

int main(){
    int t; cin >> t;
    
    while (t--){
        int n, k; cin >> n >> k;
        
        vector <pair<int, int>> a(n);
        for (auto &x : a) cin >> x.first;
        for (auto &x : a) cin >> x.second;
        sort(a.begin(), a.end());
        
        long long ans = 0;
        // case 1 : increment max 
        for (int i = 0; i < n; i++) if (a[i].second == 1){
            // find med(c_i) 
            int mc;
            if (i < n / 2) mc = a[n / 2].first;
            else mc = a[(n - 2) / 2].first;
            
            ans = max(ans, 0LL + a[i].first + k + mc);
        }
        
        // case 2 : increment median
        int lo = 0, hi = 2e9;
        while (lo != hi){
            int mid = (1LL + lo + hi) / 2;
            
            int z = 0;
            vector <int> smaller_list;
            for (int i = 0; i < n - 1; i++){
                if (a[i].first >= mid){
                    z++;
                } else if (a[i].second == 1){
                    smaller_list.push_back(mid - a[i].first); // list of numbers smaller than x but b[i] = 1 
                }
            }
            
            reverse(smaller_list.begin(), smaller_list.end()); // list will be sorted in ascending, but we want sorted in descending, as greedily changing largest elements 
            int kk = k;
            for (auto x : smaller_list) if (kk >= x){
                kk -= x;
                z++;
            }
            
            if (z >= (n + 1) / 2) lo = mid;
            else hi = mid - 1;
        }
        
        ans = max(ans, 0LL + a[n - 1].first + lo);
        
        cout << ans << "\n";
    }
    return 0;
}