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

const int N = 2e5 + 5;
int n;
int a[N];
int pre[N];
int ans;

int rk[N];
int t[N];
int lowbit(int x) {
    return x & (-x);
}
void add(int i) {
    for (; i <= n; i += lowbit(i)) {
        t[i]++;
    }
}
int presum(int i) {
    int s = 0;
    for (; i > 0; i -= lowbit(i)) {
        s += t[i];
    }
    return s;
}
void solve() {
    cin >> n;

    int minpre = 1e10;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        minpre = min(minpre, pre[i]);
    }

    if (minpre < 0) {
        cout << -1 << '\n';
        return;
    }


    for (int i = 0; i <= n + 1; i++) {
        t[i] = 0;
    }

    vector<int> b(n + 2, 0);
    for (int i = 1; i <= n + 1; ++i) {
        b[i] = pre[i - 1];
    }
    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin() + 1, b.end()), b.end());
    for (int i = 1; i <= n + 1; ++i) {
        rk[i] = lower_bound(b.begin() + 1, b.end(), pre[i - 1]) - b.begin();
    }
    int ans = 0;
    for (int i = n + 1; i >= 1; --i) {
        ans += presum(rk[i] - 1);
        add(rk[i]);
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
