#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>


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

struct road{
    int a, b, c;
};

bool cmp(road &r1, road &r2){
    return r1.c < r2.c;
}

int n, m;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("Road.in","r",stdin);
    cin >> n >> m;
    vector<road> roads(m);

    for(road &r : roads){
        cin >> r.a >> r.b >> r.c;
    }

    sort(roads.begin(),roads.end(),cmp);

    DSU d(n);
    int ans = 0;

    for(road &r : roads){
        if(!d.same_set(r.a, r.b)){
            ans += r.c;
            d.unite(r.a,r.b);
        }
    }
    cout << ans << endl;
    return 0;
}