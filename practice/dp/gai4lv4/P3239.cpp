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

double qpow(double a, int b) {
    double ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ret;
}

void solve() {
    int n, R;
    cin >> n >> R;
    vector<double> p(n + 1, 0);
    vector<int> d(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i] >> d[i];
    }
    vector dp(n + 10, vector<double>(R + 10, 0));


    vector<double> P(n + 10, 1);
    for (int r = 1; r <= R; ++r) {
        for (int i = 1; i <= n; ++i) {
            P[i] *= (1 - p[i]);
        }
        for (int i = n; i >= 1; --i) {

            dp[i][r] = dp[i + 1][r] * P[i] + (dp[i + 1][r - 1] + d[i]) * (1 - P[i]);
        }
    }

    cout << fixed << setprecision(10) << dp[1][R] << '\n';
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
