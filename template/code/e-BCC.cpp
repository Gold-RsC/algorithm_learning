/**
 * @brief tarjan算法
 * @details 无向图，边-双连通即为任意去掉一条边仍然互相连通
 * @details O(E+V)
 */
struct Edge {
    int next;
    int to;
};
vector<Edge> edge;
vector<int> head(N, -1);

void add_edge(int u, int v) {
    edge.push_back({head[u], v});
    head[u] = edge.size() - 1;
    edge.push_back({head[v], u});
    head[v] = edge.size() - 1;
}

int dfn[N];
int low[N];
int timestamp;

bool is_bridge[N];  // 边i是否为桥

int BCC_count;    // e-BCC个数
int BCC_id[N];    // 节点u所在BCC编号
int BCC_size[N];  // 编号为i的BCC大小

void tarjan(int u, int in_edge) {  // 节点u，入节点u的边
    low[u] = dfn[u] = ++timestamp;
    for (int i = head[u]; ~i; i = edge[i].next) {
        // 不能回去
        if (i == (in_edge ^ 1)) {
            continue;
        }

        int v = edge[i].to;

        // v没有被搜索过->树边
        if (!dfn[v]) {
            tarjan(v, i);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                is_bridge[i] = is_bridge[i ^ 1] = true;
            }
        }
        // v被搜索过->回边
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void dfs_BCC(int u) {
    BCC_id[u] = BCC_count;
    ++BCC_size[BCC_count];

    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        // 是桥或者已标号
        if (is_bridge[i] || BCC_id[v]) {
            continue;
        }
        dfs_BCC(v);
    }
}
void solve() {
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i, -1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!BCC_id[i]) {
            ++BCC_count;
            dfs_BCC(i);
        }
    }
}
