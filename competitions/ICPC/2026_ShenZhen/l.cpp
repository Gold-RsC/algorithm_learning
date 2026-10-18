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

struct In {
    double p;
    int v, w;
    bool operator<(const In& _) const {
        if (v != _.v) {
            return v < _.v;
        }
        if (p != _.p) {
            return p < _.p;
        }
        return w < _.w;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;

    vector<In> a(n + 1, {0, 0, 0});

    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0.0));

    for (int i = 1; i <= n; ++i) {
        cin >> a[i].p >> a[i].v >> a[i].w;
        a[i].p /= 100;
    }

    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; ++i) {
        // cerr << "?a\n";
        for (int j = m; j >= a[i].w; --j) {
            dp[i][j] = max(dp[i - 1][j], (1 - a[i].p) * dp[i - 1][j - a[i].w] + a[i].p * a[i].v);
        }
        // cerr << "?b\n";
        for (int j = min(m, a[i].w - 1); j >= 0; --j) {
            // cerr << "@ " << i << " " << j << endl;
            dp[i][j] = dp[i - 1][j];
        }
        // cerr << "?c\n";
    }
    // cerr << "!\n";
    cout << fixed << setprecision(10) << dp[n][m] << '\n';
    // cerr << "#\n";
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
