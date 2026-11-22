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

struct Edge {
    int next;
    int to;
    int weight;
};
vector<Edge> edge;
vector<int> head;
vector<int> in_deg;
vector<int> out_deg;
void init_edge(int n) {
    edge.clear();
    head.assign(n + 1, -1);
    in_deg.assign(n + 1, 0);
    out_deg.assign(n + 1, 0);
}
void add_edge(int u, int v, int w) {
    edge.push_back({head[u], v, w});
    head[u] = edge.size() - 1;
    ++out_deg[u];
    ++in_deg[v];
}

/**
 * @brief 欧拉图
 * @def 连通图G且存在一条走完所有边的回路
 * @property 1. 等价条件: 顶点的度都是偶数(对于有向图，入度等于出度)
 * @property 2. 等价条件: 可以分解为若干条不共边回路
 */
int n;
// 有向图的欧拉路径需要先找到第一个和最后一个节点，无向图或欧拉回路都无需查找
int find_first() {
    int ret       = -1;
    bool find_end = false;
    for (int i = 1; i <= n; ++i) {
        if (out_deg[i] - in_deg[i] == 1) {
            if (ret == -1) {
                ret = i;
            }
            else {
                return -1;
            }
        }
        else if (out_deg[i] - in_deg[i] == -1) {
            if (find_end) {
                return -1;
            }
            else {
                find_end = true;
            }
        }
        else if (out_deg[i] - in_deg[i] != 0) {
            return -1;
        }
    }
    if (find_end) {
        return ret;
    }
    return -1;
}
stack<int> ans;  // 倒序输出即为答案
void Hierholzer() {
    int f = find_first();
    stack<int> s;
    s.push(f);
    while (!s.empty()) {
        int u = s.top();
        if (~head[u]) {
            int e   = head[u];
            head[u] = edge[e].next;
            s.push(edge[e].to);
        }
        else {
            ans.push(u);
            s.pop();
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
