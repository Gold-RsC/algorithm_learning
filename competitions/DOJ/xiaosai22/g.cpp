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
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long

const int N   = 2e6 + 5;
const int MOD = 998244353;

int mod(int x) {
    return x % MOD;
}
int a[N];
int p[N];
int depth[N];
int dp[N];

// ·´Í¼
struct Edge {
    int next;
    int to;
};
vector<Edge> edge;
vector<int> head(N, -1);
void init_edge() {
    edge.clear();
    fill(head.begin(), head.end(), -1);
}
void add_edge(int u, int v) {
    edge.push_back({head[u], v});
    head[u] = edge.size() - 1;
}
int n, q;

void dfs(int u, int s) {
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;

        depth[v]     = depth[u] + 1;
        dp[depth[v]] = max(dp[depth[v]], s + a[v] * a[v]);
        dfs(v, s + a[v] * a[v]);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    init_edge();
    add_edge(0, 1);
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        add_edge(p[i], i);
    }

    dp[0] = 0;
    dfs(0, dp[0]);

    while (q--) {
        int x;
        cin >> x;
        cout << (dp[x] % MOD) << "\n";
    }

    return 0;
}
