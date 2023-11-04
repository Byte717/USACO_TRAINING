#include <iostream>
#include <vector>
using namespace std;

const int N = 105;

int t, n, m;
vector<pair<string, int>> inputs;

bool check(int mask) {
    for (auto input : inputs) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                res = input.first[i] - '0';
                break;
            }
        }
        if (res != input.second) return false;
    }
    return true;
}

int main() {
    freopen("reverseEngineer.in","r",stdin);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        inputs.clear();
        for (int i = 0; i < m; i++) {
            string s; int x;
            cin >> s >> x;
            inputs.push_back({s, x});
        }
        int ans = -1;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (check(mask)) {
                if (ans == -1) {
                    ans = mask;
                } else {
                    ans = -1;
                    break;
                }
            }
        }
        if (ans == -1) {
            cout << "LIE" << endl;
        } else {
            cout << "OK" << endl;
        }
    }
    return 0;
}