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
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long
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
 * @brief 费马小定理
 * @note
 *   1. p是素数，a^p=a(mod p)
 *   2. p是素数，p不整除a，a^{p-1}=1(mod p)
 */
/**
 * @brief 欧拉定理
 * @note
 *   1. a^phi(m)=1(mod m)
 *   2. m为素数p时，phi(p)=p-1
 *   3. 扩展欧拉定理(mod m下)
 *      a^k=
 *          a^(k mod phi(m))         ,gcd(a,m)=1
 *          a^k                      ,gcd(a,m)!=1,k<phi(m)
 *          a^(k mod phi(m) + phi(m)),gcd(a,m)!=1,k>=phi(m)
 *   4. a^k(mod m)随着k增大会出现纯循环和混循环
 */
/**
 * @brief 模逆元
 */
/**
 * @brief 单个模逆元
 */
// 扩展欧几里得算法，适用于所有逆元存在O(log? min{a,MOD})
void ex_gcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1;
        y = 0;
        return;
    }
    ex_gcd(b, a % b, y, x);
    y -= a / b * x;
}
int inverse1(int a, int MOD) {
    int x, y;
    ex_gcd(a, MOD, x, y);
    return (x % MOD + MOD) % MOD;
}
// 快速幂算法，适用于MOD是素数的情况，O(log MOD)
int inverse2(int a, int MOD) {
    return qpow(a, MOD - 2, MOD);
}

/**
 * @brief 多个模逆元
 * @details 模的逆元就是逆元的乘积，需要预先处理乘积
 */
int a[N];
int S[N];
int ans[N];
void solve() {
    S[0] = 1;
    for (int i = 1; i <= n; ++i) {
        S[i] = S[i - 1] * a[i] % MOD;
    }
    int S_inv = inverse(S[n], MOD);
    for (int i = n; i >= 1; --i) {
        ans[i] = S_inv * S[i - 1] % MOD;
        S_inv  = S_inv * a[i] % MOD;
    }
}
/**
 * @brief 阶乘取模
 * @note
 *   1. Wilson定理：p是素数等价于(m-1)! mod m=-1
 *      即(m!)_m=-1(mod m)
 *   2. 令P=\Pi_{k=1...m,(k,m)=1}=-1(mod m)
 *      上式取-1当且仅当m存的原根存在
 *      原根存在：
 *      m=2,4,p^a,2p^a(p为奇素数，a为正整数)
 *   3. 对于素数p和正整数n，(mod p下)
 *      (n!)_p=(-1)^floor(n/p)
 *            *(n mod p)!
 *            *(floor(n/p)!)_p
 *      递归深度为O(lnn/lnp)，复杂度O(p lnn/lnp)
 *      若p很小可以直接对小于p的n预处理出来(O(p))
 *      则总复杂度O(p+lnn/lnp)
 */
int f[N];
void init(int p) {
    f[0] = 1;
    for (int i = 1; i < p; ++i) {
        f[i] = f[i - 1] * i % p;
    }
}
int fastmod(int n, int p) {  //(n!)_p mod p
    int res = 1;
    while (n > 1) {
        if ((n / p) & 1) {
            res = p - res;
        }
        res = res * f[n % p] % p;
        n /= p;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
