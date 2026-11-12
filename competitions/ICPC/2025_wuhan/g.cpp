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
const int N   = 1e5 + 5;
const int MOD = 998244353;
int qpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
int inv(int a) {
    return qpow(a, MOD - 2);
}
int jc[N];
int inv_jc[N];
void pre_jc(int n) {
    jc[0] = 1;
    for (int i = 1; i <= n; ++i) {
        jc[i] = jc[i - 1] * i % MOD;
    }
    inv_jc[n] = inv(jc[n]);
    for (int i = n - 1; i >= 0; --i) {
        inv_jc[i] = inv_jc[i + 1] * (i + 1) % MOD;
    }
}
int C(int n, int m) {
    return jc[n] * inv_jc[m] % MOD * inv_jc[n - m] % MOD;
}

struct Point {
    int x, y;
    int qk;  // 情况数
    bool operator<(const Point& _) const {
        if (x != _.x) {
            return x < _.x;
        }
        return y < _.y;
    }
    bool operator==(const Point& _) const {
        return x == _.x & y == _.y;
    }
};
void solve() {
    int n, m;
    int color_cnt = 0;
    int ans       = 0;
    cin >> n >> m;
    vector<vector<Point>> zhangai(n * m + 1, vector<Point>());
    vector<vector<int>> g(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int color;
            cin >> color;
            if (!zhangai[color].empty()) {
                ++color_cnt;
            }
            g[i][j] = color;
            zhangai[color].push_back({i, j, 0});
        }
    }

    for (int i = 1; i <= n * m; ++i) {
        if (zhangai[i].empty()) {
            continue;
        }
        if (zhangai[i].front() == Point{1, 1, 0} || zhangai[i].back() == Point{n, m, 0}) {
            ans = (ans + C(n + m - 2, n - 1)) % MOD;
            continue;
        }
        // O(nmk)方案:
        if (zhangai[i].size() * zhangai[i].size() >= n * m) {
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
            dp[1][1] = 1;
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= m; ++k) {
                    if (j == 1 && k == 1) {
                        continue;
                    }
                    if (g[j][k] == i) {
                        dp[j][k] = 0;
                    }
                    else {
                        dp[j][k] = (dp[j - 1][k] + dp[j][k - 1]) % MOD;
                    }
                }
            }
            ans = (ans + C(n + m - 2, n - 1) - dp[n][m]) % MOD;
            while (ans < 0) {
                ans = (ans + MOD) % MOD;
            }
            continue;
        }
        // O(k^2)方案:
        sort(zhangai[i].begin(), zhangai[i].end());
        zhangai[i].push_back({n, m, 0});
        for (int j = 0; j < zhangai[i].size(); ++j) {
            zhangai[i][j].qk = (zhangai[i][j].qk + C(zhangai[i][j].x + zhangai[i][j].y - 2, zhangai[i][j].x - 1)) % MOD;
            for (int k = 0; k < j; ++k) {
                if (zhangai[i][j].x < zhangai[i][k].x || zhangai[i][j].y < zhangai[i][k].y) {
                    continue;
                }
                zhangai[i][j].qk = (zhangai[i][j].qk - zhangai[i][k].qk * C(zhangai[i][j].x - zhangai[i][k].x +
                                                                                zhangai[i][j].y - zhangai[i][k].y,
                                                                            zhangai[i][j].x - zhangai[i][k].x)) %
                                   MOD;
                while (zhangai[i][j].qk < 0) {
                    zhangai[i][j].qk = (zhangai[i][j].qk + MOD) % MOD;
                }
            }
        }
        // cerr << "cerr<<" << zhangai[i].back().qk << " " << zhangai[i].back().x << " " << zhangai[i].back().y <<
        // endl;
        ans = (ans + C(n + m - 2, n - 1) - zhangai[i].back().qk) % MOD;
        while (ans < 0) {
            ans = (ans + MOD) % MOD;
        }
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    pre_jc(N - 1);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
