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
int a[N];
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

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[1] << '\n';
        return;
    }
    sort(a + 1, a + n + 1, greater<int>());
    int last_value  = a[1];
    int chongfu_idx = n + 1;
    for (int i = 2; i <= n; ++i) {
        if (last_value == a[i]) {
            chongfu_idx = i - 1;
            break;
        }
        last_value = a[i];
    }
    if (chongfu_idx == 1) {
        cout << 1 << '\n';
        return;
    }
    int ans = 1;
    int m   = 1;
    for (int i = 1; i < chongfu_idx; ++i) {
        ans = (ans + qpow(a[i] - 1, i - 1)) % MOD;
    }
    cout << ans << '\n';
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
