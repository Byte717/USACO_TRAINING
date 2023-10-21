#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int n;
vector<int> x;
set<multiset<int>> sols;


void check(int sum, int b, int c){
    int a = sum - b - c;
    set<int> s{0,a,b,c,a + b, b+c,a+c,a+b+c};
    for(int t : x){
        if(!s.count(t))return;
    }
    sols.insert({a,b,c});
}


void test(int sum){ // test if two elements work as A and B
    set<int> candidates;
    for(int t : x){ // Find candidates for C
        if(t > sum){
            return;
        }
        if(t == 0 || t == sum) continue;
        candidates.insert(min(t,sum-t));
    }
    int a = *begin(candidates), b = *next(begin(candidates));
    check(sum, a,b);
    check(sum,a,sum-b);

}

void solve(){
    cin >> n;
    x.resize(n);
    for(int i = 0; i < n;i++){
        cin >> x[i];
    }
    sols.clear();
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            test(x[i]+x[j]);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}