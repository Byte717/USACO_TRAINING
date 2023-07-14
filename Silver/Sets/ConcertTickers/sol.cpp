#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, m; cin >> n >> m;
    multiset<int> tickets;
    for(int i = 0; i < n;i++){
        int x; cin >> x;
        tickets.insert(x);
    }
    for(int i = 0; i < m;i++){
        int MXPrice; cin >> MXPrice;
        auto it = tickets.upper_bound(MXPrice);
        if(it == tickets.begin()){
            cout << -1 << endl;
        }else{
            cout << *it << endl;
            tickets.erase(it);
        }
    }
    return 0;
}