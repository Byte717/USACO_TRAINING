#include <bits/stdc++.h>

using namespace std; 

int main(){
    int n; cin >> n; 
    vector<int> p(n + 1), t(n + 1), d(n + 2);
    for(int i = 1; i <= n; i++)cin >> p[i];
    for(int i = 1; i <= n; i++)cin >> t[i];
    for(int i = 1; i <= n; i++) d[i] = p[i] - t[i];
    int ans = 0;
    for(int i = 0; i <= n;i++){
        ans += abs(d[i] - d[i+1]);
    }
    cout << ans/2 << endl;
    return 0;
}