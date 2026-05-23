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
#define int long long
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
    int u, v, w, id;
};
bool operator<(const Edge& a, const Edge& b) {
    return a.w < b.w;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> li;
    vector<Edge> edge;
    for (int i = 0; i < m; ++i) {
        int u, v, w, id;
        cin >> u >> v >> w >> id;
        if (id == k) {
            li.push_back({u, v, w, id});
        }
        edge.push_back({u, v, w, id});
    }

    sort(edge.begin(), edge.end());
    int ans = 2e18;
    for (auto e : li) {
        DSU dsu(n + 1);

        dsu.unite(e.u, e.v);

        int len = e.w;

        for (auto [u, v, w, id] : edge) {
            u = dsu.find_root(u);
            v = dsu.find_root(v);
            if (u == v) {
                continue;
            }
            dsu.unite(u, v);

            len += w;
        }

        ans = min(ans, len);
    }
    cout << ans;


    return 0;
}
