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
 * @brief 费马小定理
 * @note
 *   1. p是素数，a^p=a(mod p)
 *   2. p是素数，p不整除a，a^{p-1}=1(mod p)
 */
/**
 * @brief 欧拉函数phi(n)
 * @note
 *   1. 小于等于n且与n互素的数的个数
 *   2. 若gcd(a,b)=1，则phi(ab)=phi(a)phi(b)
 *     - n = sum_{d|n} phi(d)
 *   3. 若p为质数，则phi(p^k)=p^k-p^(k-1)
 *     - n = n * mul (1-1/p_i)，p_i为n的质因数
 */
// 单点求解：在质因数分解的同时求即可
int euler_phi(int n) {
    int ans = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        ans = ans / n * (n - 1);
    }
    return ans;
}
// 批量预处理：线性筛
int u[N];            // 记录最小的质因子
vector<int> primes;  // 质数列表
int phi[N];
void euler_phi_pre(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (u[i] == 0) {
            u[i] = i;
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for (auto x : primes) {
            if (x > n / i) {
                break;
            }
            u[i * x] = x;
            if (i % x == 0) {
                phi[i * x] = phi[i] * x;
                break;
            }
            phi[i * x] = phi[i] * phi[x];
        }
    }
}

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
// 扩展欧几里得算法，适用于所有逆元存在O(log min{a,MOD})
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

/**
 * @brief 中国剩余定理
 * @note
 *   方程组:
 *     x = a[i] (mod r[i]) i=1,2,...,k
 *     其中，r[i]两两互质
 *   过程:
 *     1. n = mul r[i]
 *     2. m[i] = n / r[i]
 *        inv_m[i] = ... (mod r[i])
 *        c[i] = m[i] * inv_m[i]
 *     3. x = sum a[i]*c[i] (mod n)
 */
void ex_gcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1;
        y = 0;
        return;
    }
    ex_gcd(b, a % b, y, x);
    y -= a / b * x;
}
int inverse(int a, int MOD) {
    int x, y;
    ex_gcd(a, MOD, x, y);
    return (x % MOD + MOD) % MOD;
}
int CRT(int k, int a[N], int r[N]) {
    int n   = 1;
    int ans = 0;
    for (int i = 1; i <= k; ++i) {
        n *= r[i];
    }
    for (int i = 1; i <= k; ++i) {
        int m     = n / r[i];
        int inv_m = inverse(m, r[i]);
        ans       = (ans + a[i] * m * inv_m % n) % n;
    }
    return (ans % n + n) % n;
}

/**
 * @brief 裴蜀定理
 * @note
 *   1. 定理: 若a,b不全为0，则
 *     ax+by=k有正整数解，当且仅当且gcd(a,b)|k
 *   2. ax+by=1有正整数解，当且仅当且a,b互素
 */

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
