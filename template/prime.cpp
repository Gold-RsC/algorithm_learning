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

//////////////////////////////////////////////
// 质数的判定
//////////////////////////////////////////////
/**
 * @brief 试除法
 */
bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


//////////////////////////////////////////////
// 质数的筛法
//////////////////////////////////////////////
/**
 * @brief 埃式筛
 * @details O(n loglogn)
 */
const int N = 10000;
bitset<N> v;
vector<int> primes;
void get_primes_1(int n) {
    v.reset();

    for (int i = 2; i <= n; ++i) {
        if (v[i]) {
            continue;
        }
        primes.push_back(i);
        for (int j = i * i; j <= n; j += i) {
            v[j] = true;
        }
    }
}

/**
 * @brief 线性筛
 * @details O(n)
 */
int u[N];            // 记录最小的质因子
vector<int> primes;  // 质数列表
void get_primes_2(int n) {
    memset(u, 0, sizeof(u));
    for (int i = 2; i <= n; ++i) {
        if (u[i] == 0) {
            u[i] = i;
            primes.push_back(i);
        }
        for (auto x : primes) {
            if (x > u[i] || x > n / i) {
                break;
            }
            u[i * x] = x;
        }
    }
}

//////////////////////////////////////////////
// 质因数分解
//////////////////////////////////////////////
struct Prime {
    int p, c;
};
vector<Prime> p;
void divide(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            p.push_back({i, cnt});
        }
    }
    if (n > 1) {
        p.push_back({n, 1});
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
