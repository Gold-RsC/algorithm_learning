vector<vector<int>> graph;
int n;
void init_edge(int n) {
    graph.assign(n + 1, vector<int>(n + 1, 0));
}
void add_edge(int u, int v, int w) {
    graph[u][v] = w;
};
bool find_edge(int u, int v) {
    return graph[u][v] != 0;
}
vector<bool> visited(N);
void dfs(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (graph[u][v]) {
            dfs(v);
        }
    }
}
