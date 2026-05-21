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

struct Edge {
    int next;
    int to;
    int weight;
};
vector<Edge> edge;

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
 * @brief 树的重心
 * @details time O(n)
 */
int size[N];
int now_min;  // 去掉重心后的最大子树大小
int ans;
void dfs(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;

    size[u] = 1;

    int max_part = 0;  // 表示删掉x后分成的最大子树的大小


    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        int w = edge[i].weight;
        dfs(v);

        size[u] += size[v];

        max_part = max(max_part, size[v]);
    }
    max_part = max(max_part, n - size[u]);
    if (max_part < now_min) {
        now_min = max_part;
        ans     = u;
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
