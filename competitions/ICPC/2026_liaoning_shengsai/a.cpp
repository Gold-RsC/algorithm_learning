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
const int N = 5e5 + 5;

struct DSU {
    vector<int> parent, sz;
    DSU(size_t n)
        : parent(n),
          sz(n, 1) {
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
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        parent[y] = x;
        sz[x] += sz[y];
        return true;
    }
};
int r[N];
int c[N];

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> rr;
    unordered_map<int, int> cc;
    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
        cin >> c[i];
        rr[r[i]] = i;
        cc[c[i]] = i;
    }
    cin >> r[0] >> c[0];
    DSU dsu(n + 2);
    int unt = 0;
    for (int i = 0; i <= n; ++i) {
        if (rr.count(r[i])) {
            unt += dsu.unite(rr[r[i]] + 1, i + 1);
        }
        if (cc.count(c[i])) {
            unt += dsu.unite(cc[c[i]] + 1, i + 1);
        }
    }
    cout << n + n - unt << '\n';
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
