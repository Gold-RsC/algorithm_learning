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

int n, m, p;
struct DSU {
    vector<size_t> parent, size;
    DSU(size_t n)
        : parent(n),
          size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    size_t find_root(size_t x) {
        return x == parent[x]
                   ? x
                   : parent[x] = find_root(parent[x]);
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
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> p;

    DSU dsu(n + 1);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        dsu.unite(x, y);
    }
    while (p--) {
        int x, y;
        cin >> x >> y;
        cout << (dsu.find_root(x) == dsu.find_root(y)
                     ? "Yes\n"
                     : "No\n");
    }

    return 0;
}
