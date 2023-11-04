#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

vector<int> pref, suff;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, q; cin >> n >> q;
    pref = vector<int>(n+1,0); suff = vector<int>(n+1,0);
    string s; cin >> s;

    stack<char> active;
    for(int i = 0; i < n;i++){
        pref[i+1] = pref[i];
        while(!active.empty() && active.top() > s[i]) active.pop();
        if(active.empty() || active.top() < s[i]){
            active.push(s[i]);
            pref[i+1]++;
        }
    }

    active = stack<char>{};
    reverse(all(s));
    for(int i = 0; i < n;i++){
        suff[i+1] = suff[i];
        while(!active.empty() && active.top() > s[i]) active.pop();
        if(active.empty() || active.top() < s[i]){
            active.push(s[i]);
            suff[i+1]++;
        }
    }

    while(q--){
        int x, y; cin >> x >> y;
        cout << pref[x-1] + suff[n-y] << endl;
    }
    return 0;
}