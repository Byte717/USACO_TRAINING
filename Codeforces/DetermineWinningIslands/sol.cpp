#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class LazySegmentTree {
    vector<int> tree, lazy;
    int n;

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int L, int R, int val) {
        propagate(node, start, end);
        if (R < start || end < L) {
            return;
        }
        if (L <= start && end <= R) {
            lazy[node] += val;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        updateRange(2 * node + 1, start, mid, L, R, val);
        updateRange(2 * node + 2, mid + 1, end, L, R, val);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int queryRange(int node, int start, int end, int L, int R) {
        propagate(node, start, end);
        if (R < start || end < L) {
            return 0; // Out of range
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftMax = queryRange(2 * node + 1, start, mid, L, R);
        int rightMax = queryRange(2 * node + 2, mid + 1, end, L, R);
        return max(leftMax, rightMax);
    }

public:
    LazySegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(arr, 0, 0, n - 1);
    }

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void update(int L, int R, int val) {
        updateRange(0, 0, n - 1, L, R, val);
    }

    int getMax(int L, int R) {
        return queryRange(0, 0, n - 1, L, R);
    }
};

void solve(int n, int m, vector<pair<int, int>> &alt_bridges) {
    vector<int> dist_elsie(n + 1, 1e9);
    vector<int> bessieDist(n + 1);

    vector<vector<int>> graph(n + 1);
    for (auto &[u, v] : alt_bridges) {
        graph[u].push_back(v);
    }

    queue<int> q;
    dist_elsie[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (dist_elsie[v] > dist_elsie[u] + 1) {
                dist_elsie[v] = dist_elsie[u] + 1;
                q.push(v);
            }
        }
    }

    string result(n - 1, '0');
    
    // Initialize Bessie's distance when she starts from island 1.
    for (int i = 2; i <= n; ++i) {
        bessieDist[i] = i - 1;
    }

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        arr[i] = (dist_elsie[i] > bessieDist[i]) ? 1 : 0;
    }

    LazySegmentTree segTree(arr);

    for (int s = 1; s < n; ++s) {
        if (segTree.getMax(s + 1, n) == 1) {
            result[s - 1] = '0'; // Elsie wins if there's a 1 in the range
        } else {
            result[s - 1] = '1'; // Bessie wins
        }
        // Decrement the range S+1...N-1 by 1 in the segment tree as Bessie starts from a new island.
        segTree.update(s + 1, n, -1);
    }

    cout << result << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> alt_bridges(m);
        for (int i = 0; i < m; ++i) {
            cin >> alt_bridges[i].first >> alt_bridges[i].second;
        }
        solve(n, m, alt_bridges);
    }
    return 0;
}
