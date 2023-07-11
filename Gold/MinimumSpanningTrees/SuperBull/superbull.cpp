#include <bits/stdc++.h>
#define ll long long

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

class game{
    public:
        int team1, team2;
        int points;
};


bool cmp(game &g1, game &g2){
    return g1.points > g2.points;
}

int n;
vector<int> teams;
vector<game> games;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("superbull.in","r",stdin);  freopen("superbull.out","w",stdout);
    cin >> n;
    teams = vector<int>(n,0);
    for(int &i : teams){
        cin >> i;
    }
    for(int i = 0; i < n;i++){
        for(int j = i+1; j < n;j++){
            game g;
            g.team1 = i;
            g.team2 = j;
            g.points = (teams[i] ^ teams[j]);
            games.push_back(g);
        }
    }

    sort(games.begin(),games.end(), cmp);

    DSU d(n);
    ll ans = 0;
    int eliminated = 0;
    for(game &g : games){
        if(!d.same_set(g.team1,g.team2)){
            d.unite(g.team1,g.team2);
            ans += g.points;
            eliminated++;
        }
        // if(eliminated == n-1){
        //     break;
        // }
    }
    cout << ans << endl;
    return 0;
}