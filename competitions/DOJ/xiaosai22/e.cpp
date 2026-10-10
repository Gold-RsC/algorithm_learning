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
const int N = 2e6 + 6;

int dp[N][2];
int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];

        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        if (i - a[i] <= dp[i][0] && i - a[i] >= 0) {
            dp[i][1] = dp[i][0] + 1;
        }
        else {
            dp[i][1] = -1;
        }
    }
    cout << max(dp[n][0], dp[n][1]) << "\n";
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
