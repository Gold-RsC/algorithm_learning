#include <iostream>
#include <iomanip>
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
const int N = 1e5 + 5;
struct Edge {
    int next;
    int to;
    int weight;
};
vector<Edge> edge;
int n;
vector<int> head(N, -1);

void init_edge() {
    edge.clear();
    fill(head.begin(), head.end(), -1);
}
void add_edge(int u, int v, int w) {
    edge.push_back({head[u], v, w});
    head[u] = edge.size() - 1;
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
 * @brief  树的中心
 * @property 1.在直径上
 * @property 2.中心不唯一，但最多有2个，且两个中心相邻
 * @property 3.所有点到最远点的路径一定交汇于树的中心
 * @property 4.当中心为根节点时，到达直径两端的两条链一定分别是最长链和次长链
 * @property 5.树的中心到其他节点距离不超过直径的一半
 * @details 求法：寻找一个点x，使其作为根节点时的最长链长度最短
 * @details time O(n)
 */
int d1[N];  // 以1为节点时x子树的最长链
int d2[N];  // 以1为节点时x子树的次长链
int up[N];  // x子树外的最长链，必然经过x的父节点
// 如果找到点x使得max(d1[x],up[x])最小，则x即为树的中心
void dfs_down(int u, int father) {
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        int w = edge[i].weight;
        if (v == father) {
            continue;
        }
        dfs_down(v, u);

        if (d1[v] + w > d1[u]) {
            d2[u] = d1[u];
            d1[u] = d1[v] + w;
        }
        else if (d1[v] + w > d2[u]) {
            d2[u] = d1[v] + w;
        }
    }
}
void dfs_up(int u, int father) {
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        int w = edge[i].weight;
        if (v == father) {
            continue;
        }
        up[v] = up[u] + w;
        if (d1[v] + w != d1[u]) {
            up[v] = max(up[v], d1[u] + w);
        }
        else {
            up[v] = max(up[v], d2[u] + w);
        }
        dfs_up(v, u);
    }
}
int get_center() {
    dfs_down(1, 0);
    dfs_up(1, 0);
    int minlen = INT_MAX;
    int ans    = 0;
    int ans2   = 0;
    for (int i = 1; i <= n; ++i) {
        // 其中一个中心
        if (max(d1[i], up[i]) < minlen) {
            minlen = max(d1[i], up[i]);
            ans    = i;
            ans2   = 0;
        }
        // 另一个中心
        else if (max(d1[i], up[i]) == minlen) {
            ans2 = i;
        }
    }
    return ans;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
