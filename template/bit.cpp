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
 * @brief qpow
 */
int qpow(int a, int b, int MOD) {
    int ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
/**
 * @brief mul
 *
 */

int64_t mul(int64_t a, int64_t b, int64_t MOD) {
    a %= MOD;
    b %= MOD;

    // 法一: O(logb)的算法
    // int ret = 0;
    // while (b) {
    //     if (b & 1) {
    //         ret = (ret + a) % MOD;
    //     }
    //     a = (a << 1) % MOD;
    //     b >>= 1;
    // }
    // return ret;

    // 法二: O(1)的算法
    return (__int128)a * b % MOD;

    // 法三: O(1)的算法
    // 原理: ret=a*b-floor_int(a*b/p)*p
    // int64_t c   = (long double)a * b / p;
    // int64_t ans = a * b - c * p;
    // if (ans < 0)
    //     ans += p;
    // else if (ans >= p)
    //     ans -= p;
    // return ans;
}
/**
 * n为偶数时，n xor 1 == n+1
 * n为奇数时，n xor 1 == n-1
 * (0,1),(2,3),(4,5),...构成变换
 */
/**
 * @brief lowbit
 */
int lowbit(int x) {
    return x & (-x);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
