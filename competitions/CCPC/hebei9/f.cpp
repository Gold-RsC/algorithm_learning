#include <iostream>
#include <iomanip>
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
using namespace std;

const int N = 1e6 + 5;

struct Edge {
    int next;
    int to;
};
int weight[N];
int cnt[N];
int tmp_cnt[N];
vector<Edge> edge;

vector<int> head(N, -1);

void add(int u, int v) {
    edge.push_back({head[u], v});
    head[u] = edge.size() - 1;
}
int d[N];

void dfs(int u) {
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;

        cnt[weight[v]] = tmp_cnt[weight[v]] = tmp_cnt[weight[v] + 1] + 1;

        d[v] = d[u] + 1;

        dfs(v);

        tmp_cnt[weight[v]] -= tmp_cnt[weight[v] + 1] + 1;
    }
}

void init() {
    tmp_cnt[weight[1]] = cnt[weight[1]] = 1;

    d[1] = 1;

    dfs(1);
}
void solve() {
    int s, t;
    cin >> s >> t;

    int d_d = d[s] - d[t];

    int d_cnt = cnt[s] - cnt[t];

    int d_weight = weight[t] - weight[s];
}
int n, q;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> weight[i];
    }
    for (int i = 2; i <= n; ++i) {
        int u;
        cin >> u;
        add(u, i);
    }

    init();

    int q;
    cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}
