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
 * @brief 判断与检测
 * @note
 *   x |= (1u << i)       : 第i位置1
 *   x &= ~(1u << i)      : 第i位置0
 *   x ^= (1u << i)       : 第i位取反
 *   (x >>i) & 1          : 取第i位
 *   lowbit(x) = x & (-x) : 取最低位的1
 *   x |= (x + 1)         : 把最低位0置1
 *   x &= (x - 1)         : 把最低为1置0
 */

/**
 * @brief 集合操作
 * @note
 *   A | B    : 并
 *   A & B    : 交
 *   A & (~B) : 差
 */
/**
 * @brief 枚举mask的所有子集
 */
void fun() {
    for (int s = mask;; s = (s - 1) & mask) {

        // do something

        if (!s) {  // 0也是子集
            break;
        }
    }
}
/**
 * @brief 枚举mask的所有超集
 */
void fun() {
    for (int s = mask; s < (1 << n); s = (s + 1) | mask) {
        // do something
    }
}

/**
 * @brief builtin系列
 * @note
 *   __builtin_clz(x)      : x二进制前导0个数，x=0时为未定义
 *   __builtin_ctz(x)      : x二进制末尾连续0的个数，x=0时未定义
 *   __builtin_ffs(x)      : x二进制末尾最后一个1的位置，编号从1开始，x=0时为0
 *   __builtin_popcount(x) : x二进制中1的个数
 */

/**
 * @brief 格雷码
 */
int g(int n) {
    return n ^ (n >> 1);
}
int rev_g(int g) {
    int n = 0;
    for (; g; g >>= 1) {
        n ^= g;
    }
    return n;
}
