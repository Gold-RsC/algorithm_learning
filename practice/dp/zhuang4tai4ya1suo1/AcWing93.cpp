#include <iostream>
#include <iomanip>
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
#include <climits>
#include <bitset>
#include <cstring>
using namespace std;

const int N = 21;

int n;

int a[N][N];

// dp[0bxxxx][j] 表示到达j时正好状态为xxxx
// 转移方程为：
// dp[0bxxxx][j] = min(dp[0bxxxx 去掉j][k]+a[k][j])
// 其中，k得在xxxx的记录内
int dp[1 << N][N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    memset(dp, 0x3f, sizeof(dp));

    dp[1][0] = 0;

    int m = 1 << n;


    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1 == 1) {
                int state = i & (~(1 << j));
                for (int k = 0; k < n; ++k) {
                    if ((state >> k) & 1 == 1) {
                        dp[i][j] =
                            min(dp[i][j],
                                dp[state][k] + a[k][j]);
                    }
                }
            }
        }
    }

    cout << dp[m - 1][n - 1];

    return 0;
}
