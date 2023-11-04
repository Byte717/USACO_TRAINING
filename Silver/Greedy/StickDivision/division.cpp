#include <bits/stdc++.h>
#define ll long long
#define INF 1e5

using namespace std; 

// int main(){
//     cin.tie(0)->sync_with_stdio(0);
//     freopen("div.in","r",stdin);
//     int x, n; cin >> x >> n;
//     vector<int> sticks(n);
//     for(int i = 0; i < n;i++){
//         cin >> sticks[i];
//     }
//     sort(sticks.rbegin(),sticks.rend());
//     int cost = 0;
//     for(int i = 0; i < n;i++){
//         if(x == sticks[i]) continue;
//         cost+= x;
//         x-=sticks[i];
//     }
//     cout << cost << endl;
//     return 0;
// }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("div.in","r",stdin);
    int x, n; cin >> x >> n;
    vector<int> sticks(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n;i++){
        cin >> sticks[i];
        pq.push(sticks[i]);
    }

    int ans = 0;
    for(int i = 1; i < n;i++){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a+b);
        ans+= a+b;
    }
    cout << ans << endl;
    return 0;
}