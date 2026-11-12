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
const int N = 1e3 + 5;
int a[N];
int clamp(int x, int l, int r) {
    return min(max(x, l), r);
}
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> L(n + 1, 0);
    vector<int> R(n + 1, 1e9 + 5);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    bool flag = true;
    int ans   = 0;
    while (q--) {
        int p, l, r;
        cin >> p >> l >> r;
        L[p] = max(L[p], l);
        R[p] = min(R[p], r);
        if (L[p] > R[p]) {
            flag = false;
        }
    }
    if (!flag) {
        cout << -1 << '\n';
    }
    else {
        for (int i = 1; i <= n; ++i) {
            int c = clamp(a[i], L[i], R[i]);
            if (c != a[i]) {
                ans += abs(c - a[i]);
            }
        }
        cout << ans << '\n';
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
