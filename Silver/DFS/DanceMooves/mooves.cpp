#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

struct DSU{
	#define all(x) begin(x),end(x)
	vector<int> parent, size;
    DSU(int n){parent = vector<int>(n);size = vector<int>(n,1);iota(all(parent),0);}

	int get(int x){while(x != parent[x]) x = parent[x]; return x;}

	bool same_set(int a, int b){return get(a) == get(b);}

	int sz(int x){return size[x];}

	bool link(int a, int b){
		a = get(a), b = get(b);
		if(a == b) return false;
		if(size[a] < size[b]) swap(a,b);
		size[a] += size[b];
		parent[b] = a;
		return true;
	}

};
vector<set<int>> trav, components;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, k; cin >> n >> k;
    trav = vector<set<int>>(n); // a set with what position the Ith cow made
    components = vector<set<int>>(k);
    vector<int> P(n);
    for(int i = 0; i < n;i++){
        P[i] = i;
        trav[i].insert(i);
    }

    for(int i = 0; i < k;i++){
        int a, b; cin >> a >> b;
        a--; b--;
        trav[P[a]].insert(a); // P[a] visitied the Ath position
        trav[P[b]].insert(b);
        swap(P[b], P[a]);
    }
    DSU dsu(n);
    for(int i = 0; i < n;i++){
        dsu.link(i,P[i]);
    }
    for(int i = 0; i < n;i++){
        for(int x : trav[i]){
            components[dsu.get(i)].insert(x);
        }
    }
    for(int i = 0; i < n;i++){
        cout << components[dsu.get(i)].size() << endl;
    }
    return 0;
}