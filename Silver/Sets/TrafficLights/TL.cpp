#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("TL.in","r",stdin);
    int x, n; cin >> x >> n;
    multiset<int> dists{x};
    set<int> lights{0,x};
    for(int i = 0; i < n;i++){
        int pos; cin >> pos;
        auto Greater = lights.upper_bound(pos);
        auto Lower = Greater;
        --Lower;
        dists.erase(dists.find(*Greater-*Lower));
        dists.insert(pos-(*Lower));
        dists.insert((*Greater)-pos);
        lights.insert(pos);
        cout << *(--dists.end()) << endl;
    }

    return 0;
}