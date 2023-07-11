#include <bits/stdc++.h>

using namespace std; 

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

struct vid{
    int a, b;
    int rel;
};
int n, q;
vector<vid> input;
vector<pair<int,int>> query;

bool cmp(vid &v1,vid &v2){
    return v1.rel < v2.rel;
}

void solve(){
    sort(input.begin(),input.end(),cmp);
    sort(query.begin(),query.end());

    DSU d(n);
    int idx = 0;
    for(auto q : query){
        int k = q.first, v = q.second;
        while(idx < input.size() && input[idx].rel < k){
            d.unite(input[idx].a, input[idx].b);
            idx++;
        }
        cout << d.size(v)-1 << endl;
    }

}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("mootube.in","r",stdin);
    cin >> n >> q;
    input = vector<vid>(n);
    // query.resize(q);
    for(int i = 0; i < n;i++){
        int p,q,r; cin >> p >> q >> r;
        input[i] = {--p,--q,r};
    }
    for(int i = 0; i < q;i++){
        int k, v; cin >> k >> v;
        query.push_back({k,v});
    }
    solve();
    

    return 0;
}