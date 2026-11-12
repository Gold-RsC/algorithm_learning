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
const int MOD = 1e9 + 7;
const int N   = 2010;
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
    return jc[n] * inv_jc[m] % MOD * inv_jc[n - m] % MOD;
}


struct Point {
    int x, y;
    bool operator<(const Point& _) const {
        if (x != _.x) {
            return x < _.x;
        }
        return y < _.y;
    }
} a[N];

int f[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    pre_jc(2e5 + 5);

    int h, w, n;
    cin >> h >> w >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    a[n + 1].x = h;
    a[n + 1].y = w;
    sort(a + 1, a + 1 + n);


    for (int i = 1; i <= n + 1; ++i) {
        f[i] = (f[i] + C(a[i].x + a[i].y - 2, a[i].x - 1)) % MOD;
        for (int j = 1; j < i; ++j) {
            if (a[i].x >= a[j].x && a[i].y >= a[j].y) {
                f[i] = (f[i] - f[j] * C(a[i].x - a[j].x + a[i].y - a[j].y, a[i].x - a[j].x)) % MOD;
                while (f[i] < 0) {
                    f[i] = (f[i] + MOD) % MOD;
                }
            }
        }
    }
    cout << f[n + 1];

    return 0;
}
