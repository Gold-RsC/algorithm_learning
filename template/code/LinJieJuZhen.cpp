const int N = 1e5 + 5;
int graph[N][N];
void init_edge() {
    memset(graph, 0, sizeof(graph));
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
        if (graph[v]) {
            dfs(v);
        }
    }
}
