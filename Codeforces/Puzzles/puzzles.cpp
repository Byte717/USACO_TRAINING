#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;



int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("puzzles.in","r",stdin);
    int n, m; cin >> n >> m;
    vector<int> puzzles(m);
    for(int i = 0; i < m;i++){
        cin >> puzzles[i];
    }
    sort(all(puzzles));
    int MN = INF;
    for(int b = 0; b + n-1 < m;b++){
        MN = min(MN, puzzles[b+n-1] - puzzles[b]);
    }
    cout << MN << endl;
    return 0;
}