#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int ok = 0, ng = 1e9+1;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;

            long long sum = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] >= mid)
                    sum += (a[i] - mid) / b[i] + 1;
            }

            if (sum >= k) ok = mid;
            else ng = mid;
        }

        long long ans = 0;
        int s = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] >= ok) {
                int m = (a[i] - ok) / b[i] + 1;
                ans += 1LL * m * a[i] - 1LL * m * (m - 1) / 2 * b[i];
                s += m;
            }
        }

        ans -= 1LL * ok * (s - k);

        cout << ans << "\n";
    }

    return 0;
}