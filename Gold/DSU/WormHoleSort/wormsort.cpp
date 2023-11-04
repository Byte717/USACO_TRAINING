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

struct wormHole{
    int a, b, w;
    bool operator<(const wormHole &y) {return w < y.w;}

};

vector<int> order;
vector<wormHole> paths;
int n, m;

bool works(int mid){
    DSU d(n);
    for(wormHole w : paths){
        if(w.w >= mid){
            d.unite(w.a,w.b);
        }
    }
    bool canSort = true;

    for(int i = 0; i < n;i++){
        if(!d.same_set(i,order[i])){
            canSort = false;
            break;
        }
    }
    return canSort;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("wormsort.in","r",stdin);
    cin >> n >> m;
    order = vector<int>(n);
    paths = vector<wormHole>(m);

    int maxWidth = -1;
    for(int i = 0; i < n;i++){
        cin >> order[i];
        order[i]--;
    }

    for(wormHole &w : paths){
        cin >> w.a >> w.b >> w.w;
        w.a--;
        w.b--;
        maxWidth = max(maxWidth, w.w);
    }

    int low = 0, high = maxWidth + 1, mid, ans;

    while(low <= high){
        mid = (low + high)/2;
        if(works(mid)){
            ans = mid;
            low = mid+1;
        }else{
            high = mid -1;
        }
    }
    cout << ans << endl;




    return 0;
}