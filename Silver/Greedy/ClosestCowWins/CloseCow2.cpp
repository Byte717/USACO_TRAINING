#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

/*
you can split the line into intervals. represented by the underscores
111---X____X____X___X--11
then for each end, 1 cow can take those points

for the ranges in between, keep a track of the tastiness that you get from each in a variable.


What I learned Closest Cow Wins:
    - when segmenting the input in greedy, think of the things you can do for the best solution in each segment
    - consider edge cases for an interval
    - two pointers/ sliding window can be limited to a length.
*/


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    ll k, m, n; cin >> k >> m >> n;
    vector<pair<ll,ll>> points(k+m);
    for(ll i = 0; i < k;i++){
        cin >> points[i].first >> points[i].second;
    }
    for(ll i = k;i < k+m;i++){
        cin >> points[i].first;
        points[i].second = -1;
    }
    sort(all(points));
    vector<ll> increases;
    ll last_i = -1;
    ll sumRange = 0;
    for(ll i = 0; i < k+m;i++){
        if(points[i].second == -1){
            if(last_i == -1){
                increases.push_back(sumRange);
            }else{
                ll currAnsOnes = 0;
                ll bestAnsOnes = 0;
                for(int j = last_i + 1, r = last_i; j < i;j++){ // j is the first patch.
                    while(r+1 < i && (points[r+1].first - points[j].first)*2 < points[i].first - points[last_i].first){// while half of the range isn't covered, move forward
                        currAnsOnes += points[++r].second;
                    }
                    // curr ans ones will contain the maximum to get in the range(j..r) with one cow
                    bestAnsOnes = max(bestAnsOnes, currAnsOnes);
                    currAnsOnes -= points[j].second; 
                }
                increases.push_back(bestAnsOnes); // ans we can get with one cow
                increases.push_back(sumRange - bestAnsOnes); // the second cow gets sum - bestfirst 
            }
            last_i = i;
            sumRange = 0;
        }else{
            sumRange += points[i].second; // left endpoint takes 1 cow
        }
    }
    increases.push_back(sumRange);// endpoint takes 1 cow
    sort(rall(increases));
    increases.resize(n);
    ll ans = 0;
    for(auto val : increases){
        ans+= val;
    }
    cout << ans << endl;
    return 0;
}