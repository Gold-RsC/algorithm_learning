#include <iostream>
#include <iomanip>
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
#include <climits>
using namespace std;
const int MOD  = 1e9 + 7;
const int maxN = 1e6 + 10;
int a[maxN];
int f(int n) {
    if (n == 1) {
        return 0;
    }
    if (n < maxN) {
        if (a[n]) {
            return a[n];
        }
        return a[n] = (f(n >> 1) +
                       (((n + 1) % 4 > 1) ? -1 : 1)) %
                      MOD;
    }
    return (f(n >> 1) + (((n + 1) % 4 > 1) ? -1 : 1)) % MOD;
}
int s(int n) {
    if (n == 1) {
        return 0;
    }
    return (abs(f(n)) + s(n - 1)) % MOD;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << s(n) << endl;
    }
    return 0;
}

// ai解答
#include <bits/stdc++.h>
using namespace std;

const int MOD      = 1e9 + 7;
const int MAX_BITS = 61;  // 2^60 有61位
const int OFFSET   = 61;  // 用于将和映射到非负索引
const int SIZE     = 2 * OFFSET + 1;  // 123

// G[rem][p][idx] 表示剩余 rem 位，当前状态 p (p=0:
// prev_c=-1, p=1: prev_c=1)， 当前累积和为 s (idx = s +
// OFFSET) 时，后续所有情况绝对值的和
int G[MAX_BITS + 1][2][SIZE];

// H[rem] 表示尚未开始，剩余 rem 位时，所有情况的绝对值和
int H[MAX_BITS + 1];

void precompute() {
    // 基础情况 rem = 0
    for (int p = 0; p < 2; p++) {
        for (int idx = 0; idx < SIZE; idx++) {
            int s        = idx - OFFSET;
            G[0][p][idx] = abs(s) % MOD;
        }
    }

    // 递推计算 G
    for (int rem = 1; rem <= MAX_BITS; rem++) {
        for (int p_idx = 0; p_idx < 2; p_idx++) {
            int p_val = (p_idx == 0) ? -1 : 1;
            for (int idx = 0; idx < SIZE; idx++) {
                int s = idx - OFFSET;
                // 下一位选 0 -> c = 1
                int new_s0 = s + p_val * 1;
                int new_p0 = 1;  // c=1 对应 p=1
                // 下一位选 1 -> c = -1
                int new_s1 = s + p_val * (-1);
                int new_p1 = 0;  // c=-1 对应 p=0

                long long val =
                    G[rem - 1][new_p0][new_s0 + OFFSET] +
                    G[rem - 1][new_p1][new_s1 + OFFSET];
                G[rem][p_idx][idx] = val % MOD;
            }
        }
    }

    // 计算 H[rem]: 未开始时剩余 rem 位的绝对值和
    H[0] = 0;
    for (int rem = 1; rem <= MAX_BITS; rem++) {
        // 选0 -> 继续未开始，贡献 H[rem-1]
        // 选1 -> 开始，状态 p=-1, s=0，剩余 rem-1 位
        H[rem] = (H[rem - 1] + G[rem - 1][0][OFFSET]) % MOD;
    }
}

int solve_one(long long n) {
    if (n == 0)
        return 0;

    int L         = 0;
    long long tmp = n;
    while (tmp) {
        L++;
        tmp >>= 1;
    }

    long long ans = 0;
    bool started  = false;
    int prev_c    = 0;  // 仅当 started 为 true 时有效
    int cur_sum   = 0;

    // 从高位到低位处理
    for (int i = L - 1; i >= 0; i--) {
        int bit = (n >> i) & 1;
        int rem = i;  // 当前位之后还有 i 位

        if (bit == 1) {
            // 分支：当前位选择 0（小于当前位）
            if (started) {
                int new_prev_c = 1;  // c=1
                int new_sum    = cur_sum + prev_c * 1;
                ans = (ans + G[rem][1][new_sum + OFFSET]) %
                      MOD;
            }
            else {
                ans = (ans + H[rem]) % MOD;
            }

            // 沿着实际路径（选择 1）更新状态
            if (started) {
                cur_sum = cur_sum + prev_c * (-1);
                prev_c  = -1;
            }
            else {
                started = true;
                prev_c  = -1;
                cur_sum = 0;
            }
        }
        else {  // bit == 0
            // 没有小于的分支，直接更新状态
            if (started) {
                cur_sum = cur_sum + prev_c * 1;
                prev_c  = 1;
            }
            // 未开始时，选0仍为未开始，状态不变
        }
    }

    // 加上 n 本身的绝对值
    if (started) {
        ans = (ans + abs(cur_sum)) % MOD;
    }

    return (int)ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        cout << solve_one(n) << "\n";
    }

    return 0;
}
