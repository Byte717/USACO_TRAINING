#include <bits/stdc++.h>

using namespace std;

int LOG2(int n1){
    int ret = 0; 
    while((1<<(ret)) <= n+1){ret++;}
    return ret;
}

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

/** @return the sum between a and b. */
int sum(vector<ll> &segtree, int a, int b) {
	int c = segtree.size() / 2;
	a += c;
	b += c;
	int s = 0;
	while (a <= b) {
		if (a % 2) s += segtree[a++];
		if (!(b % 2)) s += segtree[b--];
		a /= 2;
		b /= 2;
	}
	return s;
}

/** Increase the element at k by x in the segment tree. */
void add(vector<ll> &segtree, int k, ll x) {
	int c = segtree.size() / 2;
	k += c;
	segtree[k] += x;
	for (k /= 2; k >= 1; k /= 2) {
		segtree[k] = segtree[2 * k] + segtree[2 * k + 1];
	}
}

template<class T> class SegTree{
    const T default = nullptr; // change later
    vector<T> segTree;
    int n;
    public:
        SegTree(int len){
            n = len;
            segTree.resize(2*n);
            std::fill(segTree.begin(), segTree.end(),default);
        }
        void set(int idx, T val){

        }
        T query(int start, int end){
        
        }
};

class LazySegmentTree {
    struct Node {
        int min_val;
        int count;
        int lazy;
    };

    std::vector<Node> tree;
    int n;

    void buildTree(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = {0, 1, 0};
        } else {
            int tm = (tl + tr) / 2;
            buildTree(v*2, tl, tm);
            buildTree(v*2+1, tm+1, tr);
            merge(v);
        }
    }

    void apply(int v, int tl, int tr, int val) {
        tree[v].min_val += val;
        tree[v].lazy += val;
    }

    void push(int v, int tl, int tr) {
        if (tree[v].lazy != 0) {
            int tm = (tl + tr) / 2;
            apply(v*2, tl, tm, tree[v].lazy);
            apply(v*2+1, tm+1, tr, tree[v].lazy);
            tree[v].lazy = 0;
        }
    }

    void merge(int v) {
        if (tree[v*2].min_val < tree[v*2+1].min_val) {
            tree[v].min_val = tree[v*2].min_val;
            tree[v].count = tree[v*2].count;
        } else if (tree[v*2].min_val > tree[v*2+1].min_val) {
            tree[v].min_val = tree[v*2+1].min_val;
            tree[v].count = tree[v*2+1].count;
        } else {
            tree[v].min_val = tree[v*2].min_val;
            tree[v].count = tree[v*2].count + tree[v*2+1].count;
        }
    }

    void updateRange(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r) return;
        if (l == tl && r == tr) {
            apply(v, tl, tr, addend);
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            updateRange(v*2, tl, tm, l, std::min(r, tm), addend);
            updateRange(v*2+1, tm+1, tr, std::max(l, tm+1), r, addend);
            merge(v);
        }
    }

    std::pair<int, int> queryRange(int v, int tl, int tr, int l, int r) {
        if (l > r) return {INT_MAX, 0};
        if (l <= tl && tr <= r) {
            return {tree[v].min_val, tree[v].count};
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        auto left = queryRange(v*2, tl, tm, l, std::min(r, tm));
        auto right = queryRange(v*2+1, tm+1, tr, std::max(l, tm+1), r);
        if (left.first < right.first) {
            return left;
        } else if (left.first > right.first) {
            return right;
        } else {
            return {left.first, left.second + right.second};
        }
    }

public:
    LazySegmentTree(int _n) {
    	n = _n;
        tree.resize(4*n);
        buildTree(1, 0, n-1);
    }

    void updateRange(int l, int r, int addend) {
        updateRange(1, 0, n-1, l, r, addend);
    }

    std::pair<int, int> queryRange(int l, int r) {
        return queryRange(1, 0, n-1, l, r);
    }
    
    int get_maintained(){
    	pair<int, int> res = queryRange(0, n-1);
    	assert(res.first == 0);
    	return n - res.second;
    };
};