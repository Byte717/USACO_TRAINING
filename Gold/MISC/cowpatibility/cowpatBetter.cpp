#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    vector<vector<int>> cows(n);

    for(int i = 0; i < n;i++){
        cows[i].resize(5);
        for(int j = 0; j < 5;j++){
            cin >> cows[i][j];
        }
        sort(all(cows[i]));
    }

    vector<map<array<int,5>, int>> common(5);
    for(int i = 0; i < n;i++){
        common[4][cows[i]]++;

        for(int a = 0; a < 5;a++){
            common[0][{cows[i][a]}]++;
            for(int b = a+1; b < 5;b++){
                
            }
        }
    }
    return 0;
}