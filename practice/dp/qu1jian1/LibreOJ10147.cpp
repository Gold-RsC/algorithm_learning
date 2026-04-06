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
#include <climits>
using namespace std;
#define int uint64_t
const int N = 410;
int n;
int presum[N];
int a[N];

int f[N][N];
int g[N][N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        presum[i] = presum[i - 1] + a[i];
    }
    for (int i = n + 1; i <= 2 * n; ++i) {
        a[i]      = a[i - n];
        presum[i] = presum[i - 1] + a[i];
    }


    // f(i,j)=max_{k=i}^{j}(f(i,k)+f(k+1,j)+sum(i,j))
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= 2 * n - len; ++i) {
            int j   = i + len - 1;
            f[i][j] = ULLONG_MAX;
            for (int k = i; k < j; ++k) {
                f[i][j] =
                    min(f[i][j],
                        f[i][k] + f[k + 1][j] + presum[j] -
                            presum[i - 1]);
                g[i][j] =
                    max(g[i][j],
                        g[i][k] + g[k + 1][j] + presum[j] -
                            presum[i - 1]);
            }
        }
    }
    int ans_min = ULLONG_MAX, ans_max = 0;

    for (int i = 1; i <= n; ++i) {
        int j   = i + n - 1;
        ans_min = min(ans_min, f[i][j]);
        ans_max = max(ans_max, g[i][j]);
    }

    cout << ans_min << endl << ans_max;

    return 0;
}
