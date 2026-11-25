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
    bool unite(size_t x, size_t y) {
        x = find_root(x), y = find_root(y);
        if (x == y) {
            return false;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    DSU dsu(27);
    for (int i = 0; i <= s.size() / 2; ++i) {
        int u = s[i] - 'a' + 1;
        int v = s[n - i - 1] - 'a' + 1;
        if (u > v) {
            swap(u, v);
        }
        for (; dsu.find_root(u) != dsu.find_root(v); v--) {
            ans += dsu.unite(v, v - 1);
            // cerr << "[] " << u << " " << v << endl;
        }
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
