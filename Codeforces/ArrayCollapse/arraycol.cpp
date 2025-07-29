#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int normalize(long long x) {
    x %= MOD;
    if (x < 0) x += MOD;
    return x;
}

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        int n;
        cin >> n;
        vector <int> a(n);
        vector <int> nextMin(n);
        vector <int> dpSum(n + 2);
        vector <int> dpNext(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        
        stack <int> stMin;
        nextMin[n - 1] = n;
        dpSum[n] = 1;
        for (int pos = n - 1; pos >= 0; --pos) {
            while(!stMin.empty() && a[stMin.top()] > a[pos])
                stMin.pop();
            nextMin[pos] = stMin.empty() ? n : stMin.top();
            stMin.push(pos);
            
            int nxtPos = nextMin[pos];
            int dpPos = normalize(dpSum[pos + 1] - dpSum[nxtPos + 1]);
            if (nxtPos != n) {
                dpPos = normalize(dpPos + dpNext[nxtPos]);
                dpNext[pos] = normalize(dpSum[nxtPos] - dpSum[nxtPos + 1] + dpNext[nxtPos]);
            }
            dpSum[pos] = normalize(dpPos + dpSum[pos + 1]);
            
            //cout << pos << ' ' << nxtPos << ' ' << dpPos << endl;
        }
        
        int res = 0;
        int mn = a[0];
        for(int i = 0; i < n; ++i) {
            mn = min(mn, a[i]);
            if (a[i] == mn) {
                res = normalize(res + dpSum[i] - dpSum[i + 1]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
