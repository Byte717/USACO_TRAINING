#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("feed.in","r",stdin);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int g_count = 0, h_count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'G') g_count++;
            else h_count++;
        }
        int patch_count = 0;
        string patches = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == 'G') {
                patch_count++;
                patches += "G";
                for (int j = 1; j <= k; j++) {
                    if (i + j < n && s[i + j] == 'H') {
                        patches += ".";
                    } else {
                        patches += "G";
                    }
                }
                i += k;
            } else if (s[i] == 'H') {
                patch_count++;
                patches += "H";
                for (int j = 1; j <= k; j++) {
                    if (i + j < n && s[i + j] == 'G') {
                        patches += ".";
                    } else {
                        patches += "H";
                    }
                }
                i += k;
            } else {
                patches += ".";
            }
        }
        cout << patch_count << endl;
        cout << patches << endl;
    }
    return 0;
}