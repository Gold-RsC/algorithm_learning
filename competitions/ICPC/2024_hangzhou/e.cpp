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
struct cao {
    int l, r;
    int flag = false;
    int rk;
};
void solve() {
    int n, f;
    cin >> n >> f;

    vector<cao> a(n);
    vector<int> as;

    int max_r = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r;
        a[i].rk = i;
        max_r   = max(max_r, a[i].r);
    }

    sort(a.begin(), a.end(), [&](const cao& x, const cao& y) {
        if (x.l != y.l) {
            return x.l < y.l;
        }
        return x.r > y.r;
    });
    int ans = 0;
    if (f < a[0].l) {
        ans += a[0].l - f;
        f = a[0].l;
    }
    for (int i = 0; i < n; ++i) {
        if (f < a[i].r) {
            ans += a[i].r - a[i].l;
            if (f < a[i].l) {
                ans += a[i].l - f;
            }
            f         = a[i].r;
            a[i].flag = true;
            as.push_back(a[i].rk);
        }
    }
    sort(a.begin(), a.end(), [&](const cao& x, const cao& y) {
        if (x.r != y.r) {
            return x.r > y.r;
        }
        return x.l > y.l;
    });
    for (int i = 0; i < n; ++i) {
        if (a[i].flag) {
            continue;
        }
        ans += a[i].r - a[i].l;
        f = a[i].r;
        as.push_back(a[i].rk);
    }
    cout << ans << '\n';
    for (int i = 1; i < as.size(); ++i) {
        cout << as[i - 1] + 1 << ' ';
    }
    cout << as.back() + 1 << '\n';
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
