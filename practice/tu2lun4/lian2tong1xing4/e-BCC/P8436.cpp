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
const int N = 4e6 + 5;

int n, m;
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

int dfn[N];
int low[N];
int timer;
bool is_bridge[N];
void tarjan(int u, int parent_edge) {
    dfn[u] = low[u] = ++timer;

    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (i == (parent_edge ^ 1)) {
            continue;
        }

        if (!dfn[v]) {
            tarjan(v, i);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                is_bridge[i] = is_bridge[i ^ 1] = true;
            }
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}
int BCC_count;
int BCC_id[N];
vector<int> BCC[N];

void dfs_BCC(int u) {
    BCC_id[u] = BCC_count;
    BCC[BCC_count].push_back(u);

    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (is_bridge[i] || BCC_id[v]) {
            continue;
        }
        dfs_BCC(v);
    }
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i, -1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!BCC_id[i]) {
            ++BCC_count;
            dfs_BCC(i);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    solve();
    cout << BCC_count << endl;
    for (int i = 1; i <= BCC_count; ++i) {
        cout << BCC[i].size() << " ";
        for (int j = 0; j < BCC[i].size(); ++j) {
            cout << BCC[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
