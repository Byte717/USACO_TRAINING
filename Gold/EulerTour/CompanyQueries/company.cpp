#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};


template <class T> class MinSegTree{
    private:
    const int DEFAULT = 1e5;
    vector<T> segTree;
    int len;

    public:
     MinSegTree(int n){
        len = n;
        segTree = vector<T>(2*n,DEFAULT);
     }

     void set(int idx, T val){
        idx += len;
        segTree[idx] = val;
        for(;idx > 1; idx/=2){
            segTree[idx/2] = min(segTree[idx], segTree[idx ^ 1]);
        }
     }

     T query(int start, int end){
        T ret = DEFAULT;
        start += len; end += len;
        while(start <= end){
            if(start % 2 == 1) ret = min(ret,segTree[start++]);
            if(end % 2 == 1) ret = min(ret, segTree[--end]);
            start /= 2;
            end /= 2;
        }
        return ret;
     }
};

vector<vector<int>> graph;
vector<int> minIdx;
vector<pair<int,int>> tourData;
int TIME = 0;

void dfs(int node,int parent){
    tourData.push_back({node,TIME});
    TIME++;
    for(int i : graph[node]){
        if(i != parent){
            dfs(i,node);
            tourData.push_back({node,TIME});    
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("cq.in","r",stdin);
    int n, q; cin >> n >> q;
    graph = vector<vector<int>>(n);
    minIdx = vector<int>(n, 1e5);
    for(int i = 1; i < n;i++){
        int a; cin >> a;
        graph[i].push_back(--a);
        graph[a].push_back(i);
    }
    dfs(0,-1);

    MinSegTree<int> seg(tourData.size());
    for(int i = 0; i < tourData.size();i++){
        seg.set(i,tourData[i].second);
    }



    // THIS IS BAD 
    // while(q--){
    //     int a, b; cin >> a >> b;
    //     a--;b--;
    //     if(a == 0 || b == 0){
    //         cout << 1 << endl;
    //         continue;
    //     }
    //     int aIdx = -1;
    //     for(int i = 0; i < tourData.size();i++){
    //         if(tourData[i].first == a){
    //             aIdx = i;
    //             break;
    //         }
    //     }
    //     int bIdx = -1;
    //     for(int i = 0; i < tourData.size();i++){
    //         if(tourData[i].first == b){
    //             bIdx = i;
    //             break;
    //         }
    //     }
    //     int MIN = INT32_MAX, minIdx = -1;
    //     for(int i = min(aIdx,bIdx); i < max(aIdx,bIdx);i++){
    //         if(tourData[i].second < MIN){
    //             MIN = tourData[i].second;
    //             minIdx = i;
    //         }
    //     }
    //     cout << tourData[minIdx].first << endl;
    // }
    return 0;
}