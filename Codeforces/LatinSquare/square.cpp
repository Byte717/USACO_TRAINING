#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;



int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        char sq[3][3];
        pair<int,int> qes;
        for(int i = 0; i < 3;i++){
            for(int j = 0; j < 3;j++){
                cin >> sq[i][j];
                if(sq[i][j] == '?'){
                    qes.first = i;
                    qes.second = j;
                }
            }
        }
        set<char> row;
        for(int j = 0; j < 3; j++){
            row.insert(sq[qes.first][j]);
        }
        set<char> need{'A','B','C'};
        for(auto &x : row){
            if(need.find(x) != need.end()){
                need.erase(need.find(x));
            }
        }
        cout << *need.begin() << endl;
    }
    return 0;
}