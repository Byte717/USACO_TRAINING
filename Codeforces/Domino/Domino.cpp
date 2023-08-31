#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

// #define debug

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


struct Domino{
    int up, down;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef debug
        freopen("","r",stdin);
    #endif
    int n; cin >> n;
    vector<Domino> d(n);
    int sumUp = 0, sumDown = 0;
    for(int i = 0; i < n;i++){
        cin >> d[i].up >> d[i].down;
        sumUp += d[i].up;
        sumDown += d[i].down;
    }
    if(sumDown %2 == 0 && sumUp %2 == 0){
        cout << 0 << endl;
        return 0;
    }
    if(sumDown % 2 != sumUp % 2){
        cout << -1 << endl;
        return 0;
    }
    for(auto &[x,y] : d){
        if(x % 2  != y % 2){
            cout << 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}