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
const int N   = 4e5 + 5;
const int MOD = 998244353;
vector<vector<int>> g;
void init_edge(int n) {
    g.assign(n + 1, vector<int>());
}
void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}
int n, k;
vector<int> a;
int qpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
int jc[N];
int invjc[N];
int C(int n, int m) {
    return jc[n] * invjc[m] % MOD * invjc[n - m] % MOD;
}

vector<int> dfsxu;
vector<int> ll;
vector<int> rr;
vector<int> mx;
vector<int> sz;
void dfs(int u, int fa) {
    sz[u] = 1;
    mx[u] = a[u];
    dfsxu.push_back(u);

    ll[u] = dfsxu.size() - 1;
    for (auto v : g[u]) {
        if (v == fa) {
            continue;
        }
        dfs(v, u);
        mx[u] = max(mx[u], mx[v]);
        sz[u] += sz[v];
    }
    rr[u] = dfsxu.size() - 1;
}
struct SegTree {
    vector<int> d;
    SegTree(int n) {
        d.assign((n + 1) << 2, 0);
        build(1, n, 1);
    }
    void push_up(int l, int r, int node) {
        if (l != r) {
            d[node] = max(d[node << 1], d[node << 1 | 1]);
        }
    }
    void build(int l, int r, int node) {
        if (l == r) {
            d[node] = a[dfsxu[l]];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, node << 1);
        build(mid + 1, r, node << 1 | 1);
        push_up(l, r, node);
    }

    int query(int l, int r, int node, int ql, int qr) {
        if (ql > qr) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return d[node];
        }
        int mid = (l + r) / 2;
        int ans = 0;
        if (ql <= mid) {
            ans = max(ans, query(l, mid, node << 1, ql, qr));
        }
        if (qr > mid) {
            ans = max(ans, query(mid + 1, r, node << 1 | 1, ql, qr));
        }
        return ans;
    }
};

int ans;
void dfs2(int u, int fa, SegTree& s) {
    for (auto v : g[u]) {
        if (v == fa) {
            continue;
        }
        dfs2(v, u, s);

        if (k >= sz[v] - 1) {
            int t = C(n - 1 - sz[v], k - sz[v] + 1) * mx[v] % MOD;
            ans   = (ans + t) % MOD;
        }
        if (k >= n - 1 - sz[v]) {
            int t = C(sz[v] - 1, k - n + 1 + sz[v]) *
                    max(s.query(1, n, 1, 1, ll[v] - 1), s.query(1, n, 1, rr[v] + 1, n)) % MOD;
            ans   = (ans + t) % MOD;
        }
    }
}

void solve() {
    ans = 0;
    cin >> n >> k;
    dfsxu.clear();
    dfsxu.push_back(0);
    a.assign(n + 1, 0);
    mx.assign(n + 1, 0);
    sz.assign(n + 1, 1);
    ll.assign(n + 1, 0);
    rr.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    init_edge(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    dfs(1, 0);
    SegTree s(n);
    dfs2(1, 0, s);
    ans = ans * qpow(C(n - 1, k), MOD - 2) % MOD;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    jc[0] = 1;
    for (int i = 1; i < N; ++i) {
        jc[i] = jc[i - 1] * i % MOD;
    }
    invjc[N - 1] = qpow(jc[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i) {
        invjc[i] = invjc[i + 1] * (i + 1) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
