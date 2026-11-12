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

int get_max(int a) {
    int p = 0;
    while (a) {
        p = max(p, a % 10);
        a /= 10;
    }
    return p;
}
int n;
int a[N];

int mod[10][N];
int mx[N];

struct Seg {
    vector<int> d;
    Seg(int n)
        : d((n + 1) << 2, 0) {
    }
    void push_up(int l, int r, int node) {
        if (l < r) {
            d[node] = d[node << 1] + d[node << 1 | 1];
        }
    }
    void build(int mod[], int j, int l, int r, int node) {
        if (l == r) {
            d[node] = (mod[l] == j);
            return;
        }
        int mid = (l + r) / 2;
        build(mod, j, l, mid, node << 1);
        build(mod, j, mid + 1, r, node << 1 | 1);
        push_up(l, r, node);
    }
    int query(int l, int r, int node, int find_left, int find_right) {
        if (find_left > find_right) {
            return 0;
        }
        if (find_left <= l && r <= find_right) {
            return d[node];
        }
        int mid = (l + r) / 2;
        int ans = 0;
        if (find_left <= mid) {
            ans = ans + query(l, mid, node << 1, find_left, find_right);
        }
        if (find_right > mid) {
            ans = ans + query(mid + 1, r, node << 1 | 1, find_left, find_right);
        }
        return ans;
    }
};

struct Node {
    int left, right;
    int parent;
};
struct CartesianTree {
    vector<Node> node;
    int root;
    CartesianTree() {
        node.assign(n + 1, {0, 0, 0});
        root = 0;
    }
    int build() {
        vector<int> stk(n + 1, 0);
        int top = 0;
        for (int i = 1; i <= n; ++i) {
            int k = top;
            while (k && mx[stk[k]] < mx[i]) {
                --k;
            }
            if (k) {
                node[stk[k]].right = i;
                node[i].parent     = stk[k];
            }
            else {
                root = i;
            }
            if (k < top) {
                node[i].left            = stk[k + 1];
                node[stk[k + 1]].parent = i;
            }
            stk[++k] = i;
            top      = k;
        }
        return root;
    }
};
int ans;
int sz[N];

void dfs(CartesianTree& tree, int u) {
    if (!u) {
        return;
    }
    sz[u] = 1;
    dfs(tree, tree.node[u].left);
    dfs(tree, tree.node[u].right);
    sz[u] += sz[tree.node[u].left];
    sz[u] += sz[tree.node[u].right];
}
void dfs2(CartesianTree& tree, int u, vector<vector<Seg>>& seg) {
    if (!u) {
        return;
    }
    int m = mx[u];
    int l = tree.node[u].left;
    int r = tree.node[u].right;
    for (int i = 0; i < m; ++i) {
        ans += seg[m][i].query(0, n, 1, u - sz[l] - 1, u - 1) * seg[m][i].query(0, n, 1, u, u + sz[r]);
    }
    dfs2(tree, l, seg);
    dfs2(tree, r, seg);
}
void solve() {
    ans = 0;
    cin >> n;
    int pre = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre += a[i];
        for (int j = 1; j <= 9; ++j) {
            mod[j][i] = pre % j;
        }
        mx[i] = get_max(a[i]);
    }
    vector<vector<Seg>> seg(10, vector<Seg>(10, Seg(n)));
    for (int i = 1; i <= 9; ++i) {
        for (int j = 0; j < i; ++j) {
            seg[i][j].build(mod[i], j, 0, n, 1);
        }
    }
    CartesianTree tree;
    int root = tree.build();
    dfs(tree, root);
    dfs2(tree, root, seg);
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
