#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

vector<ll> nums;
void calc(){
    ll k = 0;
    while((k*(k+1))/2 <= 1e9){
        nums.push_back((k*(k+1))/2);
        k++;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    calc();
    nums.erase(nums.begin());
    ll n; cin >> n;
    if(n == 1 || n == 3 || n == 10){
        cout << "NO" << endl;
        return 0;
    }
    set<ll> s;
    for(int i = 0; i < nums.size();i++){
        if(s.count(n-nums[i]) != 0 || 2 * nums[i] == n){
            cout << "YES" << endl;
            return 0;
        }else{
            s.insert(nums[i]);
        }
    }
    cout << "NO" << endl;
    return 0;
}