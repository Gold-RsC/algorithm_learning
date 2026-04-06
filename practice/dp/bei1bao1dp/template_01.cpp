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
using namespace std;
#define int uint64_t


const int N = 3402 + 5;
const int W = 12880 + 5;
struct item {
    int w, v;
};
item a[N];
// int dp01[N][W];
int dp01[W];
void beibao01() {
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].w >> a[i].v;
    }

    // 法一：二维数组
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 0; j < a[i].w; ++j) {
    //         dp01[i][j] = dp01[i - 1][j];
    //     }
    //     for (int j = a[i].w; j <= w; ++j) {
    //         dp01[i][j] =
    //             max(dp01[i - 1][j],
    //                 dp01[i - 1][j - a[i].w] + a[i].v);
    //     }
    // }
    // cout << dp01[n][w];

    // 法二：一维数组（注意遍历方向）
    for (int i = 1; i <= n; ++i) {
        for (int j = w; j >= a[i].w; --j) {
            dp01[j] =
                max(dp01[j], dp01[j - a[i].w] + a[i].v);
        }
    }
    cout << dp01[w];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    beibao01();
    return 0;
}
