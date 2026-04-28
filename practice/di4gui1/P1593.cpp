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
#define int long long
int MOD = 9901;
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

struct cao {
    int p, alpha;
};
vector<cao> z;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;

    if (b == 0) {
        cout << 1;
        return 0;
    }

    for (int j = 2; a != 1 && j * j <= a; ++j) {
        if (a != 1 && a % j == 0) {
            z.push_back({j, 0});
        }
        while (a != 1 && a % j == 0) {
            a /= j;
            z.back().alpha++;
        }
    }
    if (a > 1) {
        z.push_back({a, 1});
    }

    int ans = 1;
    for (auto [p, alpha] : z) {
        if (p % MOD != 1) {
            ans = ans * ((qpow(p % MOD, ((b) * (alpha) + 1)) + MOD - 1) % MOD) *
                  ((qpow((p - 1) % MOD, MOD - 2)) % MOD) % MOD;
        }
        else {
            ans = ans * ((b % MOD) * (alpha % MOD) + 1) % MOD;
        }
    }
    cout << ans;

    return 0;
}
