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
struct Edge {
    int next;
    int to;
};
vector<Edge> edge;
vector<int> head;
vector<int> sz;
vector<int> mx;
int a[N];
void init_edge(int n) {
    edge.clear();
    head.assign(n + 1, -1);
    sz.assign(n + 1, 1);
    mx.assign(n + 1, 1);
}
void add_edge(int u, int v) {
    edge.push_back({head[u], v});
    head[u] = edge.size() - 1;
}

void dfs(int u, int fa) {
    mx[u] = max(mx[u], a[u]);
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa) {
            continue;
        }
        dfs(v, u);
        sz[u] += sz[v];
        mx[u] = max(mx[v], mx[u]);
    }
}

int jc[N];
int inv_jc[N];
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
int inv(int a) {
    return qpow(a, MOD - 2);
}
int C(int n, int m) {
    return jc[n] * inv_jc[m] % MOD * inv_jc[n - m] % MOD;
}


int max_root;
int max_value;

int n, k;

int ans;
void dfs2(int u, int fa) {
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa) {
            continue;
        }
        dfs2(v, u);

        if (k >= sz[v] - 1) {
            int t = C(n - 1 - sz[v], k - sz[v] + 1) * mx[v] % MOD;
            ans   = (ans + t) % MOD;
        }
        if (k >= n - 1 - sz[v]) {
            int t = C(sz[v] - 1, k - n + 1 + sz[v]) * mx[max_root] % MOD;
            ans   = (ans + t) % MOD;
        }
    }
}
void solve() {
    max_root  = 0;
    max_value = 0;
    ans       = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (max_value < a[i]) {
            max_root  = i;
            max_value = a[i];
        }
    }
    init_edge(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(max_root, -1);
    dfs2(max_root, -1);
    ans = ans * inv(C(n - 1, k)) % MOD;
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    jc[0] = 1;
    for (int i = 1; i < N; ++i) {
        jc[i] = jc[i - 1] * i % MOD;
    }
    inv_jc[N - 1] = inv(jc[N - 1]);
    for (int i = N - 1; i > 0; --i) {
        inv_jc[i - 1] = inv_jc[i] * i % MOD;
    }


    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
