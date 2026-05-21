#include <iostream>
#include <iomanip>
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
using namespace std;
const int N = 1e5 + 5;
const int W = 1e9 + 5;

/**
 * @brief 01背包
 */
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
            dp01[j] = max(dp01[j], dp01[j - a[i].w] + a[i].v);
        }
    }
    cout << dp01[w];
}

/**
 * @brief 多重背包
 */
struct item {
    int w, v;
    int c;
};
item a[N];

int dpdc[W];
void beibaodc() {
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].w >> a[i].v >> a[i].c;
    }

    // 法一：当成01背包，物品复制c份
    // for (int i = 1; i <= n; ++i) {
    //     // 小剪枝：如果足够大，可以直接当成完全背包
    //     // begin
    //     if (a[i].c * a[i].w >= w) {
    //         for (int j = a[i].w; j <= w; ++j) {
    //             dpdc[j] =
    //                 max(dpdc[j], dpdc[j - a[i].w] +
    //                 a[i].v);
    //         }
    //         continue;
    //     }
    //     // end
    //     while (a[i].c--)
    //         for (int j = w; j >= a[i].w; --j) {
    //             dpdc[j] =
    //                 max(dpdc[j], dpdc[j - a[i].w] +
    //                 a[i].v);
    //         }
    // }

    // 法二：二进制优化
    for (int i = 1; i <= n; ++i) {
        // 小剪枝：如果足够大，可以直接当成完全背包
        // begin
        if (a[i].c * a[i].w >= w) {
            for (int j = a[i].w; j <= w; ++j) {
                dpdc[j] = max(dpdc[j], dpdc[j - a[i].w] + a[i].v);
            }
            continue;
        }
        // end

        // 二进制优化
        int leiji = 0;
        for (int k = 1; leiji + k <= a[i].c; leiji += k, k <<= 1) {
            for (int j = w; j >= a[i].w * k; --j) {
                dpdc[j] = max(dpdc[j], dpdc[j - a[i].w * k] + a[i].v * k);
            };
        }
        int r = a[i].c - leiji;
        if (r) {
            for (int j = w; j >= a[i].w * r; --j) {
                dpdc[j] = max(dpdc[j], dpdc[j - a[i].w * r] + a[i].v * r);
            }
        }
    }

    cout << dpdc[w];
}

/**
 * @brief 完全背包
 */

struct item {
    int w, v;
};
item a[N];

int dpwq[W];
void beibaowq() {
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].w >> a[i].v;
    }


    for (int i = 1; i <= n; ++i) {
        for (int j = a[i].w; j <= w; ++j) {
            dpwq[j] = max(dpwq[j], dpwq[j - a[i].w] + a[i].v);
        }
    }
    cout << dpwq[w];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
