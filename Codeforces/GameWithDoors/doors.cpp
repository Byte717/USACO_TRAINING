#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("doors.in","r",stdin);
    int t;
    cin >> t;
    while (t--) {
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        if (r < L) {
            cout << L - r << endl;
        } else if (R < l) {
            cout << l - R << endl;
        } else {
            int lock_left = r - L + 1;
            int lock_right = R - l + 1;
            cout << min(lock_left, lock_right) << endl;
        }
    }
    return 0; 
}