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
int max_flow(int s, int t) {
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
