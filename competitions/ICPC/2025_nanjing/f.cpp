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

void add_edge(vector<DSU>& d, int u, int v, int w) {
    if (d[w].find_root(u) == d[w].find_root(v)) {
        return;
    }
    d[w].unite(u, v);
    for (int i = 0; i < 12; ++i) {
        if ((w >> i) & 1) {
            add_edge(d, u, v, w ^ (1ull << i));
        }
    }
};
void solve() {
    int n, q;
    cin >> n >> q;

    vector<DSU> d(1 << 12, n + 1);

    int total_ans = 0;
    while (q--) {
        char op;
        int u, v, w;
        cin >> op >> u >> v;
        if (op == '+') {
            cin >> w;

            // for (int s = w;; s = (s - 1) & w) {
            //     d[s].unite(u, v);
            //     if (!s) {
            //         break;
            //     }
            // }
            add_edge(d, u, v, w);
        }
        else {
            if (d[0].find_root(u) != d[0].find_root(v)) {
                total_ans += -1;
                continue;
            }
            int ans = 0;
            for (int i = 11; i >= 0; --i) {
                int c = ans | (1ull << i);
                if (d[c].find_root(u) == d[c].find_root(v)) {
                    ans = c;
                }
            }
            total_ans += ans;
        }
    }
    cout << total_ans << '\n';
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
