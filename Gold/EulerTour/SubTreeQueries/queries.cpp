#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<int> v;
vector<vector<int>> adj;
vector<int> start, endTime;
int t = 0;

template <class T> class SumSegTree{
    private:
    const int DEFAULT = 0;
    vector<T> segTree;
    int len;

    public:
     SumSegTree(int n){
        len = n;
        segTree = vector<T>(2*n,DEFAULT);
     }

     void set(int idx, T val){
        idx += len;
        segTree[idx] = val;
        for(;idx > 1; idx/=2){
            segTree[idx/2] = segTree[idx] + segTree[idx^1];
        }
     }
     T query(int start, int end){
        T ret = DEFAULT;
        start += len; end += len;
        while(start <= end){
            if(start % 2 == 1) ret += segTree[start++];
            if(end % 2 == 1) ret += segTree[--end];
            start /= 2;
            end /= 2;
        }
        return ret;
     }
};

void dfs(int node, int prev){
    start[node] = t;
    t++;
    for(int n : adj[node]){
        if(n != prev) dfs(n,node);
    }
    endTime[node] = t;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("queries.in","r",stdin);

    cin >> n >> q;
    v = vector<int>(n);
    adj = vector<vector<int>>(n);
    for(int i = 0; i < n;i++){
        cin >> v[i];
    }

    for(int i = 0; i < n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }

    start = vector<int>(n,0);
    endTime = vector<int>(n,0);
    dfs(0,-1);

    SumSegTree<long long> s(n);
    for(int i = 0; i < n;i++)s.set(start[i],v[i]);

    for(int i = 0; i < q;i++){
        int type; cin >> type;
        if(type == 1){
            int node, val; cin >> node >> val;
            s.set(start[--node],val);
        }
    }



    return 0;
}