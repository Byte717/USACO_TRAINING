#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std; 

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }//  get parent node

	bool same_set(int a, int b) { return get(a) == get(b); } // if same set

	int size(int x) { return -e[get(x)]; } // size of set

	bool unite(int x, int y) { // put into same group
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};


ll distSquared(ll x1,ll y1,ll x2,ll y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    int n; cin >> n;
    vector<pair<ll,ll>> cows(n);
    for(auto &i : cows){cin >> i.first >> i.second;}

    auto works = [&](ll distance){
        DSU dsu(n);
        for(int i = 0; i < n-1;i++){
            for(int j = i+1; j < n;j++){
                if(distSquared(cows[i].first, cows[i].second,cows[j].first,cows[j].second) <= distance){
                    dsu.unite(i,j);
                }
            }
        }
        return dsu.size(0) == n;
    };



    ll low = 1, high = INF, ans;
    while(low <= high){
        ll mid = low + (high-low)/2;
        if(works(mid)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
