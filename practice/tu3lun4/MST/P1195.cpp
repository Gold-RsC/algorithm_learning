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
const int N = 1e3 + 5;

int n;
int m;
int k;
struct Edge {
    int u, v, w;
};
bool operator<(const Edge& a, const Edge& b) {
    return a.w < b.w;
}
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
vector<Edge> a;
void kruskal() {
    sort(a.begin(), a.end());

    DSU dsu(n);
    int ans = 0;
    int tot = 0;
    for (auto [u, v, w] : a) {
        int x = dsu.find_root(u);
        int y = dsu.find_root(v);
        if (x == y) {
            continue;
        }
        dsu.unite(x, y);

        ans += w;
        tot++;

        if (tot == n - k) {
            cout << ans;
            return;
        }
    }
    cout << "No Answer";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    if (n == k) {
        cout << "0";
        return 0;
    }
    a.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    kruskal();
    return 0;
}
