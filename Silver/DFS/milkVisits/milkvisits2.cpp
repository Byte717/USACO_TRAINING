#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
vector<char> type;
struct dsu{ // standard dsu implementation
	vector<int> parent, size;
    dsu(int n){
        parent = vector<int>(n);
        size = vector<int>(n,1);
        iota(all(parent),0);
    }

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



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    int n,m; cin >> n >> m;
    type = vector<char>(n);
    for(int i = 0; i < n;i++){
        cin >> type[i];
    }
    dsu d(n);
    vector<int> ans(m,0);

    for(int i = 0; i < n-1;i++){
        int a, b; cin >> a >> b;
        a--; b--;
        if(type[d.get(a)] == type[d.get(b)]){
            d.link(a,b);
        } // only link 2 nodes if they are of the same type
    }

    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        a--;b--;
        char x; cin >> x;
        if(d.same_set(a,b)){ // if they are in the same group
            if(type[a]== x && type[b] == x){ // if the group has the type that the farmer wants
                ans[i] = 1;
            }else{
                ans[i] = 0;
            }
        }else{
            ans[i] = 1;
        }
    }

    for(int i = 0; i < m;i++){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
