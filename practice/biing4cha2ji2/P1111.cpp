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
#include <climits>
using namespace std;
struct V {
    int x, y, t;
    bool operator<(const V& a) const {
        return this->t < a.t;
    }
};
struct DSU {
    vector<int> parent, size;
    int max_size;
    DSU(int n)
        : parent(n),
          size(n, 1),
          max_size(0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return x == parent[x] ? x
                              : parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        max_size = max(max_size, size[x]);
    }
};
vector<V> v;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    if (m < n - 1) {
        cout << -1;
        return 0;
    }
    DSU dsu(n + 1);
    while (m--) {
        int x, y, t;
        cin >> x >> y >> t;
        v.push_back({x, y, t});
    }
    sort(v.begin(), v.end());
    for (auto x : v) {
        dsu.unite(x.x, x.y);
        if (dsu.max_size == n) {
            cout << x.t;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
