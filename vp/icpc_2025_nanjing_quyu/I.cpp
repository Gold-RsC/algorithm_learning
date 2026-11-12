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
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), b(n + 1), c(n + 1), d(n + 1, 0), e(n + 1, 0), cza(n + 1, 0), czb(n + 1, 0), czc(n + 1, 0),
        czd(n + 1, 0), cze(n + 1, 0);
    vector<double> p(n + 1), lp(n + 1), blp(n + 1), dp(n + 1, 1e18);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i] >> p[i];
        cza[i] = cza[i - 1] + a[i];
        czb[i] = czb[i - 1] + b[i];
        czc[i] = czc[i - 1] + c[i];
        czd[i] = czd[i - 1] + d[i];
        cze[i] = cze[i - 1] + e[i];
        lp[i]  = lp[i - 1] * p[i];
        blp[i] = blp[i - 1] * (1 - p[i]);
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < n; j++) {
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
