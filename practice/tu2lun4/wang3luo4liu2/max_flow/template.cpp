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
                edge[u][v] -= d;
                edge[v][u] += d;
                return d;
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
struct Edge {
    int next;
    int to;
    int weight;  // capacity
};
vector<Edge> edge;

vector<int> head(N, -1);

void init_edge() {
    edge.clear();
    fill(head.begin(), head.end(), -1);
}
void add_edge(int u, int v, int w) {
    // 正图
    edge.push_back({head[u], v, w});
    head[u] = edge.size() - 1;
    // 反图
    edge.push_back({head[v], u, 0});
    head[v] = edge.size() - 1;
}
// pre[v] 记录到达 v 的边的下标
int pre[N];
// minflow[v] 是s到v的最小剩余容量
int minflow[N];

bool bfs(int s, int t) {
    fill(pre, pre + N, -1);
    memset(minflow, 0, sizeof(minflow));
    queue<int> q;
    q.push(s);
    minflow[s] = INF;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            int w = edge[i].weight;

            // 未访问或有剩余容量
            if (pre[v] == -1 && w > 0) {
                pre[v]     = i;
                minflow[v] = min(minflow[u], w);
                q.push(v);
            }
        }
    }
    return pre[t] != -1;
}

int max_flow2(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {  // bfs找路
        // 从t开始遍历沿着反图走到s
        for (int v = t; v != s;) {
            int i = pre[v];
            edge[i].weight -= minflow[t];
            edge[i ^ 1].weight += minflow[t];
            v = edge[i ^ 1].to;
        }
        flow += minflow[t];
    }
    return flow;
}

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
void init_edge() {
    edge.clear();
    fill(head.begin(), head.end(), -1);
}
void add_edge(int u, int v, int w) {
    // 正图
    edge.push_back({head[u], v, w});
    head[u] = edge.size() - 1;
    // 反图
    edge.push_back({head[v], u, 0});
    head[v] = edge.size() - 1;
}

vector<int> level(N, -1);  // 分层图
vector<int> cur(N, -1);    // 当前弧优化，cur[u]表示遍历到哪条边
// bfs找路，建立分层图，让dfs只允许走最短路
bool bfs(int s, int t) {
    fill(level.begin(), level.end(), -1);

    queue<int> q;
    q.push(s);
    level[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            int w = edge[i].weight;
            // 如果没有经过v或有剩余容量
            if (level[v] == -1 && w > 0) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[t] != -1;
}
// 按分层图找u到t的增广路
int dfs(int u, int t, int flow) {
    if (u == t) {
        return flow;  // 找到增广路即返回
    }
    for (int& i = cur[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        int w = edge[i].weight;
        // 只能走到下一层且有剩余容量的点
        if (level[v] == level[u] + 1 && w > 0) {
            int d = dfs(v, t, min(flow, w));
            // 如果之后的v到t有最大流量d
            if (d > 0) {
                edge[i].weight -= d;
                edge[i ^ 1].weight += d;  // 反向边
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
