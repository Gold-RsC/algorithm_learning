const int N = 1e5 + 5;
struct Edge {
    int v, w;
};
vector<int> edge[N];
void init_edge() {
    for (int i = 0; i < N; ++i) {
        edge[i].clear();
    }
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
