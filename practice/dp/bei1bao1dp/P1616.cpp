#include <iostream>
#include <vector>
using namespace std;
#define int uint64_t
int t, m;
int tm[10005];
int value[10005];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t >> m;
    vector<vector<int>> dp(t + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; ++i) {
        cin >> tm[i] >> value[i];
    }
    // dp[i][weight]=max(dp[i-1][weight],dp[i-1][weight-w[i]]+v[i])
    for (int i = 1; i <= m; ++i) {
        for (int j = tm[i]; j <= t; ++j) {
            dp[j][i] = max(dp[j][i - 1], dp[j - tm[i]][i] + value[i]);
        }
    }
    cout << dp[t][m];
    return 0;
}
