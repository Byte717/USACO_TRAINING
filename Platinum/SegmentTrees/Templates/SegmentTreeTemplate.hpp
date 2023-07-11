#include <bits/stdc++.h>

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

template <class T> class MaxSegTree{
    private:
    const int DEFAULT = -1e4;
    vector<T> segTree;
    int len;

    public:
     MaxSegTree(int n){
        len = n;
        segTree = vector<T>(2*n,DEFAULT);
     }

     void set(int idx, T val){
        idx += len;
        segTree[idx] = val;
        for(;idx > 1; idx/=2){
            segTree[idx/2] = max(segTree[idx] , segTree[idx^1]);
        }
     }
     T query(int start, int end){
        T ret = DEFAULT;
        start += len; end += len;
        while(start <= end){
            if(start % 2 == 1) ret = max(ret,segTree[start++]);
            if(end % 2 == 1) ret = max(ret,segTree[--end]);
            start /= 2;
            end /= 2;
        }
     }
};