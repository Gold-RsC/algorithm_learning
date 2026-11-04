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
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long
namespace std {
template <>
struct hash<pair<int, int>> {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>{}(p.first) ^ (hash<int>{}(p.second) + 0x9e3779b9);
    }
};
}  // namespace std

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    unordered_set<int> frd;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;

        frd.insert(a);
    }
    int ans = 0;
    unordered_map<int, int> c;
    unordered_map<pair<int, int>, int> d;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        if (frd.count(b)) {
            swap(a, b);
        }
        if (frd.count(a)) {
            if (frd.count(b)) {
                ++ans;
            }
            else {
                ++c[b];
            }
        }
        else {
            if (a == b) {
                ++c[a];
                continue;
            }
            if (a > b) {
                swap(a, b);
            }
            ++d[{a, b}];
        }
    }
    if (k - n == 0) {
        cout << ans << '\n';
        return;
    }
    int m1 = 0, m2 = 0;
    int m1_i = 0, m2_i = 0;
    for (int i = 1; i <= k; ++i) {
        if (!frd.count(i)) {
            if (c[i] > m1) {
                swap(m1, m2);
                swap(m1_i, m2_i);
                m1   = c[i];
                m1_i = i;
            }
            else if (c[i] > m2) {
                m2   = c[i];
                m2_i = i;
            }
        }
    }
    int ans1 = ans + m1 + m2;

    int ans2 = 0;
    for (const auto& [p, z] : d) {
        const auto& [a, b] = p;
        int x              = z;
        if (c.count(a)) {
            x += c[a];
        }
        if (c.count(b)) {
            x += c[b];
        }
        ans2 = max(ans2, x);
    }
    ans2 += ans;
    if (ans1 > ans2) {
        cout << ans1 << '\n';
    }
    else {
        cout << ans2 << '\n';
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
