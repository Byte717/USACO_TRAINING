#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

// #define debug

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

struct Exam{
    ll a, b;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef debug
        freopen("vanyaExams.in","r",stdin);
    #endif
    ll n, r, avg; cin >> n >> r >> avg;
    ll sum = 0;
    vector<Exam> exams(n);
    for(ll i = 0; i < n;i++){
        cin >> exams[i].a >> exams[i].b;
        sum += exams[i].a;
    }
    ll needed = (avg*n) - sum;
    if(needed <= 0){
        cout << 0 << endl;
        return 0;
    }
    sort(all(exams),[](const Exam &e1, const Exam &e2){
        if(e1.b == e2.b) return e1.a < e2.a;   
        return e1.b < e2.b;
    });
    ll ans = 0;
    ll pt = 0;
    while(needed > 0 && pt < n){
        if(exams[pt].a == r){
            pt++;
            continue;
        }
        ll ptsGained = min(r - exams[pt].a, needed);
        needed -= ptsGained;
        ans += (ptsGained*exams[pt].b);
        pt++;
    }
    cout << ans << endl;
    return 0;
}