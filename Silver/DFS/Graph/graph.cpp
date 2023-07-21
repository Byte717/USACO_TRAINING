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

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) { 
	return make_pair(a.first + b.first, a.second + b.second);
}

const ll emp = 1e18;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>>  adj(n);
    vector<vector<int>> conected_components;
    vector<bool> visited(n,false);
    for(int i = 0; i < n;i++){
        int a,b,c;cin >> a >> b >> c;
        adj[--a].push_back({--b,c});
        adj[b].push_back({a,c});
    }
    vector<pair<ll,ll>> coeffs(n,{-INF,-INF});
    bool bad = false;
    auto dfs = [&](int node){
        conected_components.back().push_back(node);
        visited[node] = true;
        for(auto& [v,w] : adj[node]){
            if(visited[v]){
                pair<int,int> res = coeffs[node] + coeffs[v];
                if(res.first == 0 && res.second != n){
                    bad = true;
                }else if(res.first != 0 && val == emp){
                    if(res.first == 2){
                        val = w-res.second;
                    }else{
                        val = res.second - w;
                    }
                }else if(res.first != 0 && val != emp){
                    if(res.first == 2 && val != w-res.second){
                        bad = true;
                        return; 
                    }else if(res.first == -2){
                        if(val != res.second - w){
                            bad = true;
                            return;
                        }
                    }
                }
            }else{
                coeffs[v] = {-coeffs[node].first, w-coeffs[node].second};
                dfs(v);
            }
        }
    };

    vector<ll> vals;
    for(int i = 0; i < n;i++){
        if(!visited[i]){
            conected_components.emplace_back();
            coeffs[i] = {1,0};
            dfs(i);
            vals.push_back(i);
        }
    }
    vector<double> ans(n);
    auto out = [&](int u){
        visited[u] = true;
        for(auto& [v,w] : adj[u]){
            if(!visited[v]){
                ans[v] = w - ans[u];
                out(v);
            }
        }
    };
    if(bad){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        for(int i = 0; i < conected_components.size();i++){
            if(vals[i] == emp){
                vector<int> compvals;
                for(int j = 0; j < conected_components[i].size();j++){
					if (coeffs[conncomps[i][j]].first == 1) {
                        compvals.push_back(-coeffs[conncomps[i][j]].second);
					} else {
                        compvals.push_back(coeffs[conncomps[i][j]].second);
					}
                }
	            sort(compvals.begin(), compvals.end());
				ans[conncomps[i][0]] = (double)(compvals[(compvals.size() - 1) / 2] + compvals[compvals.size() / 2]) / (double)2; // x median is the optimal choice
				out(conncomps[i][0]);
			} else { // value of x is finalized
				ans[conncomps[i][0]] = (double)vals[i] / (double)2;
                out(conncomps[i][0]);
            }
        }
        for(int i = 0; i < n;i++){
            cout << fixed << setprecision(6) << ans[i] << " ";
        }
    }
    return 0;
}
