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

    string s, t; cin >> s >> t;
    vector<int> freqS(26,0), freqT(26,0);
    for(char i = 'a'; i <= 'z';i++){
        for(char x : s){
            if(x == i){
                freqS[i-'a']++;
            }
        }
        for(char x : t){
            if(x == i){
                freqT[i-'a']++;
            }
        }
    }
    
    int q; cin >> q;


    return 0;
}