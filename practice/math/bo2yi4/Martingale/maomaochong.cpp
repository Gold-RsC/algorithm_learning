/*
题目背景
猫猫虫 为了对抗 saki，找来了一些帮手，猫猫虫
想先通过比武来决出最强的一位，以确保面对 saki
时有更大的胜算。猫猫虫
想知道每个帮手胜出的可能性，但是还要去负责组织比武，就把这个任务交给你了。

题目描述
猫猫虫 有
$n$ 个帮手，每个帮手有个初始积分
$a_i$
，现在进行若干轮比武，每轮比武选择两个未被淘汰的帮手，获胜的帮手积分
$+1$，落败的帮手积分
$-1$，如果一个帮手积分变成了
$0$
则自动淘汰。比武会一直进行，直到最后只剩下一个帮手。已知参加每轮比武的帮手由
猫猫虫 随机抽选，而每轮比武时双方胜出的概率都为
$50\%$，你要告诉 猫猫虫 最后每个帮手胜出的概率。

由于输出文件过大而导致无法
AC，现在改变输出方式：输入时再给定一个正整数 $k$，输出
$\sum_{i=1}^{n} k^i \times p(i)$，其中
$p(i)$ 是选手
$i$ 的获胜概率。结果对 998244353 取模。

输入格式
第一行 2 个正整数
$n$，
$k$，表示帮手个数与给定正整数。
第二行有
$n$ 个正整数
$a_i$ ，表示每个帮手的初始积分。

输出格式
一行 1 个整数，表示
$\sum_{i=1}^{n} k^i \times p(i)$对 998244353 取模后的结果。

输入输出样例 #1
输入 #1
3 75
1 1 1
输出 #1
142525
说明/提示
对于 100%的数据，
$1 \leq n \leq 10^7$ ，
$a_i \geq 1$，
$1 \leq \sum a_i \leq 998244352$，
$1\leq k \leq 998244352$。

为了防止输入过大带来的常数问题，C++
选手请尽量使用关闭流同步的 std::cin 和 std::cout
实现输入输出，否则可能出现因读入输出问题导致的 TLE 等。

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  // your code

  return 0;
}
 */
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
#include <climits>
using namespace std;
#define int __int128
__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x  = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
istream& operator>>(istream& is, __int128& a) {
    __int128 x = 0, f = 1;
    char ch;
    is.get(ch);
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        is.get(ch);
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        is.get(ch);
    }
    a = x * f;
    return is;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        print(x / 10);
    }
    putchar(x % 10 + '0');
}
ostream& operator<<(ostream& os, __int128 x) {
    if (x < 0) {
        os << '-';
        x = -x;
    }
    if (x > 9) {
        os << __int128(x / 10);
    }
    os << char(x % 10 + '0');
    return os;
}
__int128 abs(__int128 x) {
    return x < 0 ? -x : x;
}
const int MOD = 998244353llu;
int qpow(int a, int b) {
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

int n, k;


const int N = 1e7 + 10;
int a[N];

int k_i = 1;
int sum_a;
int ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum_a = (sum_a + a[i]) % MOD;
    }
    for (int i = 1; i <= n; ++i) {
        k_i = k * k_i % MOD;
        ans = (ans + (k_i * a[i]) % MOD) % MOD;
    }
    ans = ans * qpow(sum_a, MOD - 2) % MOD;
    cout << ans;


    return 0;
}
