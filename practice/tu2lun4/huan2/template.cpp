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

const int N   = 1e5 + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;


/**
 * @brief ×îÐ¡»·
 */

/**
 * @brief Floyd
 * @details O(n^3)
 */
vector<vector<int>> g;
void init_edge(int n) {
    g.assign(n + 1, vector<int>(n + 1, 0));
}
void add_edge(int u, int v, int w) {
    g[u][v] = g[v][u] = w;
}

int n;

int dis[N][N];
int pos[N][N];
int ans = INF;
vector<int> path;
void add_path(int x) {
    path.push_back(x);
}
void get_path(int x, int y) {
    if (pos[x][y] == 0) {
        return;
    }
    int k = pos[x][y];
    get_path(x, k);
    add_path(k);
    get_path(k, y);
}
void floyd() {
    memset(pos, 0, sizeof(pos));
    memset(dis, 0x3f, sizeof(dis));
    for (int k = 1; k <= n; ++k) {
        for (int x = 1; x < k; ++x) {
            for (int y = 1; y < x; ++y) {
                if (ans > dis[x][y] + g[x][k] + g[k][y]) {
                    ans = dis[x][y] + g[x][k] + g[k][y];
                    add_path(x);
                    add_path(k);
                    add_path(y);
                    get_path(y, x);
                }
            }
        }
        for (int x = 1; x <= n; ++x) {
            for (int y = 1; y <= n; ++y) {
                if (dis[x][y] > dis[x][k] + dis[k][y]) {
                    dis[x][y] = dis[x][k] + dis[k][y];
                    pos[x][y] = k;
                }
            }
        }
    }
}


/**
 * @brief Dijkstra
 * @details O(m(n+m)logn)
 */
struct Edge {
    int next;
    int to;
    int weight;
};
vector<Edge> edge;
vector<int> head;
void init_edge(int n) {
    edge.clear();
    head.assign(n + 1, -1);
}
void add_edge(int u, int v, int w) {
    edge.push_back({head[u], v, w});
    head[u] = edge.size() - 1;
}

int dis[N];

int dijkstra(int s, int t, int ban_id) {
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dis[u]) {
            continue;
        }
        if (u == t) {
            return d;
        }
        for (int i = head[u]; ~i; i = edge[i].next) {
            if (i == ban_id) {
                continue;
            }

            int v = edge[i].to;
            int w = edge[i].weight;

            if (dis[v] > d + w) {
                dis[v] = d + w;
                pq.push({dis[v], v});
            }
        }
    }
    return dis[v];
}
int ans;
bool visited[N];
void dfs(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        int w = edge[i].weight;
        int d = dijkstra(u, v, i);
        if (d < INF) {
            ans = min(ans, d + w);
        }
        dfs(v);
    }
}
void solve() {
    dfs(1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
