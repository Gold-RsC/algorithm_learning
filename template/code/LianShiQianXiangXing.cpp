/**
 * @name 链式前向星
 * @note 适用于有向图
 */
const int N = 1e5 + 5;
int n;
struct Edge {
    int next;    // 下一个坐标
    int to;      // 指向的节点
    int weight;  // 边权重
};
vector<Edge> edge;
vector<int> head(N, -1);  // 头节点的初始坐标

void init_edge() {
    edge.clear();
    fill(head.begin(), head.end(), -1);
}
void add_edge(int u, int v, int w) {
    edge.push_back({head[u], v, w});
    head[u] = edge.size() - 1;

    isnt_root[v] = true;
}
bool find_edge(int u, int v) {
    for (int i = head[u]; ~i; i = edge[i].next) {
        if (edge[i].to == v) {
            return true;
        }
    }
    return false;
}

/**
 * @brief dfs遍历
 * @details time O(n)
 */
vector<bool> visited(N);
void dfs(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        int w = edge[i].weight;

        dfs(v);
    }
}

/**
 * @note 寻找根节点->寻找入度为0的节点
 */

/**
 * @brief 无向图
 * @note edge[i]的反边为edge[i^1]
 */
void add_edge(int u, int v, int w) {
    edge.push_back({head[u], v, w});
    head[u] = edge.size() - 1;

    edge.push_back({head[v], u, w});
    head[v] = edge.size() - 1;
}
