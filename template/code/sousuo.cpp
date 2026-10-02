
/**
 * @brief bfs
 */
void bfs(int x) {
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if () {
            q.push(v);
        }
    }
}

/**
 * @brief dfs
 */
void dfs(int u) {
    if () {
        return;
    }
    dfs(v);
}

/**
 * @brief iddfs
 */
bool iddfs(int u, int d) {
    if (!d) {
        return false;
    }

    iddfs(v, d - 1);
    return true;
}
void solve() {
    for (int deep = 0;; ++deep) {
        if (iddfs(s, deep)) {
            break;
        }
    }
}

/**
 * @brief A*
 * @note Dijkstra°æA*£¬dis[v]=g[v]+h[v]
 */
struct Edge {
    int v, w;
};
struct Node {  /// Dijkstra½Úµã
    int dis, u;
    bool operator>(const Node& a) const {
        return dis > a.dis;
    }
};
vector<Edge> edge[N];
int g[N];
bool vis[N];
priority_queue<Node, vector<Node>, greater<Node>> pq;

void Astar(int s) {
    memset(g, 0x3f, sizeof(g));

    g[s] = 0;

    pq.push({h[0], s});

    while (!pq.empty()) {
        int u = pq.top().u;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = 1;
        for (auto ed : edge[u]) {
            int v = ed.v, w = ed.w;
            if (g[v] > g[u] + w) {
                g[v] = g[u] + w;
                pq.push({g[v] + h[v], v});
            }
        }
    }
}
