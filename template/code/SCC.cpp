/**
 * @name Tarjan算法
 * @details O(V+E)
 */
struct Edge {
    int next;
    int to;
    int weight;
};
vector<Edge> edge;
vector<int> head(N, -1);

int dfn[N];     // dfs搜索时，u被搜索到的timestamp。从根节点开始的一个路径上dfn[u]单调递增
int low[N];     // 从u出发，dfs子树中，能追溯到的最早的仍在栈里的节点的dfn。从根节点开始的一个路径上low[u]单调不增
int timestamp;  // 全局时间戳

int SCC_count;    // SCC个数
int SCC_id[N];    // 节点i所在的SCC编号
int SCC_size[N];  // 编号为i的SCC的大小

bool in_stack[N];  // 节点u是否在栈中
stack<int> s;      // 栈

void tarjan(int u) {
    low[u] = dfn[u] = ++timestamp;

    s.push(u);
    in_stack[u] = true;
    // 遍历一次u树
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;

        // 如果v没有被搜索过
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        // 如果v被搜索过并且在栈中，则说明找到了返祖边
        else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    // 找到SCC的根节点
    if (dfn[u] == low[u]) {
        ++SCC_count;
        int v;
        // 弹出我和我的子树(即找到了一组SCC)
        do {
            v = s.top();
            s.pop();
            SCC_id[v] = SCC_count;
            ++SCC_size[SCC_count];
            in_stack[v] = false;
        } while (u != v);
    }
}
void solve() {
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
}


/**
 * @brief Kosaraju算法
 * @details O(V+E)
 */
vector<int> edge[N];  // 正向图
vector<bool> vis;
vector<int> edge2[N];  // 反向图
vector<bool> vis2;

vector<int> post_order;  // 后序遍历节点表

int SCC_count;
int SCC_id[N];
int SCC_size[N];

// 正图上后序遍历，得到拓扑序
void dfs1(int u) {
    vis[u] = true;
    for (auto v : edge[u]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }
    post_order.push_back(u);
}
// 反图上扩散
void dfs2(int u) {
    SCC_id[u] = SCC_count;
    ++SCC_size[SCC_count];
    for (auto v : edge2[u]) {
        if (!SCC_id[v]) {
            dfs2(v);
        }
    }
}

void kosaraju() {
    // 第一次dfs进行后序遍历
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs1(i);
        }
    }
    // 对后序遍历的表进行反向遍历
    for (auto it = post_order.rbegin(); it != post_order.rend(); ++it) {
        int u = *it;
        // 如果还没开始标SCC的序号
        if (!SCC_id[u]) {
            ++SCC_count;
            dfs2(u);
        }
    }
}
