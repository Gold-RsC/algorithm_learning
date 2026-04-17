#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
using namespace std;
#define int int64_t
const int MOD = 1000000007llu;
const int N   = 5e5 + 5;

int n_m;

int a[N];

int ans;

int re[N] = {1, 1};
int cur   = 2;
int jiecheng(int n) {
    for (; cur <= n; ++cur) {
        re[cur] = cur * re[cur - 1] % MOD;
    }
    return re[n];
}

int qpow(int x, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * x % MOD;
        }
        x = x * x % MOD;
        b >>= 1;
    }

    return ret;
}
// niyuan(jiecheng(x.second))
int reni[N] = {1, 1};
int get_ni(int n) {
    if (reni[n]) {
        return reni[n];
    }
    return reni[n] = qpow(jiecheng(n), MOD - 2);
}

int f() {
    int m = jiecheng(n_m);

    // for (auto x : a) {
    //     if (x.second) {
    //         // cerr << "[" << x.second << " "
    //         //      << get_ni(x.second) << "]" << endl;
    //         m = m * get_ni(x.second) % MOD;
    //     }
    // }
    for (int i = 1; i < N; ++i) {
        if (a[i] > 0) {
            m = m * get_ni(a[i]) % MOD;
        }
    }
    return m;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n_m;

    for (int i = 0; i < n_m; ++i) {
        int x;
        cin >> x;
        ++a[x];
    }
    n_m -= 2;

    for (int i = 1; i * i <= n_m; ++i) {
        if (n_m % i == 0) {
            if (a[i] && a[n_m / i]) {
                --a[i];
                --a[n_m / i];
                ans = (ans + (f() * ((i * i != n_m) + 1))) %
                      MOD;
                ++a[i];
                ++a[n_m / i];
            }
        }
    }
    cout << ans;
    return 0;
}
