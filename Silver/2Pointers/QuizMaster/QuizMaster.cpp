#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

/*
solution: 
use 2 pointers to see if the students between those pointer are collectively smart. We precompute the factors of each number
then we go through factors of the first student and keep a frequency array. while we still have all the topics, move the second pointer forward
keep updating the factors

What I learned QuizMaster:
    - in 2 pointer approach, keep moving the second pointer forward while you still can greedily
    - in number theory, store ther factors.
*/


const ll MAXM = 1e5;
vector<ll> factors[MAXM+5];

void init(){
    for(ll i = 1; i <= MAXM;i++){
        for(ll j = i; j <= MAXM;j += i){
            factors[j].push_back(i);
        }
    }
}

void solve(){
    ll n, m; cin >> n >> m;
    vector<pair<ll,ll>> a(n);
    for(ll i = 0; i < n;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    vector<ll> freq(m+5,0);
    ll currCount = 0;
    ll j = 0;
    ll globalAns = INF;
    for(ll i = 0; i < n;i++){
        for(auto x : factors[a[i].first]){
            if(x > m){
                break;
            }
            if(!freq[x]++){
                currCount++;
            }
        }
        while(currCount == m ){
            ll currAns = a[i].first - a[j].first;
            if(currAns < globalAns){
                globalAns = currAns;
            }
            for(auto x : factors[a[j].first]){
                if(x > m){
                    break;
                }
                if(--freq[x] == 0){
                    currCount--;
                }
            }
            j++;
        }
    }
    if(globalAns >= INF){
        cout << -1 << endl;
    }else{
        cout << globalAns << endl;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("quiz.in","r",stdin);
    init();
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}