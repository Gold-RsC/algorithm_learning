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
typedef long long ll;
struct dsu {
    ll n;
    vector<ll> fa;
    dsu(ll np) {
        n = np;
        fa.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }
    ll fi(ll x) {
        if (x == fa[x])
            return x;
        return fa[x] = fi(fa[x]);
    }
    void merge(ll x, ll y) {
        fa[fi(y)] = fi(x);
    }
    bool insa(ll x, ll y) {
        x = fi(x), y = fi(y);
        return x == y;
    }
};


void solve() {
    int n, q;
    cin >> n >> q;
    array<array<dsu, 12>, 12> d(array<dsu, 12>(n));

    while (q--) {
        char op;
        cin >> op;
        if (op == '+') {
            int u, v, w;
            cin >> u >> v >> w;


            for (int i = 11; i >= 0; --i) {
                if (w & (1ull << i)) {
                }
            }
        }
        else {
            int u, v;
            cin >> u >> v;
        }
    }
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
