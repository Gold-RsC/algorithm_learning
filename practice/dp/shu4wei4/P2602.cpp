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

const int N = 1e5 + 5;

int dp[N], pow10[N];
int ans1[N], ans2[N];
int a[N];

void solve(int n, int* ans) {
    int tmp = n;
    int len = 0;
    while (n) {
        a[++len] = n % 10;
        n /= 10;
    }
    for (int i = len; i >= 1; --i) {
        for (int j = 0; j < 10; j++) {
            ans[j] += dp[i - 1] * a[i];
        }
        for (int j = 0; j < a[i]; j++) {
            ans[j] += pow10[i - 1];
        }
        tmp -= pow10[i - 1] * a[i];
        ans[a[i]] += tmp + 1;
        ans[0] -= pow10[i - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> l >> r;

    pow10[0] = 1;
    for (int i = 1; i <= 13; ++i) {
        dp[i]    = dp[i - 1] * 10 + pow10[i - 1];
        pow10[i] = 10 * pow10[i - 1];
    }
    solve(r, ans1);
    solve(l - 1, ans2);
    for (int i = 0; i < 10; ++i) {
        printf("%lld ", ans1[i] - ans2[i]);
    }
    return 0;
}
