#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;
/*
loop through, and just ignore characters if they follow the pattern.

*/
int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    string s; cin >> s;
    string d;
    ll ans = 0;
    for(int i = 0; i < s.size();i++){
        if(i < 2){
            d += s[i];
        }else if(s[i] == d[d.size()-1] && s[i] == d[d.size()-2]){
            ans++;
        }else if(d.size() > 2 && s[i] == d[d.size()-1] && d[d.size()-2] == d[d.size()-3]){
            ans++;
        }else{
            d+=s[i];
        }
    }
    cout << d << endl;
    return 0;
}