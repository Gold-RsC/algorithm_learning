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
