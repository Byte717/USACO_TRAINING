#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("good.in","r",stdin);
    int n; cin >> n;
    vector<int> pref(n+1);
    for(int i = 1; i <= n;i++){
        char c; cin >> c;
        pref[i] = c -'0';
    }
    for(int i = 1; i <= n;i++){
        pref[i] += pref[i-1];
    }
    map<int,int> m;
    for(int i = 1; i <= n;i++){
        m[pref[i]-i]++;
    }
    int good = 0;
    for(int i = 0; i < n;i++){
        int curr = pref[i] - i;
        good += m[curr];
    }
    cout << good << endl;
    return 0;
}