#include <iostream>

using namespace std;

int a[1000000 + 5], p[1000000 + 5];

int get_sum(int l, int r) {
    if (l > r) {
        return 0;
    }
    return (l % 2 == 1) ? p[r] - p[l - 1] : p[l - 1] - p[r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string ss;
        cin >> ss;
        for (int i = 1; i <= n; i++) {
            a[i] = (ss[i - 1] == '+' ? 1 : -1);
        }
        p[0] = 0;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + (i % 2 == 1 ? a[i] : -a[i]);
        }
        for (int o = 0; o < q; o++) {
            int l, r;
            cin >> l >> r;
            if (get_sum(l, r) == 0) {
                cout << "0\n";
                continue;
            }
            if ((r - l + 1) % 2 == 0) {
                cout << "2\n";
            }
            else {
                cout << "1\n";
            }
        }
    }
}