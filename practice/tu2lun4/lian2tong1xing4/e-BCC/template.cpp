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
#define int long long

const int N = 1e5 + 5;

/**
 * @brief tarjan算法
 * @details 边-双连通即为任意去掉一条边仍然互相连通
 */
struct Edge {
    int next;
    int to;
    int weight;
};
vector<Edge> edge;

vector<int> head(N, -1);

void add_edge(int u, int v, int w) {
    edge.push_back({head[u], v, w});
    head[u] = edge.size() - 1;

    // 反图
    edge.push_back({head[v], u, w});
    head[v] = edge.size() - 1;
}

int dfn[N];
int low[N];
int timestamp;

bool is_bridge[N];

int BCC_count;
int BCC_id[N];
int BCC_size[N];

void tarjan(int u, int parent_edge) {
    low[u] = dfn[u] = ++timestamp;
    for (int i = head[u]; ~i; i = edge[i].next) {
        // 不能回去
        if (i == (parent_edge ^ 1)) {
            continue;
        }

        int v = edge[i].to;

        // 判据
        if (!dfn[v]) {
            tarjan(v, i);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[v]) {
                is_bridge[i] = is_bridge[i ^ 1] = true;
            }
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void dfs_BCC(int u) {
    BCC_id[u] = BCC_count;

    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (is_bridge[i] || BCC_id[v]) {
            continue;
        }
        dfs_BCC(v);
    }
}
void solve() {
    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) {
            tarjan(i, -1);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!BCC_id[i]) {
            ++BCC_count;
            dfs_BCC(i);
        }
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
