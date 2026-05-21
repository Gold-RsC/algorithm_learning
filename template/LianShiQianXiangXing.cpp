#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
using namespace std;


/**
 * @name 链式前向星
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
// 有环图
vector<bool> visited;
void dfs(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    for (int i = head[u]; ~i; i = edge[i].next) {
        dfs(edge[i].to);
    }
}
// 无环图
void tree_dfs(int u, int fa) {
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        int w = edge[i].weight;
        if (v == fa) {
            continue;
        }
        dfs(edge[i].to);
    }
}


/**
 * @brief 寻找根节点
 */
// 如果节点的情况未知
vector<int> head_list;  // 头节点的集合
vector<int> find_root() {
    vector<int> in_degree(head.size(), 0);

    for (auto e : edge) {
        ++in_degree[e.to];
    }

    vector<int> root_list;
    for (int x : head_list) {
        if (in_degree[x] == 0) {
            root_list.push_back(x);
        }
    }
    return root_list;
}
// 如果节点的情况已知
vector<bool> isnt_root;
void do_root() {
    for (int u = 1; u <= n; ++u) {
        if (!isnt_root[u]) {
            dfs(u);
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
