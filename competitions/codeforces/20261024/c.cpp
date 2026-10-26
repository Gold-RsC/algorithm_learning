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
const int N = 5e5 + 5;
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
    edge.push_back({head[v], u});
    head[v] = edge.size() - 1;
}


void dfs_deep(vector<int>& d, int u, int in_edge) {
    for (int i = head[u]; ~i; i = edge[i].next) {
        if ((in_edge ^ 1) == i) {
            continue;
        }
        int v = edge[i].to;
        d[v]  = d[u] + 1;
        if (v == 1) {
            continue;
        }
        dfs_deep(d, v, i);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> d(n + 1, 0);
    init_edge();
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        add_edge(x, y);
    }

    dfs_deep(d, n, -1);

    int ans = d[1];
    while (m--) {
        int v;
        cin >> v;
        ans = max(ans, d[v] + 1);
    }
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
