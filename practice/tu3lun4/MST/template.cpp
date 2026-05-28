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

/**
 * @brief Kruskal算法
 * @details time O(m log m)
 */
struct DSU {
    vector<size_t> parent, size;
    DSU(size_t n)
        : parent(n),
          size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    size_t find_root(size_t x) {
        return parent[x] == x ? x : parent[x] = find_root(parent[x]);
    }
    void unite(size_t x, size_t y) {
        x = find_root(x), y = find_root(y);
        if (x == y) {
            return;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
    }
};

struct Edge {
    int u, v, w;
};
bool operator<(const Edge& a, const Edge& b) {
    return a.w < b.w;
}
void kruskal(vector<Edge>& lists) {
    int n = lists.size();
    sort(lists.begin(), lists.end());

    DSU dsu(n);
    for (auto [u, v, w] : lists) {
        int x = dsu.find_root(u);
        int y = dsu.find_root(v);
        if (x == y) {
            continue;
        }
        dsu.unite(x, y);

        // add_edge(u, v, w);
    }
}

/**
 * @brief Prim算法
 * @details O(m log n)
 */
const int N = 1e5 + 5;
int dis[N];  // 到当前生成树的最小距离
// pii=<dis,u>
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
vector<bool> visited;
int prim(int root) {
    visited.resize(n, false);
    memset(dis, 0x3f, sizeof(dis));
    dis[root] = 0;
    q.push({0, root});
    int cnt = 0;
    while (!q.empty()) {

        auto [d, u] = q.top();
        q.pop();

        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        ++cnt;

        // do_something(father,u,d);

        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            int w = edge[i].weight;

            if (w < dis[v]) {
                dis[v] = w;
                q.push({w, v});
            }
        }

        if (cnt >= n) {
            break;
        }
    }
    if (cnt < n) {
        // 不连通
        return -1;
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
