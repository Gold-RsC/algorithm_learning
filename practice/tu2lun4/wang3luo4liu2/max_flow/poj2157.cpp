#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>

using namespace std;

/**
 * @brief Bellman-Ford 模板（改：找负环 + 记录路径 + 带容量）
 */
struct Edge {
    int u, v, w;  // 起点、终点、费用
    int cap;      // 剩余容量
    int rev;      // 反向边在 edge 数组中的下标
};

int n, m;                // 大楼数、防空洞数
int V;                   // 总节点数
vector<Edge> edge;       // 所有边（含反向）
vector<int> head[1005];  // 每个点的出边编号（可选，本题直接遍历全边）
vector<int> dis;         // 距离
vector<int> preV, preE;  // 前驱节点、前驱边编号，用于回溯负环

const int INF = 0x3f3f3f3f;

/**
 * @brief 加边（正向 + 反向）
 */
void addEdge(int u, int v, int cap, int cost) {
    Edge a{u, v, cost, cap, (int)edge.size() + 1};
    Edge b{v, u, -cost, 0, (int)edge.size()};
    edge.push_back(a);
    edge.push_back(b);
}

/**
 * @brief 在残量网络中找负环（适配模板）
 * @return true 表示找到负环
 * @details 与单源 BF 不同，这里 dis 全初始化为 0，
 *          因为我们要找任意负环，所有点都可能是环上一点。
 */
bool Bellman_Ford_findNegativeCycle() {
    dis.assign(V, 0);
    preV.assign(V, -1);
    preE.assign(V, -1);

    int last = -1;  // 最后一次被松弛的节点（必在负环上）
    for (int i = 1; i <= V; ++i) {
        last      = -1;
        bool flag = false;
        for (int j = 0; j < (int)edge.size(); ++j) {
            int u = edge[j].u, v = edge[j].v, w = edge[j].w;
            if (edge[j].cap <= 0)
                continue;  // 残量网络中无剩余容量
            if (dis[v] > dis[u] + w) {
                dis[v]  = dis[u] + w;
                preV[v] = u;
                preE[v] = j;  // 记录边编号
                flag    = true;
                last    = v;
            }
        }
        if (!flag)
            break;  // 没有松弛，退出
        // 第 V 轮还在松弛，说明有负环
        if (i == V && last != -1) {
            // 回溯 V 次，保证 v 一定在环上
            int v = last;
            for (int k = 0; k < V; ++k)
                v = preV[v];
            // 从 v 出发沿 pre 走一圈，收集环上的边
            vector<int> cycleEdges;
            int u = v;
            do {
                cycleEdges.push_back(preE[u]);
                u = preV[u];
            } while (u != v);

            // 找环上最小剩余容量
            int delta = INF;
            for (int id : cycleEdges) {
                delta = min(delta, edge[id].cap);
            }
            // 沿环增广 delta
            for (int id : cycleEdges) {
                edge[id].cap -= delta;
                edge[id ^ 1].cap += delta;  // 反向边
            }
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    vector<int> X(n), Y(n), B(n);
    for (int i = 0; i < n; ++i)
        cin >> X[i] >> Y[i] >> B[i];
    vector<int> P(m), Q(m), C(m);
    for (int j = 0; j < m; ++j)
        cin >> P[j] >> Q[j] >> C[j];

    vector<vector<int>> E(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> E[i][j];

    // 计算时间
    vector<vector<int>> tim(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            tim[i][j] = abs(X[i] - P[j]) + abs(Y[i] - Q[j]) + 1;

    // 节点编号：S=0, 楼 1..n, 洞 n+1..n+m, T=n+m+1
    int S = 0, T = n + m + 1;
    V = n + m + 2;

    // ---------- 建残量网络 ----------
    // S -> i, i -> S
    for (int i = 0; i < n; ++i) {
        int sumE = 0;
        for (int j = 0; j < m; ++j)
            sumE += E[i][j];
        addEdge(S, 1 + i, B[i] - sumE, 0);  // 正向：剩余可分配人数
        addEdge(1 + i, S, sumE, 0);         // 反向：已分配人数
    }
    // i -> j, j -> i
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            addEdge(1 + i, n + 1 + j, INF, tim[i][j]);       // 正向：可继续分配
            addEdge(n + 1 + j, 1 + i, E[i][j], -tim[i][j]);  // 反向：可撤销
        }
    }
    // j -> T, T -> j
    for (int j = 0; j < m; ++j) {
        int sumE = 0;
        for (int i = 0; i < n; ++i)
            sumE += E[i][j];
        addEdge(n + 1 + j, T, C[j] - sumE, 0);  // 正向：剩余容量
        addEdge(T, n + 1 + j, sumE, 0);         // 反向：已用容量
    }

    // ---------- 找负环 ----------
    if (!Bellman_Ford_findNegativeCycle()) {
        cout << "OPTIMAL\n";
    }
    else {
        cout << "SUBOPTIMAL\n";
        // 从残量网络反向边提取新的 E_ij
        // 反向边 (洞 j -> 楼 i) 的 cap 就是新的 E_ij
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int u = n + 1 + j, v = 1 + i;
                for (int k = 0; k < (int)edge.size(); ++k) {
                    if (edge[k].u == u && edge[k].v == v) {
                        E[i][j] = edge[k].cap;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << E[i][j] << (j + 1 == m ? '\n' : ' ');
            }
        }
    }
    return 0;
}
