#include <iostream>
using namespace std;
#define int uint64_t
int N, M;
int v[3500];
int d[3500];
int dp[1360800];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> v[i] >> d[i];
    }
    // dp[i][w]=max(dp[i-1][w],dp[i-1][w-v[i-1]]+d[i-1]);
    for (int i = 1; i <= N; ++i) {
        for (int w = M; w >= v[i]; --w) {
            dp[w] = max(dp[w], dp[w - v[i]] + d[i]);
        }
    }
    cout << dp[M];
    return 0;
}
