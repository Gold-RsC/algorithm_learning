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

void solve() {
    int n;
    cin >> n;

    int min_ = LLONG_MAX, max_ = 0;

    for (int i = 1; i <= n; ++i) {
        int a;

        cin >> a;

        min_ = min(min_, a);
        max_ = max(max_, a);
    }
    int ans = 0;
    for (int i = 31; i >= 0; --i) {
        int a = min_ & (1ull << i);
        int b = max_ & (1ull << i);
        if (a ^ b) {
            if (b) {
                swap(a, b);
            }
            ans += a | (a - 1);
            break;
        }
        else if (a & b) {
            ans |= a;
            min_ &= ~a;
            min_ &= ~a;
        }
    }
    cout << ans << '\n';
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
