#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

const int dX[4] = {-1, 0, 1, 0};
const int dY[4] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i = 0; i < n;i++) for(int j = 0; j < n;j++){
        cin >> grid[i][j];
    }
    function<bool(int,int)> inBound = [&](int i,int j){
    return !(i < 0 || i >= n || j < 0 || j >= n);
    };
    vector<vector<int>> regions(n, vector<int>(n));
    vector<vector<pair<int,int>>> regionCells;

    int oneBiggest = 0;
    vector<vector<bool>> visited(n,vector<bool>(n));

    for(int r = 0; r < n;r++){
        for(int c = 0; c < n;c++){
            if(visited[r][c]) continue;

            int currRegion = regionCells.size();

            vector<pair<int,int>> contained, frontier{{r,c}};

            visited[r][c] = true;

            while(!frontier.empty()){
                auto curr = frontier.back();
                frontier.pop_back();
                contained.push_back(curr);
                regions[curr.first][curr.second] = currRegion;

                for(int i = 0; i < 4;i++){
                    int newX = r + dX[i], newY = c + dY[i];
                    if(inBound(newX,newY) && !visited[newX][newY] && grid[r][c] == grid[newX][newY]){
                        visited[newX][newY] = true;
                        frontier.push_back({newX, newY});
                    }
                }
            }
            oneBiggest = max(oneBiggest, (int)contained.size());
            regionCells.push_back(contained);
        }
    }
    vector<set<int>> adjRegions(regionCells.size());
    for(const auto & reg : regionCells){
        for(const auto &[r,c] : reg){
            for(int i = 0; i < 4;i++){
                int newX = r + dX[i], newY = c + dY[i];
                if(inBound(newX,newY) && regions[r][c] != regions[newX][newY]){
                    adjRegions[regions[r][c]].insert(regions[newX][newY]);
                }
            }
        }
    }

    auto regionId = [&](int r){
        return grid[regionCells[r][0].first][regionCells[r][0].second];
    };

    map<pair<int,int>, set<int>> seen;
    int twoBiggest = oneBiggest;
    for(int r1 = 0; r1 < regionCells.size();r1++){
        for(int r2 : adjRegions[r1]){
            pair<int,int> valid{regionId(r1), regionId(r2)};
            if(valid.first > valid.second){
                swap(valid.first,valid.second);
            }
            if(seen[valid].count(r1)) continue;
            
            int twoSize = 0;
            vector<int> frontier{r1};
            vector<bool> currVis(regionCells.size());
            currVis[r1] = true;
            while(!frontier.empty()){
                int curr = frontier.back();
                frontier.pop_back();
                twoSize += regionCells[curr].size();
                seen[valid].insert(curr);

                for(int nr : adjRegions[curr]){
                    int nig = regionId(nr);
                    if(!currVis[nr] && (valid.first == nid || valid.second == nid)){
                        currVis[nr] = true; 
                        frontier.push_back(nr);
                    }
                }
            }
            twoBiggest= max(twoBiggest, twoSize);
        }
    }
    cout << oneBiggest << endl;
    cout << twoBiggest << endl;
    return 0;
}