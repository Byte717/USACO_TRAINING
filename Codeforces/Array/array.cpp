#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("array.in","r",stdin);
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    vector<int> cnt(1e5,0);
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    set<int> s;
    int finish = -1;
    for(int i = 0; i < n;i++){
        s.insert(arr[i]);
        if(s.size() == k){
            finish = i;
            break;
        }
    }
    if(s.size() < k){
        cout << "-1 -1" << endl;
        return 0;
    }
    set<int> s1;
    int start = -1;
    for(int i = finish; i >= 0;i--){
        s1.insert(arr[i]);
        if(s1.size() == k){
            start = i;
            break;
        }
    }
    cout << start + 1 << ' ' << finish + 1 << endl;
    return 0;
}