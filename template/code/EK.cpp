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
int max_flow(int s, int t) {
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
