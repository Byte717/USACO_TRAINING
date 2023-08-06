#include <bits/stdc++.h>
using namespace std;

int n, ans[100010];
vector<pair<int,int>> arr;

void solve() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = n - 1, sz = n;
    while (l <= r) {
        if ((arr[r].first == n - l) ^ (arr[l].first == n - 1 - r)) {
            if (arr[r].first == n - l) {
                ans[arr[r--].second] = sz--;
            }
            else {
                ans[arr[l++].second] = -(sz--);
            }
        }
        else {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}