#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <string>
#include <numeric>
#include <algorithm>
#include <limits>
#include <iterator>
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long
const int N = 1e5 + 5;
struct Edge {
    int next;
    int to;
};
vector<Edge> edge;
vector<int> head;
void init_edge(int n) {
    edge.clear();
    head.assign(n + 1, -1);
}
void __add_edge(int u, int v) {
    edge.push_back({head[u], v});
    head[u] = edge.size() - 1;
}
void add_edge(int u, int v) {
    __add_edge(u, v);
    __add_edge(v, u);
}
/**
 * @brief 子树权值最大值
 * @note
 *   1. 全树最大权值节点r很重要，每个节点朝向节点r的子树最大值是r的权值
 *   2. 若无update操作，则以r为根最合适
 *      此时对于每一条边来说
 *      朝向根的子树权值最大值为根
 *      朝向叶子的子树权值最大值正常求
 *   3. 若需要动态维护子树最大值，则可用dfs序+线段树
 *      u的子树对应区间: [dfn[u], dfn[u] + sz[u] - 1]
 */
int a[N];  // 每个节点的权值
int dfn[N];
int dfs_list[N];
int sz[N];
int timestamp;
void dfs(int u, int fa) {
    dfn[u]              = ++timestamp;
    dfs_list[timestamp] = u;
    sz[u]               = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa) {
            continue;
        }
        dfs(v, u);
        sz[u] += sz[v];
    }
}
struct Interval {
    int left, right;
    int node;

    inline int mid(void) const {
        return left + (right - left) / 2;
    }
    inline int len(void) const {
        return right - left + 1;
    }

    inline int left_node(void) const {
        return node * 2;
    }
    inline int right_node(void) const {
        return node * 2 + 1;
    }

    inline int left_len(void) const {
        return mid() - left + 1;
    }
    inline int right_len(void) const {
        return right - mid();
    }

    inline Interval left_interval(void) const {
        return {left, mid(), node * 2};
    }
    inline Interval right_interval(void) const {
        return {mid() + 1, right, node * 2 + 1};
    }

    inline bool is_leaf(void) const {
        return left == right;
    }
    inline bool is_in(int find_left, int find_right) const {
        return find_left <= left && find_right >= right;
    }
};
struct SegTree {
    vector<int> d;
    vector<int> lazy;
    SegTree(int n) {
        d.assign((n + 1) << 2, 0);
        lazy.assign((n + 1) << 2, 0);
    }
    void push_up(Interval interval) {
        if (!interval.is_leaf()) {
            d[interval.node] = max(d[interval.left_node()], d[interval.right_node()]);
        }
    }
    void build(Interval interval) {
        if (interval.is_leaf()) {
            d[interval.node] = a[dfs_list[interval.left]];
            return;
        }
        build(interval.left_interval());
        build(interval.right_interval());
        push_up(interval);
    }
    void push_down(Interval interval) {
        if (!interval.is_leaf() && lazy[interval.node]) {
            d[interval.left_node()]     = max(d[interval.left_node()], lazy[interval.node]);
            d[interval.right_node()]    = max(d[interval.right_node()], lazy[interval.node]);
            lazy[interval.left_node()]  = max(lazy[interval.left_node()], lazy[interval.node]);
            lazy[interval.right_node()] = max(lazy[interval.right_node()], lazy[interval.node]);
            lazy[interval.node]         = 0;
        }
    }
    void update(Interval interval, int find_left, int find_right, int val) {
        if (interval.is_in(find_left, find_right)) {
            d[interval.node]    = max(d[interval.node], val);
            lazy[interval.node] = max(lazy[interval.node], val);
            return;
        }
        push_down(interval);
        int mid = interval.mid();
        if (find_left <= mid) {
            update(interval.left_interval(), find_left, find_right, val);
        }
        if (find_right > mid) {
            update(interval.right_interval(), find_left, find_right, val);
        }
        push_up(interval);
    }
    int query(Interval interval, int find_left, int find_right) {
        if (find_left > find_right) {
            return 0;
        }
        if (interval.is_in(find_left, find_right)) {
            return d[interval.node];
        }
        push_down(interval);
        int mid = interval.mid();
        int ans = 0;
        if (find_left <= mid) {
            ans = max(ans, query(interval.left_interval(), find_left, find_right));
        }
        if (find_right > mid) {
            ans = max(ans, query(interval.right_interval(), find_left, find_right));
        }
        return ans;
    }
};
SegTree seg;
int n;
void init() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    init_edge(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    dfs(1, -1);
    seg.build({1, n, 1});
}
void update_subtree(int u, int val) {
    seg.update({1, n, 1}, dfn[u], dfn[u] + sz[u] - 1, val);
}
int query_nonsubtree(int u) {
    return max(seg.query({1, n, 1}, 1, dfn[u] - 1), seg.query({1, n, 1}, dfn[u] + sz[u], n));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
