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
#include <limits>
#include <iterator>
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long
const int N = 1e5 + 5;
struct Edge {
    int next;
    int to;
    int weight;
};
vector<Edge> edge;
vector<int> head;
void init_edge(int n) {
    edge.clear();
    head.assign(n + 1, -1);
}
void add_edge(int u, int v, int w) {
    edge.push_back({head[u], v, w});
    head[u] = edge.size() - 1;
}
/**
 * @brief 重链剖分
 * @def 重子节点: 表示子结点中子树最大的子节点(若相同则任选其一)
 *      轻子结点: 其余子结点
 *      重/轻边: 当前结点与对应子结点的连边
 *      重链: 首尾相连的重边或落单的结点
 * @property
 *   1. 重链上深度最小结点一定不是重子节点(要么是根，要么是轻子结点)
 *   2. 每向下经过一条轻边时，所在子树大小至少除以2
 *   3. 可以将树上任何一条路径划分成不超过O(logn)条连续的链，且每条链上的点深度互不相同
 *   4. 保证划分出的每条链的结点dfs序连续，因此可以用线段树、树状数组等结构进行维护树上路径的信息
 * @note
 *   1. 可以用来O(logn)地求LCA
 */
int depth[N];
int father[N];
int heavy_son[N];
int sz[N];
int dfn[N];
int rnk[N];
int timestamp;
int top[N];  // 重链上深度最小的结点
void dfs(int u, int fa) {
    father[u] = fa;
    depth[u]  = depth[fa] + 1;
    sz[u]     = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa) {
            continue;
        }
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[heavy_son[u]]) {
            heavy_son[u] = v;
        }
    }
}
// 建链
void dfs2(int u, int ftop, int fa) {
    top[u]         = ftop;
    dfn[u]         = ++timestamp;
    rnk[timestamp] = u;
    if (heavy_son[u]) {
        dfs2(heavy_son[u], ftop, u);
    }
    for (int i = head[u]; ~i; edge[i].next) {
        int v = edge[i].to;
        if (v != heavy_son[u] && v != fa) {
            dfs2(v, v, u);
        }
    }
}
// 用重链剖分求两点路径权值之和
int a[N];
int presum[N];  // 预处理链上前缀和
void dfs_presum(int u, int fa) {
    presum[u] += a[u];
    for (int i = head[u]; ~i; edge[i].next) {
        int v = edge[i].to;
        if (v == fa) {
            continue;
        }
        if (v == heavy_son[u]) {
            presum[v] += presum[u];
        }
        dfs_presum(v, u);
    }
}
int path_sum(int u, int v) {
    int ans = 0;
    while (top[u] != top[v]) {
        if (depth[top[u]] < depth[top[v]]) {
            swap(u, v);
        }
        ans += presum[u];
        u = father[top[u]];
    }
    return ans;
}
// 求lca
int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (depth[top[u]] > depth[top[v]]) {
            u = father[top[u]];
        }
        else {
            v = father[top[v]];
        }
    }
    return depth[u] > depth[v] ? v : u;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
