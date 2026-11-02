struct Edge {
    int v, w;
};
int n;
vector<vector<int>> edge;
void init_edge(int n) {
    edge.assign(n + 1, vector<Edge>());
}
void add_edge(int u, int v, int w) {
    edge[u].push_back({v, w});
};
bool find_edge(int u, int v) {
    for (auto [_v, w] : edge[u]) {
        if (v == _v) {
            return true;
        }
    }
    return false;
}
vector<bool> visited(N);
void dfs(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    for (auto v : edge[u]) {
        dfs(v);
    }
}
