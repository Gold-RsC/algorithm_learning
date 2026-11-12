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
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1, 0);
    vector<int> le(n + 1, 0);
    vector<int> ri(n + 1, 1e9 + 5);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    bool flag = true;
    while (q--) {
        int p, l, r;
        cin >> p >> l >> r;
        le[p] = max(le[p], l);
        ri[p] = min(ri[p], r);
        if (le[p] > ri[p]) {
            flag = false;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int b = clamp(a[i], le[i], ri[i]);
        ans += abs(a[i] - b);
    }
    if (flag) {
        cout << ans << '\n';
    }
    else {
        cout << "-1\n";
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
