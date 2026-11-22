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

const int INF = 2e5 + 5;
int B(int c, int t) {
    return (c + 2 * t - 1) % 7 + 1;
}
int D(int x, int y) {
    return min(abs(x - y), 7 - abs(x - y));
}


void solve() {
    string s;
    cin >> s;
    int n = s.size();
    array<int, 3> dp{0, 0, 0};
    for (int i = 1; i < n; ++i) {
        array<int, 3> ndp{INF, INF, INF};
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                ndp[j] = min(ndp[j], dp[k] + D(B(s[i] - '0', j), B(s[i - 1] - '0', k)));
            }
        }
        swap(dp, ndp);
    }
    int ans = INF;
    for (int i = 0; i < 3; ++i) {
        ans = min(dp[i], ans);
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
