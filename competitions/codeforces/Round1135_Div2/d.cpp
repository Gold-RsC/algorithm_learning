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
const int N   = 2e5 + 5;
const int MOD = 1e9 + 7;


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
vector<int> jc;
vector<int> inv_jc;
void pre_jc(int n) {
    jc.assign(n + 1, 0);
    inv_jc.assign(n + 1, 0);
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
    if (n < 0 || n < m) {
        return 0;
    }
    return jc[n] * inv_jc[m] % MOD * inv_jc[n - m] % MOD;
}

int a[N];
int c[N];
int pre[N];
int zero[N];
unordered_map<int, vector<int>> mp;

void solve() {
    mp.clear();
    int n, m, q;
    cin >> n >> m >> q;

    int n2 = (n + 1) / 2;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        c[i]   = a[i] - a[n + 1 - i];
        pre[i] = pre[i - 1] + c[i];
        mp[pre[i]].push_back(i);
        zero[i] = zero[i - 1];
        if (!pre[i]) {
            ++zero[i];
        }
    }

    while (q--) {
        int i, v;
        cin >> i >> v;
        if (i > n2) {
            i = n + 1 - i;
            v = -v;
        }

        int ans = 0;

        int x = 0;

        if (mp.count(-v)) {
            x += upper_bound(mp[-v].begin(), mp[-v].end(), n - i) - lower_bound(mp[-v].begin(), mp[-v].end(), i);
        }
        x += zero[n - 1] - (zero[n - i] - zero[i - 1]);
        ans = (ans + C(x, m - 1)) % MOD;
        cout << ans << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    pre_jc(N);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
