#include <bits/stdc++.h>
#define INF 1e9
#define mod 1e9+7

typedef long long ll;

using namespace std; 

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

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("RU.in","r",stdin);
    int n, q; cin >> n >> q;
    vector<ll> arr(n+1);
    for(int i = 1; i <= n;i++){
        cin >> arr[i];
    }
    arr[0] = 0;
    vector<ll> diff(n+1)
    for(int i = 1;i <= n;i++){
        diff[i] = arr[i]-arr[i-1];
    }
    SumSegTree<ll> seg(n+1);
    for(int i = 1; i <= n; i++){
        seg.set
    }
    return 0;
}