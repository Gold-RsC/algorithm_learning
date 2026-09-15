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
using namespace std;
#define int long long

const int N   = 1e3 + 5;
const int INF = 0x3f3f3f3f;
// 总方法：Ford–Fulkerson 增广
// 正反图


/**
 * @name dfs版本算法
 * @details 时间复杂度 O(E F),E是边数，F是流值
 */
int edge[N][N];
bool visited[N];
int n;

int dfs(int u, int t, int flow) {
    if (u == t) {
        return flow;
    }
    visited[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (visited[v]) {
            continue;
        }

        if (edge[u][v] > 0) {
            int d = dfs(v, t, min(flow, edge[u][v]));
            if (d > 0) {
                edge[u][v] -= t;
                edge[v][u] += t;
                return t;
            }
        }
    }
    return 0;
}
int max_flow1(int s, int t) {
    int ans = 0;
    while (true) {
        memset(visited, 0, sizeof(visited));
        int a = dfs(s, t, INF);
        if (a == 0) {
            break;
        }
        ans += a;
    }
    return ans;
}

/**
 * @name Edmonds-Karp算法
 * @details 时间复杂度 O(V * E^2)
 */
/**
 * @name Dinic算法
 * @details 时间复杂度 O(V^2 * E)
 */
struct Edge {
    int next;
    int to;
    int weight;
};
vector<Edge> edge;

vector<int> head(N, -1);


vector<int> level(N, -1);
vector<int> cur(N, -1);

void init_edge() {
    edge.clear();
    fill(head.begin(), head.end(), -1);
}
void add_edge(int u, int v, int w) {
    edge.push_back({head[u], v, w});
    head[u] = edge.size() - 1;

    // 反图
    edge.push_back({head[v], u, 0});
    head[v] = edge.size() - 1;
}


bool bfs(int s, int t) {
    fill(level.begin(), level.begin() + n, -1);

    queue<int> q;
    q.push(s);
    level[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            int w = edge[i].weight;

            if (level[v] == -1 && w > 0) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[t] != -1;
}
int dfs(int u, int t, int flow) {
    if (u == t) {
        return flow;
    }

    visited[u] = true;
    for (int& i = cur[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        int w = edge[i].weight;
        if (level[v] == level[u] + 1 && w > 0) {
            int d = dfs(v, t, min(flow, w));
            if (d > 0) {
                edge[i].w -= d;
                edge[i ^ 1].w += d;  // 反向边
                return d;
            }
        }
    }
    return 0;
}
int max_flow3(int s, int t) {
    int ans = 0;
    while (bfs(s, t)) {
        copy(head.begin(), head.end(), cur.begin());
        int f = 0;
        while ((f = dfs(s, t, INF)) > 0) {
            ans += f;
        }
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
