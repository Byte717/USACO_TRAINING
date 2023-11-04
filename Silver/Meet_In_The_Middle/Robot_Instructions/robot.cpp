#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <map>

#define all(x) begin(x), end(x)
typedef long long ll;

using namespace std;

using P = pair<ll,ll>;
P operator+(P a, P b) { return {a.first + b.first, a.second + b.second}; }
P operator-(P a, P b) { return {a.first - b.first, a.second - b.second}; }

vector<pair<P,int>> all_subsets(const vector<P> &dirs){
    vector<pair<P,int>> ret{{}};
    for(const P &d : dirs){
        ret.resize(2*ret.size());
        for(int i = 0; i < ret.size()/2;i++){
            ret[i+ret.size()/2] = {ret[i].first + d, ret[i].second + 1};
        }
    }
    // sort(all(ret));
    return ret;
}
struct hsh {
	size_t operator()(const P &p) const {
		return p.first * 239 + p.second;
	}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("robot.in","r", stdin);
    int n; cin >> n;
    P target; cin >> target.first >> target.second;
    vector<P> dirs(n);
    for(auto &[x,y] : dirs){
        cin >> x >> y;
    }
    vector<pair<P,int>> a = all_subsets(vector<P>(dirs.begin(), dirs.begin() + (n/2)));
    vector<pair<P,int>> b = all_subsets(vector<P>(dirs.begin()+(n/2), dirs.end()));
    unordered_map<P,map<int,int>, hsh> firstHalf;
    for(const auto& [offset, num] : a){
        firstHalf[offset][num]++;
    }
    vector<ll> ans(n+1);
    for(const  auto &[offset,num] : b){
        auto it = firstHalf.find(target - offset);
        if(it != firstHalf.end()){
            for(const auto&[num2, ways] : it->second){
                ans[num + num2] += ways;
            }
        }
    }
    for(int i = 1; i <= n;i++){
        cout << ans[i] << endl;
    }
    return 0;
}

