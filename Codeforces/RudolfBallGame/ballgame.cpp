#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// #pragma GCC optimize("O3","unroll-loops")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

struct Throw{
    int dist;
    char dir;
};

int n, m,x;
vector<Throw> moves;
vector<int> candidates;

void solve(){
    cin >> n >> m >> x;
    moves.resize(m);
    for(int i = 0; i < m;i++){
        cin >> moves[i].dist >> moves[i].dir;
    }
    set<int> posible = {x};
    for(int i = 0; i < m;i++){
        set<int> nextSet;
        for(auto &j : posible){
            if(moves[i].dir == '0' || moves[i].dir == '?'){
                nextSet.insert((j+moves[i].dist-1)%n+1);// cw
            }
            if(moves[i].dir == '1' || moves[i].dir == '?'){
                nextSet.insert((j-moves[i].dist-1+n)%n+1);// ccw
            }
        }
        posible = nextSet;
    }
    cout << posible.size() << endl;
    for(auto &x : posible){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("ballgame.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}