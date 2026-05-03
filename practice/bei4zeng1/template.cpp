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

/**
 * @brief 倍增分段模板
 */
bool check(int l, int r) {
    return true;
}
void beizeng(vector<int> a) {
    int n = a.size();

    for (int l = 0, r = 0; l < n;) {
        int p = 1;

        while (p) {
            // 左闭右开
            if (r + p <= n && check(l, r + p)) {
                r += p;
                p <<= 1;
            }
            else {
                p >>= 1;
            }
        }

        (l, r);
        l = r;
    }
}

/**
 * @brief ST算法
 * @details f[i][j]记录[i,i+2^j)内的最大值
 * @details 先进行O(nlogn)的预处理，之后可以进行O(1)的在线回答
 */
const int N    = 1e5 + 5;
const int LOGN = 20;
int n;
int a[N];
int f[N][LOGN];
void st_prework() {
    for (int i = 1; i <= n; ++i) {
        f[i][0] = a[i];
    }
    int t = log2(n) + 1;
    for (int j = 1; j < t; ++j) {
        for (int i = 1; i < n - (1 << j); ++i) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int st_query(int l, int r) {
    int k = log2(r - l + 1);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
