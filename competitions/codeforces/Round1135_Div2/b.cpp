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
#include <limits>
#include <iterator>
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int one = 0;
    for (int i = 0; i < n; ++i) {
        one += (s[i] == '1');
    }
    if (one > n / 2) {
        one = min(one + k, n);
    }
    else {
        one = max(one - k, 0ll);
    }
    cout << 1 + (n + one * one + (n - one) * (n - one)) / 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
