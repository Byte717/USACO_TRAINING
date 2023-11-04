#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


/*

What i learned Xenia And Bits:
    - for queries, think segment trees.
    - segment trees can do other queries as well

*/



template <class T> class SegTree{
    private:
    const int DEFAULT = 0;
    vector<T> segTree;
    int len;

    public:
     SegTree(int n){
        len = n;
        segTree = vector<T>(2*n,DEFAULT);
     }
    
     void set(int idx, T val){
        idx += len;
        segTree[idx] = val;
        int count = 0;
        for(;idx > 1; idx/=2){
            if(count % 2){ // odd
                segTree[idx/2] = segTree[idx] ^ segTree[idx^1];
            }else{ // even
                segTree[idx/2] = segTree[idx] | segTree[idx^1];
            }
            count++;
            // segTree[idx/2] = segTree[idx] + segTree[idx^1];
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
     
     T getTop(){
        return query(0,len);
     }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("xeniaBit.in","r",stdin);
    ll n, m; cin >> n >> m;
    SegTree<ll> seg((1<<n));
    vector<ll> a((1 << n));
    for(int i = 0; i < (1<<n);i++){
        cin >> a[i];
        seg.set(i, a[i]);
    }
    while(m--){
        ll p, b; cin >> p >> b;
        seg.set(p-1,b);
        cout << seg.getTop()/2 << endl;
    }
    return 0;
}