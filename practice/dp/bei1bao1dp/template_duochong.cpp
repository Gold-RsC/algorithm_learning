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


const int N = 500 + 5;
const int W = 1000 + 5;
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
                dpdc[j] =
                    max(dpdc[j], dpdc[j - a[i].w] + a[i].v);
            }
            continue;
        }
        // end

        // 二进制优化
        int leiji = 0;
        for (int k = 1; leiji + k <= a[i].c;
             leiji += k, k <<= 1) {
            for (int j = w; j >= a[i].w * k; --j) {
                dpdc[j] =
                    max(dpdc[j],
                        dpdc[j - a[i].w * k] + a[i].v * k);
            };
        }
        int r = a[i].c - leiji;
        if (r) {
            for (int j = w; j >= a[i].w * r; --j) {
                dpdc[j] =
                    max(dpdc[j],
                        dpdc[j - a[i].w * r] + a[i].v * r);
            }
        }
    }

    cout << dpdc[w];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    beibaodc();
    return 0;
}
