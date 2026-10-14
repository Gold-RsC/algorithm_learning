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

const int N   = 1e6 + 5;
const int MOD = 998244353;

int f[N];
int invf[N];

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

void init() {
    f[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i % MOD;
    }
    invf[N - 1] = qpow(f[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i) {
        invf[i] = invf[i + 1] * (i + 1) % MOD;
    }
}
int C(int n, int m) {
    return f[n] * invf[m] % MOD * invf[n - m] % MOD;
}
void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int x   = 0;
    int y   = 0;
    int ans = 1;
    for (char c : s) {
        if (c == '(') {
            ++x;
        }
        else {
            ++y;

            int x_ = n - x - 1;
            int y_ = n - y + 1;
            if (x_ >= 0) {
                ans = (ans + (C(x_ + y_, x_) - C(x_ + y_, x_ - 1) + MOD) % MOD) % MOD;
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    init();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
