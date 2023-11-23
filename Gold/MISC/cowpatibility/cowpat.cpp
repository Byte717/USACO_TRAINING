#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("cowpatibility.in","r",stdin);
    int n; cin >> n;
    map<int,set<int>> valid;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < 5; j++){
            int x; cin >> x;
            if(valid.find(x) == valid.end()){
                valid[x] = set<int>{i};
            }else{
                valid[x].insert(i);
            }
        }
    }
    int numPairs = 0;
    for(auto &[taste,cows] : valid){
        if(cows.size() > 1){
            numPairs += ((cows.size())*(cows.size()-1))/2;
        }
    }

    cout << ((n*(n-1))/2) - numPairs << endl;
    return 0;
}