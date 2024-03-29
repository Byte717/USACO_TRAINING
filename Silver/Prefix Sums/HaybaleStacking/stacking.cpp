#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("stacking.in","r",stdin);
    int n, k; cin >> n >> k;
    int pref[n+1]{};
    pref[0] = 0;
    for(int i = 0; i < k;i++){
        int a, b; cin >> a >> b;
        pref[a] = 1;
        pref[b+1] = -1;
    }
    for(int i = 1; i <= n;i++){
        pref[i] = pref[i-1] + pref[i];
    }
    sort(pref+1,pref+n+1);
    cout << pref[n/2+1] << endl;
    return 0;
}