#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std; 

template<class T> class utilites{
    int n;
    bool debug;
    int m;

    public:
        const int dirX[] = {-1, 0, 1, 0};
        const int dirY[] = {0, 1, 0, -1};

        utilites(const int &n1, const bool &d, const int &m1= -1){
            n = n1;
            debug = d;
            m = (m1 > 0) ? m1 : n;
        }

        int LOG2(const int &n){
            int ret = 0; 
            while((1<<(ret+1)) <= n){ret++;}
            return ret;
        }
        
        bool InBounds(const T &x1, const T &y1){return x1 < n && x1 >= 0 && y1 >= 0 && y1 < m;}

        void SetIo(const string &name = ""){
            cin.tie(0)->sync_with_stdio(0);
            if(debug && name.size()){
                freopen(name,"r",stdin);
            }
        }
        vector<T> coordinateCompression(vector<T> a){
            // idx of each element in a sorted list;
            // to be implemented later;
        }

        unsigned long long distanceSquared(const T &x1, const T &y1, const T &x2, const T &y2){
            return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        }
        
};
