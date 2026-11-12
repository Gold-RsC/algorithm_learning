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

/**
 * @brief ST算法
 * @details f[i][j]记录[i,i+2^j)内的最大值
 * @details 先进行O(nlogn)的预处理，之后可以进行O(1)的在线回答
 */
const int N    = 1e5 + 5;
const int LOGN = 20;

int LOG2[N];
int n;
int a[N];
int f[N][LOGN];
void prework() {
    LOG2[2] = 1;
    for (int i = 3; i < N; ++i) {
        LOG2[i] = LOG2[i / 2] + 1;
    }

    for (int i = 1; i <= n; ++i) {
        f[i][0] = a[i];
    }
    for (int j = 1; j < LOGN; ++j) {
        for (int i = 1; i + (1 << j) < n; ++i) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int query(int l, int r) {
    int k = LOG2[r - l + 1];
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
