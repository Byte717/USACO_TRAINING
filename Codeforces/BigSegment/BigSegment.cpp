#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

// #define debug

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

struct Segment{
    ll l, r;
    int idx;
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef debug
        freopen("bigSegment.in","r",stdin);
    #endif
    int n; cin >> n;
    vector<Segment> segments(n);
    for(int i = 0; i < n;i++){
        cin >> segments[i].l >> segments[i].r;
        segments[i].idx = i+1;
    }
    sort(all(segments),[](const Segment&p1, const Segment&p2){return (p1.r - p1.l + 1) < (p2.r - p2.l + 1);});
    ll left, right,idx;
    ll mnPt = INF, mxPt = -1;
    for(int i = 0; i < n-1;i++){
        left = segments[i].l, right = segments[i].r, idx = segments[i].idx;
        mnPt = min(mnPt, left);
        mxPt = max(mxPt, right);
    }
    left = segments[n-1].l, right = segments[n-1].r, idx = segments[n-1].idx;
    if(left <= mnPt && right >= mxPt){
        cout << idx << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}